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
  bundledCode: "#line 1 \"math/inversion.hpp\"\n#include <vector>\n\n//\u914D\u5217\
    \u306E\u8EE2\u5012\u6570(i < j and a[i] > a[j]\u3092\u6E80\u305F\u3059\u7D44\u306E\
    \u500B\u6570)\u3092\u8FD4\u3059\n//\u914D\u5217\u304C\u975E\u8CA0\u304B\u3064\
    Max\u304C1e5\u307E\u3067\u7A0B\u5EA6\u306B\u5BFE\u5FDC\ntemplate <class T>\nlong\
    \ long inversion(std::vector<T> vec) {\n\tlong long res = 0;\n\tint n = *max_element(vec.begin(),\
    \ vec.end()) + 1;\n\tstd::vector<T> d(n + 1, 0);\n\tfor(int i = 0; i < vec.size();\
    \ i++) {\n\t\tres += i;\n\t\tfor(int j = vec[i] + 1; j; j -= j & -j) res -= d[j];\n\
    \t\tfor(int j = vec[i] + 1; j <= n; j += j & -j) d[j] += 1;\n\t}\n\treturn res;\n\
    }\n"
  code: "#include <vector>\n\n//\u914D\u5217\u306E\u8EE2\u5012\u6570(i < j and a[i]\
    \ > a[j]\u3092\u6E80\u305F\u3059\u7D44\u306E\u500B\u6570)\u3092\u8FD4\u3059\n\
    //\u914D\u5217\u304C\u975E\u8CA0\u304B\u3064Max\u304C1e5\u307E\u3067\u7A0B\u5EA6\
    \u306B\u5BFE\u5FDC\ntemplate <class T>\nlong long inversion(std::vector<T> vec)\
    \ {\n\tlong long res = 0;\n\tint n = *max_element(vec.begin(), vec.end()) + 1;\n\
    \tstd::vector<T> d(n + 1, 0);\n\tfor(int i = 0; i < vec.size(); i++) {\n\t\tres\
    \ += i;\n\t\tfor(int j = vec[i] + 1; j; j -= j & -j) res -= d[j];\n\t\tfor(int\
    \ j = vec[i] + 1; j <= n; j += j & -j) d[j] += 1;\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/inversion.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/inversion.hpp
layout: document
redirect_from:
- /library/math/inversion.hpp
- /library/math/inversion.hpp.html
title: math/inversion.hpp
---
