import dataclasses
import logging
import os
import re
import shutil
import tempfile
import urllib.request
import zipfile
from typing import Any, Optional

from bs4 import BeautifulSoup, Tag

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

header_dir = 'adl_headers'

# these are structs of unknown structure that are used in the API
@dataclasses.dataclass
class Struct:
    name: str
    is_ptr: bool = False

unknown_structs = [
    Struct("ADL_DL_DISPLAYMODEINFO"),
    Struct("ADL_DL_DISPLAY_MODE"),
    Struct("ADLVulkanAppInfo"),
    Struct("BINFILE"),
    Struct("BOOL"),
    Struct("CUSTOMISATIONS"),
    Struct("DATATYPES"),
    Struct("LPXScreenInfo", True),
    Struct("PRIVACYTYPES"),
]


def _get_sdk() -> str:
    out_dir = tempfile.mkdtemp()
    logger.info("Retrieving SDK and unpacking to %s", out_dir)
    with tempfile.NamedTemporaryFile(prefix="16.0-", suffix=".zip") as f:
        f.close()
        urllib.request.urlretrieve(
            'https://github.com/GPUOpen-LibrariesAndSDKs/display-library/archive/refs/tags/16.0.zip',
            f.name,
        )
        with zipfile.ZipFile(f.name, 'r') as zf:
            zf.extractall(out_dir)
    return os.path.join(out_dir, "display-library-16.0")


@dataclasses.dataclass
class _File:
    doc_file: str
    out_file: str


@dataclasses.dataclass
class _FunctionDoc:
    doc_file: str
    anchor: str
    out_file: str


@dataclasses.dataclass
class _Param:
    typ: str
    name: str


@dataclasses.dataclass
class _Proto:
    return_type: str
    name: str
    params: list[_Param]

    def pretty(self) -> str:
        base = f"{self.return_type} {self.name} ( "
        indent_len = len(base)

        out = base
        if self.params:
            max_type_len = max(len(x.typ) for x in self.params)
            for i, param in enumerate(self.params):
                if i > 0:
                    out += " " * indent_len
                out += f"{param.typ:{max_type_len}} {param.name}"
                if i < len(self.params) - 1:
                    out += ","
                out += "\n"
            out += " " * (indent_len - 2) + ");"
        else:
            out += ");"
        return out


@dataclasses.dataclass
class _DocParam:
    dir: str
    name: str
    desc: str


@dataclasses.dataclass
class _Doc:
    desc: Optional[str]
    user: Optional[str]
    params: Optional[list[_DocParam]]
    returns: Optional[str]
    remark: Optional[str]
    deprecated: Optional[str]

    def pretty(self) -> str:
        out = ""

        if self.desc:
            out += self.desc.replace("\n", "\n\n")
            out += "\n"

        if self.user:
            out += "Supported Platforms:\n"
            out += f"  {self.user}\n"
            out += "\n"

        if self.params:
            out += "Parameters\n"
            max_dir_len = max(len(x.dir) for x in self.params)
            max_name_len = max(len(x.name) for x in self.params)
            for param in self.params:
                out += f"  {param.dir:{max_dir_len}} {param.name:{max_name_len}} {param.desc}\n"
            out += "\n"

        if self.returns:
            out += "Returns\n"
            out += f"  {self.returns}\n"
            out += "\n"

        if self.remark:
            out += "Remarks\n"
            out += f"  {self.remark}"
            out += "\n"

        if self.deprecated:
            out += "Deprecated:\n"
            out += f"  {self.deprecated}"
            out += "\n"

        return "/// " + "\n/// ".join(out.strip().split("\n"))


@dataclasses.dataclass
class _Function:
    proto: _Proto
    doc: _Doc

    def pretty(self) -> str:
        return self.doc.pretty() + "\n" + self.proto.pretty()


_soup_cache: dict[str, Any] = {}


