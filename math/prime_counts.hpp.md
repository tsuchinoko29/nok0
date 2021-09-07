---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/prime_counts.hpp\"\n#include <cmath>\n#include <vector>\n\
    \nlong long prime_pi(const long long n) {\n\tif(n <= 2) return n == 2;\n\tconst\
    \ int v = floor(std::sqrt((long double)n));\n\tint s = v + 1 >> 1;\n\tstd::vector<int>\
    \ smalls(s), roughs(s);\n\tstd::vector<long long> larges(s);\n\tfor(int i = 1;\
    \ i < s; ++i) smalls[i] = i;\n\tfor(int i = 0; i < s; ++i) roughs[i] = 2 * i +\
    \ 1;\n\tfor(int i = 0; i < s; ++i) larges[i] = (n / (2 * i + 1) - 1) / 2;\n}\n"
  code: "#include <cmath>\n#include <vector>\n\nlong long prime_pi(const long long\
    \ n) {\n\tif(n <= 2) return n == 2;\n\tconst int v = floor(std::sqrt((long double)n));\n\
    \tint s = v + 1 >> 1;\n\tstd::vector<int> smalls(s), roughs(s);\n\tstd::vector<long\
    \ long> larges(s);\n\tfor(int i = 1; i < s; ++i) smalls[i] = i;\n\tfor(int i =\
    \ 0; i < s; ++i) roughs[i] = 2 * i + 1;\n\tfor(int i = 0; i < s; ++i) larges[i]\
    \ = (n / (2 * i + 1) - 1) / 2;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_counts.hpp
  requiredBy: []
  timestamp: '2021-09-07 20:08:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_counts.hpp
layout: document
redirect_from:
- /library/math/prime_counts.hpp
- /library/math/prime_counts.hpp.html
title: math/prime_counts.hpp
---
