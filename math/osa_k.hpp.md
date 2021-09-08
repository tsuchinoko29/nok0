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
  bundledCode: "#line 1 \"math/osa_k.hpp\"\n#include <vector>\n\nstruct osa_k {\n\
    private:\n\tstd::vector<int> spf, pr;\n\npublic:\n\tosa_k() = default;\n\n\tosa_k(int\
    \ MAX) : spf(MAX + 1) {\n\t\tfor(int i = 2; i <= MAX; i++) {\n\t\t\tif(spf[i]\
    \ == 0) {\n\t\t\t\tspf[i] = i;\n\t\t\t\tpr.push_back(i);\n\t\t\t}\n\t\t\tfor(int\
    \ j = 0; j < pr.size() and pr[j] <= spf[i] and i * pr[j] <= MAX; j++)\n\t\t\t\t\
    spf[i * pr[j]] = pr[j];\n\t\t}\n\t}\n\n\tstd::vector<std::pair<int, int>> PF(int\
    \ n) {\n\t\tstd::vector<std::pair<int, int>> divisor;\n\t\tif(n == 1) return divisor;\n\
    \t\tint before = spf[n], cnt = 0;\n\t\twhile(n > 1) {\n\t\t\tif(spf[n] == before)\
    \ {\n\t\t\t\tcnt++;\n\t\t\t\tn /= spf[n];\n\t\t\t} else {\n\t\t\t\tdivisor.emplace_back(before,\
    \ cnt);\n\t\t\t\tbefore = spf[n];\n\t\t\t\tcnt = 1;\n\t\t\t\tn /= spf[n];\n\t\t\
    \t}\n\t\t}\n\t\tdivisor.emplace_back(before, cnt);\n\t\treturn divisor;\n\t}\n\
    \n\tint smallestprimefactor(const int n) const {\n\t\treturn spf[n];\n\t}\n\n\t\
    bool isPrime(const int n) const {\n\t\treturn n == spf[n];\n\t}\n};\n"
  code: "#include <vector>\n\nstruct osa_k {\nprivate:\n\tstd::vector<int> spf, pr;\n\
    \npublic:\n\tosa_k() = default;\n\n\tosa_k(int MAX) : spf(MAX + 1) {\n\t\tfor(int\
    \ i = 2; i <= MAX; i++) {\n\t\t\tif(spf[i] == 0) {\n\t\t\t\tspf[i] = i;\n\t\t\t\
    \tpr.push_back(i);\n\t\t\t}\n\t\t\tfor(int j = 0; j < pr.size() and pr[j] <= spf[i]\
    \ and i * pr[j] <= MAX; j++)\n\t\t\t\tspf[i * pr[j]] = pr[j];\n\t\t}\n\t}\n\n\t\
    std::vector<std::pair<int, int>> PF(int n) {\n\t\tstd::vector<std::pair<int, int>>\
    \ divisor;\n\t\tif(n == 1) return divisor;\n\t\tint before = spf[n], cnt = 0;\n\
    \t\twhile(n > 1) {\n\t\t\tif(spf[n] == before) {\n\t\t\t\tcnt++;\n\t\t\t\tn /=\
    \ spf[n];\n\t\t\t} else {\n\t\t\t\tdivisor.emplace_back(before, cnt);\n\t\t\t\t\
    before = spf[n];\n\t\t\t\tcnt = 1;\n\t\t\t\tn /= spf[n];\n\t\t\t}\n\t\t}\n\t\t\
    divisor.emplace_back(before, cnt);\n\t\treturn divisor;\n\t}\n\n\tint smallestprimefactor(const\
    \ int n) const {\n\t\treturn spf[n];\n\t}\n\n\tbool isPrime(const int n) const\
    \ {\n\t\treturn n == spf[n];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/osa_k.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/osa_k.hpp
layout: document
redirect_from:
- /library/math/osa_k.hpp
- /library/math/osa_k.hpp.html
title: math/osa_k.hpp
---
