---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-e.test.cpp
    title: test/aoj-grl-5-e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/rangeadd_rangesum_bit.hpp\"\n#include <vector>\n\
    \ntemplate <class T>\nstruct rangeadd_rangesum_bit {\nprivate:\n\tstd::vector<T>\
    \ vec1, vec2;\n\tsize_t n;\n\npublic:\n\trangeadd_rangesum_bit() = default;\n\t\
    rangeadd_rangesum_bit(size_t n_) : n(n_ + 1), vec1(n_ + 2, 0), vec2(n_ + 2, 0)\
    \ {}\n\n\t//add x for [l, r)\n\tvoid add(int l, int r, T x = T(1)) {\n\t\tl++;\n\
    \t\tr++;\n\t\tfor(int i = l; i <= n; i += i & -i) vec1[i] -= x * l;\n\t\tfor(int\
    \ i = l; i <= n; i += i & -i) vec2[i] += x;\n\t\tfor(int i = r; i <= n; i += i\
    \ & -i) vec1[i] += x * r;\n\t\tfor(int i = r; i <= n; i += i & -i) vec2[i] -=\
    \ x;\n\t}\n\n\t//return sum[0, r)\n\tT sum(int r) {\n\t\tr += 1;\n\t\tT ret =\
    \ 0;\n\t\tfor(int x = r; x > 0; x -= x & -x) ret += vec1[x];\n\t\tfor(int x =\
    \ r; x > 0; x -= x & -x) ret += vec2[x] * r;\n\t\treturn ret;\n\t}\n\n\t//return\
    \ sum[l, r)\n\tT sum(int l, int r) { return sum(r) - sum(l); }\n\n\tT operator[](int\
    \ x) { return sum(x, x + 1); }\n};\n"
  code: "#include <vector>\n\ntemplate <class T>\nstruct rangeadd_rangesum_bit {\n\
    private:\n\tstd::vector<T> vec1, vec2;\n\tsize_t n;\n\npublic:\n\trangeadd_rangesum_bit()\
    \ = default;\n\trangeadd_rangesum_bit(size_t n_) : n(n_ + 1), vec1(n_ + 2, 0),\
    \ vec2(n_ + 2, 0) {}\n\n\t//add x for [l, r)\n\tvoid add(int l, int r, T x = T(1))\
    \ {\n\t\tl++;\n\t\tr++;\n\t\tfor(int i = l; i <= n; i += i & -i) vec1[i] -= x\
    \ * l;\n\t\tfor(int i = l; i <= n; i += i & -i) vec2[i] += x;\n\t\tfor(int i =\
    \ r; i <= n; i += i & -i) vec1[i] += x * r;\n\t\tfor(int i = r; i <= n; i += i\
    \ & -i) vec2[i] -= x;\n\t}\n\n\t//return sum[0, r)\n\tT sum(int r) {\n\t\tr +=\
    \ 1;\n\t\tT ret = 0;\n\t\tfor(int x = r; x > 0; x -= x & -x) ret += vec1[x];\n\
    \t\tfor(int x = r; x > 0; x -= x & -x) ret += vec2[x] * r;\n\t\treturn ret;\n\t\
    }\n\n\t//return sum[l, r)\n\tT sum(int l, int r) { return sum(r) - sum(l); }\n\
    \n\tT operator[](int x) { return sum(x, x + 1); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/rangeadd_rangesum_bit.hpp
  requiredBy: []
  timestamp: '2021-10-30 20:59:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-grl-5-e.test.cpp
documentation_of: data_structure/rangeadd_rangesum_bit.hpp
layout: document
redirect_from:
- /library/data_structure/rangeadd_rangesum_bit.hpp
- /library/data_structure/rangeadd_rangesum_bit.hpp.html
title: data_structure/rangeadd_rangesum_bit.hpp
---
