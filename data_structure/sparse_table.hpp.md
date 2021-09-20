---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-staticrmq.test.cpp
    title: test/yosupo-staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sparse_table.hpp\"\n#include <cassert>\n\
    #include <vector>\n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\nint\
    \ ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int bsf_constexpr(unsigned int n)\
    \ {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\n//\
    \ @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 << x))\
    \ != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 5\
    \ \"data_structure/sparse_table.hpp\"\n\ntemplate <class S, S (*op)(S, S)>\nstruct\
    \ sparse_table {\npublic:\n\tsparse_table() = default;\n\texplicit sparse_table(const\
    \ std::vector<S>& v) : _n(int(v.size())), lt(int(v.size()) + 1) {\n\t\tlog = atcoder::internal::ceil_pow2(_n);\n\
    \t\td.assign(log + 1, std::vector<S>(_n));\n\t\tfor(int i = 0; i <= log; i++)\
    \ {\n\t\t\tfor(int j = 0; j <= _n - (1 << i); j++) {\n\t\t\t\tif(i)\n\t\t\t\t\t\
    d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << i - 1)]);\n\t\t\t\telse\n\t\t\t\t\
    \td[i][j] = v[j];\n\t\t\t}\n\t\t}\n\t\tfor(int i = 2; i <= _n; i++)\n\t\t\tlt[i]\
    \ = lt[i >> 1] + 1;\n\t}\n\n\tS prod(int l, int r) const {\n\t\tassert(0 <= l\
    \ && l <= r && r <= _n);\n\t\tint len = r - l;\n\t\treturn op(d[lt[len]][l], d[lt[len]][r\
    \ - (1 << lt[len])]);\n\t}\n\n\tS all_prod() const { return prod(0, _n); }\n\n\
    private:\n\tint _n, size, log;\n\tstd::vector<std::vector<S>> d;\n\tstd::vector<int>\
    \ lt;\n};\n"
  code: "#include <cassert>\n#include <vector>\n\n#include \"atcoder/internal_bit\"\
    \n\ntemplate <class S, S (*op)(S, S)>\nstruct sparse_table {\npublic:\n\tsparse_table()\
    \ = default;\n\texplicit sparse_table(const std::vector<S>& v) : _n(int(v.size())),\
    \ lt(int(v.size()) + 1) {\n\t\tlog = atcoder::internal::ceil_pow2(_n);\n\t\td.assign(log\
    \ + 1, std::vector<S>(_n));\n\t\tfor(int i = 0; i <= log; i++) {\n\t\t\tfor(int\
    \ j = 0; j <= _n - (1 << i); j++) {\n\t\t\t\tif(i)\n\t\t\t\t\td[i][j] = op(d[i\
    \ - 1][j], d[i - 1][j + (1 << i - 1)]);\n\t\t\t\telse\n\t\t\t\t\td[i][j] = v[j];\n\
    \t\t\t}\n\t\t}\n\t\tfor(int i = 2; i <= _n; i++)\n\t\t\tlt[i] = lt[i >> 1] + 1;\n\
    \t}\n\n\tS prod(int l, int r) const {\n\t\tassert(0 <= l && l <= r && r <= _n);\n\
    \t\tint len = r - l;\n\t\treturn op(d[lt[len]][l], d[lt[len]][r - (1 << lt[len])]);\n\
    \t}\n\n\tS all_prod() const { return prod(0, _n); }\n\nprivate:\n\tint _n, size,\
    \ log;\n\tstd::vector<std::vector<S>> d;\n\tstd::vector<int> lt;\n};\n"
  dependsOn:
  - atcoder/internal_bit.hpp
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2021-09-20 12:04:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-staticrmq.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_table.hpp
- /library/data_structure/sparse_table.hpp.html
title: data_structure/sparse_table.hpp
---
