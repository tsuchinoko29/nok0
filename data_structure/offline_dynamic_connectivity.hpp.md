---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data_structure/undo_uf.hpp
    title: data_structure/undo_uf.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/offline_dynamic_connectivity.hpp\"\n#include\
    \ <algorithm>\n#include <map>\n\n#line 2 \"data_structure/undo_uf.hpp\"\n#include\
    \ <stack>\n#include <vector>\n\nstruct rollback_unionfind {\nprivate:\n\tstd::vector<int>\
    \ par;\n\tstd::stack<std::pair<int, int>> history;\n\npublic:\n\trollback_unionfind()\
    \ = default;\n\n\trollback_unionfind(size_t n) : par(n, -1) {}\n\n\tint root(int\
    \ x) {\n\t\tif(par[x] < 0) return x;\n\t\treturn root(par[x]);\n\t}\n\n\tbool\
    \ same(int x, int y) { return root(x) == root(y); }\n\n\tbool unite(int x, int\
    \ y) {\n\t\tx = root(x), y = root(y);\n\t\thistory.emplace(x, par[x]);\n\t\thistory.emplace(y,\
    \ par[y]);\n\t\tif(x == y) return false;\n\t\tif(par[x] > par[y]) std::swap(x,\
    \ y);\n\t\tpar[x] += par[y];\n\t\tpar[y] = x;\n\t\treturn true;\n\t}\n\n\tvoid\
    \ snapshot() {\n\t\twhile(!history.empty()) history.pop();\n\t}\n\n\tvoid undo()\
    \ {\n\t\tfor(int i = 0; i < 2; i++) {\n\t\t\tpar[history.top().first] = history.top().second;\n\
    \t\t\thistory.pop();\n\t\t}\n\t}\n\n\tvoid rollback() {\n\t\twhile(!history.empty())\
    \ undo();\n\t}\n\n\tsize_t size(int x) { return -par[root(x)]; }\n};\n#line 6\
    \ \"data_structure/offline_dynamic_connectivity.hpp\"\nstruct offline_dynamic_connectivity\
    \ {\npublic:\n\trollback_unionfind uf;\n\n\toffline_dynamic_connectivity(int n,\
    \ int q) : uf(n), seg(q), q(q) {}\n\n\tvoid link(int t, int u, int v) {\n\t\t\
    std::pair e = std::minmax(u, v);\n\t\tif(!cnt[e]++) appear[e] = t;\n\t}\n\n\t\
    void cut(int t, int u, int v) {\n\t\tstd::pair e = std::minmax(u, v);\n\t\tif(!(--cnt[e]))\
    \ seg.set(appear[e], t, e);\n\t}\n\n\tvoid build() {\n\t\tfor(const auto &[e,\
    \ val] : cnt)\n\t\t\tif(val) seg.set(appear[e], q, e);\n\t}\n\n\ttemplate <class\
    \ F>\n\tvoid run(const F &f, int k = 1) {\n\t\tfor(const auto &[u, v] : seg.node[k])\n\
    \t\t\tuf.unite(u, v);\n\t\tif(k < q)\n\t\t\trun(f, k << 1), run(f, k << 1 | 1);\n\
    \t\telse\n\t\t\tf(k - q);\n\t\tfor(int i = 0; i < (int)seg.node[k].size(); i++)\n\
    \t\t\tuf.undo();\n\t}\n\nprivate:\n\tint q;\n\tusing edge = std::pair<int, int>;\n\
    \tstd::map<edge, int> appear, cnt;\n\tstd::vector<std::pair<std::pair<int, int>,\
    \ edge>> pend;\n\n\tstruct seg {\n\tpublic:\n\t\tint n;\n\t\tstd::vector<std::vector<edge>>\
    \ node;\n\t\tseg(int n_) : n(n_), node(n << 1) {}\n\n\t\tvoid set(int l, int r,\
    \ edge e) {\n\t\t\tfor(l += n, r += n; l < r; l >>= 1, r >>= 1) {\n\t\t\t\tif(l\
    \ & 1) node[l++].push_back(e);\n\t\t\t\tif(r & 1) node[--r].push_back(e);\n\t\t\
    \t}\n\t\t}\n\t};\n\n\tseg seg;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <map>\n\n#include \"data_structure/undo_uf.hpp\"\
    \nstruct offline_dynamic_connectivity {\npublic:\n\trollback_unionfind uf;\n\n\
    \toffline_dynamic_connectivity(int n, int q) : uf(n), seg(q), q(q) {}\n\n\tvoid\
    \ link(int t, int u, int v) {\n\t\tstd::pair e = std::minmax(u, v);\n\t\tif(!cnt[e]++)\
    \ appear[e] = t;\n\t}\n\n\tvoid cut(int t, int u, int v) {\n\t\tstd::pair e =\
    \ std::minmax(u, v);\n\t\tif(!(--cnt[e])) seg.set(appear[e], t, e);\n\t}\n\n\t\
    void build() {\n\t\tfor(const auto &[e, val] : cnt)\n\t\t\tif(val) seg.set(appear[e],\
    \ q, e);\n\t}\n\n\ttemplate <class F>\n\tvoid run(const F &f, int k = 1) {\n\t\
    \tfor(const auto &[u, v] : seg.node[k])\n\t\t\tuf.unite(u, v);\n\t\tif(k < q)\n\
    \t\t\trun(f, k << 1), run(f, k << 1 | 1);\n\t\telse\n\t\t\tf(k - q);\n\t\tfor(int\
    \ i = 0; i < (int)seg.node[k].size(); i++)\n\t\t\tuf.undo();\n\t}\n\nprivate:\n\
    \tint q;\n\tusing edge = std::pair<int, int>;\n\tstd::map<edge, int> appear, cnt;\n\
    \tstd::vector<std::pair<std::pair<int, int>, edge>> pend;\n\n\tstruct seg {\n\t\
    public:\n\t\tint n;\n\t\tstd::vector<std::vector<edge>> node;\n\t\tseg(int n_)\
    \ : n(n_), node(n << 1) {}\n\n\t\tvoid set(int l, int r, edge e) {\n\t\t\tfor(l\
    \ += n, r += n; l < r; l >>= 1, r >>= 1) {\n\t\t\t\tif(l & 1) node[l++].push_back(e);\n\
    \t\t\t\tif(r & 1) node[--r].push_back(e);\n\t\t\t}\n\t\t}\n\t};\n\n\tseg seg;\n\
    };\n"
  dependsOn:
  - data_structure/undo_uf.hpp
  isVerificationFile: false
  path: data_structure/offline_dynamic_connectivity.hpp
  requiredBy: []
  timestamp: '2021-09-07 20:08:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/offline_dynamic_connectivity.hpp
layout: document
redirect_from:
- /library/data_structure/offline_dynamic_connectivity.hpp
- /library/data_structure/offline_dynamic_connectivity.hpp.html
title: data_structure/offline_dynamic_connectivity.hpp
---
