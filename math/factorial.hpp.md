---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':question:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':question:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: math/formal_power_series.hpp
    title: math/formal_power_series.hpp
  - icon: ':warning:'
    path: math/multipoint_evaluation.hpp
    title: math/multipoint_evaluation.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-division_of_polynomials.test.cpp
    title: test/yosupo-division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-exp_of_formal_power_series.test.cpp
    title: test/yosupo-exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-inv_of_formal_power_series.test.cpp
    title: test/yosupo-inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-log_of_formal_power_series.test.cpp
    title: test/yosupo-log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-pow_of_formal_power_series.test.cpp
    title: test/yosupo-pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-sqrt_of_formal_power_series.test.cpp
    title: test/yosupo-sqrt_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo-stirling_number_of_the_first_kind.test.cpp
    title: test/yosupo-stirling_number_of_the_first_kind.test.cpp
  - icon: ':x:'
    path: test/yosupo-stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo-stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/factorial.hpp\"\n#include <atcoder/modint>\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <class T>\nstruct factorial {\npublic:\n\
    \tstatic int MAX;\n\tstatic std::vector<T> fac, finv, inv;\n\n\tfactorial() {}\n\
    \n\tT binom(int n, int r) {\n\t\tif(n < r or n < 0 or r < 0) return T(0);\n\t\t\
    assert(n < MAX);\n\t\treturn fac[n] * finv[r] * finv[n - r];\n\t}\n\n\tT large_binom(int\
    \ n, int r) {\n\t\tif(n < r or n < 0 or r < 0) return T(0);\n\t\tassert(r < MAX);\n\
    \t\tT ret = finv[r];\n\t\tfor(int i = 1; i <= r; ++i)\n\t\t\tret *= (n + 1 - i);\n\
    \t\treturn ret;\n\t}\n\n\tstatic void set_size(int n) {\n\t\tassert(n >= 1);\n\
    \t\tMAX = n + 1;\n\t\tfac.resize(MAX);\n\t\tfinv.resize(MAX);\n\t\tinv.resize(MAX);\n\
    \t\tconst int MOD = T::mod();\n\t\tfac[0] = fac[1] = 1;\n\t\tfinv[0] = finv[1]\
    \ = 1;\n\t\tinv[1] = 1;\n\t\tfor(int i = 2; i < MAX; i++) {\n\t\t\tfac[i] = fac[i\
    \ - 1] * i;\n\t\t\tinv[i] = (T)MOD - inv[MOD % i] * (MOD / i);\n\t\t\tfinv[i]\
    \ = finv[i - 1] * inv[i];\n\t\t}\n\t}\n};\ntemplate <class T>\nint factorial<T>::MAX\
    \ = 0;\ntemplate <class T>\nstd::vector<T> factorial<T>::fac;\ntemplate <class\
    \ T>\nstd::vector<T> factorial<T>::finv;\ntemplate <class T>\nstd::vector<T> factorial<T>::inv;\n"
  code: "#include <atcoder/modint>\n#include <cassert>\n#include <vector>\n\ntemplate\
    \ <class T>\nstruct factorial {\npublic:\n\tstatic int MAX;\n\tstatic std::vector<T>\
    \ fac, finv, inv;\n\n\tfactorial() {}\n\n\tT binom(int n, int r) {\n\t\tif(n <\
    \ r or n < 0 or r < 0) return T(0);\n\t\tassert(n < MAX);\n\t\treturn fac[n] *\
    \ finv[r] * finv[n - r];\n\t}\n\n\tT large_binom(int n, int r) {\n\t\tif(n < r\
    \ or n < 0 or r < 0) return T(0);\n\t\tassert(r < MAX);\n\t\tT ret = finv[r];\n\
    \t\tfor(int i = 1; i <= r; ++i)\n\t\t\tret *= (n + 1 - i);\n\t\treturn ret;\n\t\
    }\n\n\tstatic void set_size(int n) {\n\t\tassert(n >= 1);\n\t\tMAX = n + 1;\n\t\
    \tfac.resize(MAX);\n\t\tfinv.resize(MAX);\n\t\tinv.resize(MAX);\n\t\tconst int\
    \ MOD = T::mod();\n\t\tfac[0] = fac[1] = 1;\n\t\tfinv[0] = finv[1] = 1;\n\t\t\
    inv[1] = 1;\n\t\tfor(int i = 2; i < MAX; i++) {\n\t\t\tfac[i] = fac[i - 1] * i;\n\
    \t\t\tinv[i] = (T)MOD - inv[MOD % i] * (MOD / i);\n\t\t\tfinv[i] = finv[i - 1]\
    \ * inv[i];\n\t\t}\n\t}\n};\ntemplate <class T>\nint factorial<T>::MAX = 0;\n\
    template <class T>\nstd::vector<T> factorial<T>::fac;\ntemplate <class T>\nstd::vector<T>\
    \ factorial<T>::finv;\ntemplate <class T>\nstd::vector<T> factorial<T>::inv;\n"
  dependsOn:
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  isVerificationFile: false
  path: math/factorial.hpp
  requiredBy:
  - math/formal_power_series.hpp
  - math/multipoint_evaluation.hpp
  timestamp: '2021-09-08 16:43:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-stirling_number_of_the_second_kind.test.cpp
  - test/yosupo-division_of_polynomials.test.cpp
  - test/yosupo-inv_of_formal_power_series.test.cpp
  - test/yosupo-log_of_formal_power_series.test.cpp
  - test/yosupo-pow_of_formal_power_series.test.cpp
  - test/yosupo-sqrt_of_formal_power_series.test.cpp
  - test/yosupo-stirling_number_of_the_first_kind.test.cpp
  - test/yosupo-exp_of_formal_power_series.test.cpp
documentation_of: math/factorial.hpp
layout: document
redirect_from:
- /library/math/factorial.hpp
- /library/math/factorial.hpp.html
title: math/factorial.hpp
---