def _gen_function_headers(sdk_dir: str) -> None:
    doc_root = os.path.join(sdk_dir, "Public-Documents", "html")
    func_header_dir = os.path.join(header_dir, "functions")
    pregen = set(os.listdir(os.path.join(sdk_dir, "include")))

    logger.info("Generating headers from documentation")
    logger.info("    Doc dir: %s", doc_root)
    logger.info("    Out dir: %s", func_header_dir)

    def list_files(sdk_dir: str) -> list[_File]:
        with open(os.path.join(doc_root, "files.html"), "r", encoding="utf-8") as f:
            soup = BeautifulSoup(f, "html.parser")
        directory = soup.find("table", class_="directory")
        files = directory.find_all("a", class_="el")
        return [_File(x['href'], x.text) for x in files if x.text not in pregen]

    def list_functions(file: _File) -> list[_FunctionDoc]:
        with open(os.path.join(doc_root, file.doc_file), "r", encoding="utf-8") as f:
            soup = BeautifulSoup(f, "html.parser")
        memberdecls_list = soup.find_all("table", class_="memberdecls")
        memberdecls = [x for x in memberdecls_list if len(x.find_all("a", attrs={"name": "func-members"})) > 0][0]
        funcs = memberdecls.find_all("tr", class_=re.compile(r"memitem:.*"))
        out = []
        for func in funcs:
            func_a = func.find("td", class_="memItemRight").find_all("a")[0]
            page, anchor = func_a["href"].split("#")
            out.append(_FunctionDoc(page, anchor, file.out_file))
        return out

    def gen_function(function_doc: _FunctionDoc) -> _Function:
        def gen_proto(proto_div: Tag) -> _Proto:
            return_type, func_name = proto_div.find("td", class_="memname").text.strip().split(" ")
            params = []
            for row in proto_div.find_all("tr")[:-1]:
                param_type = row.find("td", class_="paramtype").text.strip()
                param_name = row.find("td", class_="paramname").find("em").text
                params.append(_Param(param_type, param_name))
            return _Proto(return_type, func_name, params)

        def gen_doc_param(param_div: Tag) -> _DocParam:
            dir = param_div.find("td", class_="paramdir").text.strip()
            name = param_div.find("td", class_="paramname").text.strip()
            desc = param_div.find_all("td")[-1].get_text()
            return _DocParam(dir, name, desc)

        def gen_doc(doc_div: Tag) -> _Doc:
            desc = "\n".join([x.text for x in doc_div.find_all("p")])
            if not desc:
                desc = None

            user = None
            if user_dl := doc_div.find("dl", class_="user"):
                user = user_dl.find("dd").text

            params = None
            if param_div := doc_div.find("dl", class_="params"):
                params = [gen_doc_param(x) for x in param_div.find_all("tr")]

            returns = None
            if returns_div := doc_div.find("dl", class_="return"):
                returns = returns_div.find("dd").text

            remark = None
            if remark_dl := doc_div.find("dl", class_="remark"):
                remark = remark_dl.find("dd").text

            deprecated = None
            if deprecated_dl := doc_div.find("dl", class_="deprecated"):
                deprecated = deprecated_dl.find("dd").text

            return _Doc(desc, user, params, returns, remark, deprecated)

        doc_file_path = os.path.join(doc_root, function_doc.doc_file)
        if doc_file_path not in _soup_cache:
            with open(doc_file_path, "r", encoding="utf-8", errors="ignore") as f:
                _soup_cache[doc_file_path] = BeautifulSoup(f, "html.parser")
        soup = _soup_cache[doc_file_path]
        anchor = soup.find("a", id=function_doc.anchor)
        doc_div = anchor.find_next_sibling("div")

        proto_div = doc_div.find("div", class_="memproto")
        proto = gen_proto(proto_div)

        doc_div = doc_div.find("div", class_="memdoc")
        doc = gen_doc(doc_div)

        return _Function(proto, doc)

    files = list_files(sdk_dir)
    os.mkdir(func_header_dir)
    for file in files:
        logger.info("Generating functions for output file %s", file.out_file)
        function_docs = list_functions(file)
        logger.info("    Found %d functions", len(function_docs))
        functions = [gen_function(x) for x in function_docs]
        with open(os.path.join(func_header_dir, file.out_file), "w", encoding="utf-8") as f:
            symbol = f"ADL_HEADER_{file.out_file.split('.')[0].upper()}_H_"
            f.write(f"#ifndef {symbol}\n")
            f.write(f"#define {symbol}\n")
            f.write("\n")
            f.write("#include <errno.h>\n")
            f.write('#include "../adl_defines.h"\n')
            f.write('#include "../adl_sdk.h"\n')
            f.write('#include "../adl_structures.h"\n')
            f.write("\n")
            f.write("// HACK: we don't have docs for all structs used in the API, so make unknown ones void for now\n")
            for struct in unknown_structs:
                f.write(f"#define {struct.name} void{' *' if struct.is_ptr else ''}\n")
            f.write("\n")
            for func in functions:
                f.write(func.pretty() + "\n\n\n")
            f.write(f"#endif /* {symbol} */\n")

    with open(os.path.join(header_dir, "functions.h"), "w", encoding="utf-8") as f:
        symbol = f"ADL_HEADER_H_"
        f.write(f"#ifndef {symbol}\n")
        f.write(f"#define {symbol}\n")
        f.write("\n")
        f.write('#include "adl_defines.h"\n')
        f.write('#include "adl_sdk.h"\n')
        f.write('#include "adl_structures.h"\n')
        f.write("\n")
        for file in files:
            f.write(f'#include "functions/{file.out_file}"\n')
        f.write("\n")
        f.write(f"#endif /* {symbol} */\n")


def main() -> None:
    shutil.rmtree(header_dir)

    sdk_dir = _get_sdk()

    logger.info("Copying pre-built headers")
    shutil.copytree(os.path.join(sdk_dir, "include"), header_dir)

    _gen_function_headers(sdk_dir)


if __name__ == '__main__':
    main()
