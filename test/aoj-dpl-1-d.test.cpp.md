---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: math/lis.hpp
    title: math/lis.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
  bundledCode: "#line 1 \"test/aoj-dpl-1-d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <iostream>\n#include <math/lis.hpp>\n#include <vector>\n\nint main()\
    \ {\n\tint n;\n\tstd::cin >> n;\n\tstd::vector a(n, 0);\n\tfor(auto &v : a) std::cin\
    \ >> v;\n\tstd::cout << longest_increasing_subsequence(a) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <iostream>\n#include <math/lis.hpp>\n#include <vector>\n\nint main()\
    \ {\n\tint n;\n\tstd::cin >> n;\n\tstd::vector a(n, 0);\n\tfor(auto &v : a) std::cin\
    \ >> v;\n\tstd::cout << longest_increasing_subsequence(a) << '\\n';\n}"
  dependsOn:
  - math/lis.hpp
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  isVerificationFile: true
  path: test/aoj-dpl-1-d.test.cpp
  requiredBy: []
  timestamp: '2021-10-26 10:11:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-dpl-1-d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-dpl-1-d.test.cpp
- /verify/test/aoj-dpl-1-d.test.cpp.html
title: test/aoj-dpl-1-d.test.cpp
---
