---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/mincostflow.hpp
    title: atcoder/mincostflow.hpp
  - icon: ':warning:'
    path: graph/dag_mcf.hpp
    title: graph/dag_mcf.hpp
  - icon: ':heavy_check_mark:'
    path: multi.hpp
    title: multi.hpp
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: test/yosupo-predecessor_problem.test.cpp
    title: test/yosupo-predecessor_problem.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-predecessor_problem2.test.cpp
    title: test/yosupo-predecessor_problem2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-scc.test.cpp
    title: test/yosupo-scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-segment_add_get_min.test.cpp
    title: test/yosupo-segment_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-set_xor_min.test.cpp
    title: test/yosupo-set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-tree_diameter.test.cpp
    title: test/yosupo-tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-two_edge_connected_components.test.cpp
    title: test/yosupo-two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-vertex_add_path_sum.test.cpp
    title: test/yosupo-vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-vertex_add_subtree_sum.test.cpp
    title: test/yosupo-vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/internal_queue.hpp\"\n\n\n\n#include <vector>\n\n\
    namespace atcoder {\n\nnamespace internal {\n\ntemplate <class T> struct simple_queue\
    \ {\n    std::vector<T> payload;\n    int pos = 0;\n    void reserve(int n) {\
    \ payload.reserve(n); }\n    int size() const { return int(payload.size()) - pos;\
    \ }\n    bool empty() const { return pos == int(payload.size()); }\n    void push(const\
    \ T& t) { payload.push_back(t); }\n    T& front() { return payload[pos]; }\n \
    \   void clear() {\n        payload.clear();\n        pos = 0;\n    }\n    void\
    \ pop() { pos++; }\n};\n\n}  // namespace internal\n\n}  // namespace atcoder\n\
    \n\n"
  code: "#ifndef ATCODER_INTERNAL_QUEUE_HPP\n#define ATCODER_INTERNAL_QUEUE_HPP 1\n\
    \n#include <vector>\n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate\
    \ <class T> struct simple_queue {\n    std::vector<T> payload;\n    int pos =\
    \ 0;\n    void reserve(int n) { payload.reserve(n); }\n    int size() const {\
    \ return int(payload.size()) - pos; }\n    bool empty() const { return pos ==\
    \ int(payload.size()); }\n    void push(const T& t) { payload.push_back(t); }\n\
    \    T& front() { return payload[pos]; }\n    void clear() {\n        payload.clear();\n\
    \        pos = 0;\n    }\n    void pop() { pos++; }\n};\n\n}  // namespace internal\n\
    \n}  // namespace atcoder\n\n#endif  // ATCODER_INTERNAL_QUEUE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_queue.hpp
  requiredBy:
  - atcoder/maxflow.hpp
  - atcoder/mincostflow.hpp
  - graph/dag_mcf.hpp
  - multi.hpp
  - template.hpp
  timestamp: '2021-09-08 15:21:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-two_edge_connected_components.test.cpp
  - test/aoj-grl-3-b.test.cpp
  - test/yosupo-predecessor_problem.test.cpp
  - test/yosupo-segment_add_get_min.test.cpp
  - test/aoj-grl-4-b.test.cpp
  - test/yosupo-line_add_get_min.test.cpp
  - test/aoj-grl-4-a.test.cpp
  - test/yosupo-tree_diameter.test.cpp
  - test/aoj-grl-1-a.test.cpp
  - test/yosupo-lca.test.cpp
  - test/yosupo-predecessor_problem2.test.cpp
  - test/aoj-grl-3-c.test.cpp
  - test/aoj-grl-5-e.test.cpp
  - test/aoj-2703.test.cpp
  - test/aoj-grl-5-a.test.cpp
  - test/aoj-grl-5-c.test.cpp
  - test/yosupo-set_xor_min.test.cpp
  - test/aoj-grl-1-b.test.cpp
  - test/yosupo-vertex_add_path_sum.test.cpp
  - test/aoj-dsl-2-b.test.cpp
  - test/aoj-2235.test.cpp
  - test/aoj-grl-3-a.test.cpp
  - test/aoj-grl-1-c.test.cpp
  - test/aoj-alds1_5_d.test.cpp
  - test/aoj-grl-5-d.test.cpp
  - test/aoj-grl-5-b.test.cpp
  - test/yosupo-vertex_add_subtree_sum.test.cpp
  - test/aoj-2600.test.cpp
  - test/aoj-grl-2-a.test.cpp
  - test/yosupo-factorize.test.cpp
  - test/yosupo-scc.test.cpp
documentation_of: atcoder/internal_queue.hpp
layout: document
redirect_from:
- /library/atcoder/internal_queue.hpp
- /library/atcoder/internal_queue.hpp.html
title: atcoder/internal_queue.hpp
---
