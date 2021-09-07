---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_dynamic_connectivity.hpp
    title: data_structure/offline_dynamic_connectivity.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-2235.test.cpp
    title: test/aoj-2235.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/undo_uf.hpp\"\n#include <stack>\n#include\
    \ <vector>\n\nstruct rollback_unionfind {\nprivate:\n\tstd::vector<int> par;\n\
    \tstd::stack<std::pair<int, int>> history;\n\npublic:\n\trollback_unionfind()\
    \ = default;\n\n\trollback_unionfind(size_t n) : par(n, -1) {}\n\n\tint root(int\
    \ x) {\n\t\tif(par[x] < 0) return x;\n\t\treturn root(par[x]);\n\t}\n\n\tbool\
    \ same(int x, int y) { return root(x) == root(y); }\n\n\tbool unite(int x, int\
    \ y) {\n\t\tx = root(x), y = root(y);\n\t\thistory.emplace(x, par[x]);\n\t\thistory.emplace(y,\
    \ par[y]);\n\t\tif(x == y) return false;\n\t\tif(par[x] > par[y]) std::swap(x,\
    \ y);\n\t\tpar[x] += par[y];\n\t\tpar[y] = x;\n\t\treturn true;\n\t}\n\n\tvoid\
    \ snapshot() {\n\t\twhile(!history.empty()) history.pop();\n\t}\n\n\tvoid undo()\
    \ {\n\t\tfor(int i = 0; i < 2; i++) {\n\t\t\tpar[history.top().first] = history.top().second;\n\
    \t\t\thistory.pop();\n\t\t}\n\t}\n\n\tvoid rollback() {\n\t\twhile(!history.empty())\
    \ undo();\n\t}\n\n\tsize_t size(int x) { return -par[root(x)]; }\n};\n"
  code: "#pragma once\n#include <stack>\n#include <vector>\n\nstruct rollback_unionfind\
    \ {\nprivate:\n\tstd::vector<int> par;\n\tstd::stack<std::pair<int, int>> history;\n\
    \npublic:\n\trollback_unionfind() = default;\n\n\trollback_unionfind(size_t n)\
    \ : par(n, -1) {}\n\n\tint root(int x) {\n\t\tif(par[x] < 0) return x;\n\t\treturn\
    \ root(par[x]);\n\t}\n\n\tbool same(int x, int y) { return root(x) == root(y);\
    \ }\n\n\tbool unite(int x, int y) {\n\t\tx = root(x), y = root(y);\n\t\thistory.emplace(x,\
    \ par[x]);\n\t\thistory.emplace(y, par[y]);\n\t\tif(x == y) return false;\n\t\t\
    if(par[x] > par[y]) std::swap(x, y);\n\t\tpar[x] += par[y];\n\t\tpar[y] = x;\n\
    \t\treturn true;\n\t}\n\n\tvoid snapshot() {\n\t\twhile(!history.empty()) history.pop();\n\
    \t}\n\n\tvoid undo() {\n\t\tfor(int i = 0; i < 2; i++) {\n\t\t\tpar[history.top().first]\
    \ = history.top().second;\n\t\t\thistory.pop();\n\t\t}\n\t}\n\n\tvoid rollback()\
    \ {\n\t\twhile(!history.empty()) undo();\n\t}\n\n\tsize_t size(int x) { return\
    \ -par[root(x)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/undo_uf.hpp
  requiredBy:
  - data_structure/offline_dynamic_connectivity.hpp
  timestamp: '2021-09-07 20:08:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-2235.test.cpp
documentation_of: data_structure/undo_uf.hpp
layout: document
redirect_from:
- /library/data_structure/undo_uf.hpp
- /library/data_structure/undo_uf.hpp.html
title: data_structure/undo_uf.hpp
---
