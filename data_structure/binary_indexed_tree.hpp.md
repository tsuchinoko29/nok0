---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-dsl-2-b.test.cpp
    title: test/aoj-dsl-2-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-d.test.cpp
    title: test/aoj-grl-5-d.test.cpp
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
  bundledCode: "#line 1 \"data_structure/binary_indexed_tree.hpp\"\n#include <vector>\n\
    \ntemplate <typename T>\nstruct binary_indexed_tree {\nprivate:\n\tint n, p;\n\
    \tstd::vector<T> d;\n\npublic:\n\tbinary_indexed_tree() = default;\n\n\tbinary_indexed_tree(int\
    \ n) : n(n), d(n + 1) {\n\t\tp = 1;\n\t\twhile(p < n) p *= 2;\n\t}\n\n\tvoid add(int\
    \ i, T x = 1) {\n\t\tfor(i++; i <= n; i += i & -i) d[i] += x;\n\t}\n\n\t//return\
    \ sum[0,i)\n\tT sum(int i) {\n\t\tT res = 0;\n\t\tfor(; i; i -= i & -i) res +=\
    \ d[i];\n\t\treturn res;\n\t}\n\n\t//return sum[l,r)\n\tT sum(int l, int r) {\
    \ return sum(r) - sum(l); }\n\n\t//return min(x) which satisfies (v0 + v1 + ...\
    \ + vx >= w)\n\tint lower_bound(T w) {\n\t\tif(w <= 0) return 0;\n\t\tT x = 0;\n\
    \t\tfor(int i = p; i; i /= 2) {\n\t\t\tif(i + x <= n && d[i + x] < w) {\n\t\t\t\
    \tw -= d[i + x];\n\t\t\t\tx += i;\n\t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n};\n"
  code: "#include <vector>\n\ntemplate <typename T>\nstruct binary_indexed_tree {\n\
    private:\n\tint n, p;\n\tstd::vector<T> d;\n\npublic:\n\tbinary_indexed_tree()\
    \ = default;\n\n\tbinary_indexed_tree(int n) : n(n), d(n + 1) {\n\t\tp = 1;\n\t\
    \twhile(p < n) p *= 2;\n\t}\n\n\tvoid add(int i, T x = 1) {\n\t\tfor(i++; i <=\
    \ n; i += i & -i) d[i] += x;\n\t}\n\n\t//return sum[0,i)\n\tT sum(int i) {\n\t\
    \tT res = 0;\n\t\tfor(; i; i -= i & -i) res += d[i];\n\t\treturn res;\n\t}\n\n\
    \t//return sum[l,r)\n\tT sum(int l, int r) { return sum(r) - sum(l); }\n\n\t//return\
    \ min(x) which satisfies (v0 + v1 + ... + vx >= w)\n\tint lower_bound(T w) {\n\
    \t\tif(w <= 0) return 0;\n\t\tT x = 0;\n\t\tfor(int i = p; i; i /= 2) {\n\t\t\t\
    if(i + x <= n && d[i + x] < w) {\n\t\t\t\tw -= d[i + x];\n\t\t\t\tx += i;\n\t\t\
    \t}\n\t\t}\n\t\treturn x;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2021-09-07 20:47:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-dsl-2-b.test.cpp
  - test/aoj-grl-5-d.test.cpp
  - test/yosupo-vertex_add_path_sum.test.cpp
  - test/yosupo-vertex_add_subtree_sum.test.cpp
documentation_of: data_structure/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/data_structure/binary_indexed_tree.hpp
- /library/data_structure/binary_indexed_tree.hpp.html
title: data_structure/binary_indexed_tree.hpp
---
