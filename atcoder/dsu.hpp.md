---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: multi.hpp
    title: multi.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-2235.test.cpp
    title: test/aoj-2235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-2600.test.cpp
    title: test/aoj-2600.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-2703.test.cpp
    title: test/aoj-2703.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-alds1_5_d.test.cpp
    title: test/aoj-alds1_5_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dsl-2-b.test.cpp
    title: test/aoj-dsl-2-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-a.test.cpp
    title: test/aoj-grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-b.test.cpp
    title: test/aoj-grl-1-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-c.test.cpp
    title: test/aoj-grl-1-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-2-a.test.cpp
    title: test/aoj-grl-2-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-3-a.test.cpp
    title: test/aoj-grl-3-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-3-b.test.cpp
    title: test/aoj-grl-3-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-3-c.test.cpp
    title: test/aoj-grl-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-4-a.test.cpp
    title: test/aoj-grl-4-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-4-b.test.cpp
    title: test/aoj-grl-4-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-a.test.cpp
    title: test/aoj-grl-5-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-b.test.cpp
    title: test/aoj-grl-5-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-c.test.cpp
    title: test/aoj-grl-5-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-d.test.cpp
    title: test/aoj-grl-5-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-e.test.cpp
    title: test/aoj-grl-5-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-factorize.test.cpp
    title: test/yosupo-factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-lca.test.cpp
    title: test/yosupo-lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-line_add_get_min.test.cpp
    title: test/yosupo-line_add_get_min.test.cpp
  - icon: ':x:'
    path: test/yosupo-predecessor_problem.test.cpp
    title: test/yosupo-predecessor_problem.test.cpp
  - icon: ':x:'
    path: test/yosupo-predecessor_problem2.test.cpp
    title: test/yosupo-predecessor_problem2.test.cpp
  - icon: ':x:'
    path: test/yosupo-scc.test.cpp
    title: test/yosupo-scc.test.cpp
  - icon: ':x:'
    path: test/yosupo-segment_add_get_min.test.cpp
    title: test/yosupo-segment_add_get_min.test.cpp
  - icon: ':x:'
    path: test/yosupo-set_xor_min.test.cpp
    title: test/yosupo-set_xor_min.test.cpp
  - icon: ':x:'
    path: test/yosupo-tree_diameter.test.cpp
    title: test/yosupo-tree_diameter.test.cpp
  - icon: ':x:'
    path: test/yosupo-two_edge_connected_components.test.cpp
    title: test/yosupo-two_edge_connected_components.test.cpp
  - icon: ':x:'
    path: test/yosupo-vertex_add_path_sum.test.cpp
    title: test/yosupo-vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo-vertex_add_subtree_sum.test.cpp
    title: test/yosupo-vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/dsu.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace atcoder {\n\n// Implement (union by\
    \ size) + (path compression)\n// Reference:\n// Zvi Galil and Giuseppe F. Italiano,\n\
    // Data structures and algorithms for disjoint set union problems\nstruct dsu\
    \ {\n  public:\n    dsu() : _n(0) {}\n    explicit dsu(int n) : _n(n), parent_or_size(n,\
    \ -1) {}\n\n    int merge(int a, int b) {\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        int x = leader(a), y = leader(b);\n\
    \        if (x == y) return x;\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        return x;\n    }\n\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a)\
    \ == leader(b);\n    }\n\n    int leader(int a) {\n        assert(0 <= a && a\
    \ < _n);\n        if (parent_or_size[a] < 0) return a;\n        return parent_or_size[a]\
    \ = leader(parent_or_size[a]);\n    }\n\n    int size(int a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n\n}  // namespace atcoder\n\
    \n\n"
  code: "#ifndef ATCODER_DSU_HPP\n#define ATCODER_DSU_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\n// Implement (union\
    \ by size) + (path compression)\n// Reference:\n// Zvi Galil and Giuseppe F. Italiano,\n\
    // Data structures and algorithms for disjoint set union problems\nstruct dsu\
    \ {\n  public:\n    dsu() : _n(0) {}\n    explicit dsu(int n) : _n(n), parent_or_size(n,\
    \ -1) {}\n\n    int merge(int a, int b) {\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        int x = leader(a), y = leader(b);\n\
    \        if (x == y) return x;\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        return x;\n    }\n\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a)\
    \ == leader(b);\n    }\n\n    int leader(int a) {\n        assert(0 <= a && a\
    \ < _n);\n        if (parent_or_size[a] < 0) return a;\n        return parent_or_size[a]\
    \ = leader(parent_or_size[a]);\n    }\n\n    int size(int a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n\n}  // namespace atcoder\n\
    \n#endif  // ATCODER_DSU_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/dsu.hpp
  requiredBy:
  - template.hpp
  - multi.hpp
  timestamp: '2021-09-08 15:21:46+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-vertex_add_subtree_sum.test.cpp
  - test/yosupo-segment_add_get_min.test.cpp
  - test/yosupo-scc.test.cpp
  - test/aoj-grl-2-a.test.cpp
  - test/aoj-2235.test.cpp
  - test/aoj-dsl-2-b.test.cpp
  - test/yosupo-vertex_add_path_sum.test.cpp
  - test/aoj-grl-3-a.test.cpp
  - test/yosupo-predecessor_problem2.test.cpp
  - test/yosupo-set_xor_min.test.cpp
  - test/aoj-grl-1-b.test.cpp
  - test/aoj-grl-4-b.test.cpp
  - test/aoj-grl-5-e.test.cpp
  - test/aoj-grl-5-c.test.cpp
  - test/aoj-alds1_5_d.test.cpp
  - test/aoj-2703.test.cpp
  - test/aoj-grl-5-d.test.cpp
  - test/aoj-grl-4-a.test.cpp
  - test/aoj-grl-3-b.test.cpp
  - test/aoj-grl-1-a.test.cpp
  - test/aoj-grl-1-c.test.cpp
  - test/yosupo-lca.test.cpp
  - test/yosupo-tree_diameter.test.cpp
  - test/yosupo-line_add_get_min.test.cpp
  - test/yosupo-predecessor_problem.test.cpp
  - test/aoj-grl-5-b.test.cpp
  - test/aoj-2600.test.cpp
  - test/yosupo-factorize.test.cpp
  - test/aoj-grl-3-c.test.cpp
  - test/yosupo-two_edge_connected_components.test.cpp
  - test/aoj-grl-5-a.test.cpp
documentation_of: atcoder/dsu.hpp
layout: document
redirect_from:
- /library/atcoder/dsu.hpp
- /library/atcoder/dsu.hpp.html
title: atcoder/dsu.hpp
---
