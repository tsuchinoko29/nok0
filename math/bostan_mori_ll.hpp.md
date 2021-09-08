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
  bundledCode: "#line 1 \"math/bostan_mori_ll.hpp\"\n#include <atcoder/convolution>\n\
    #include <atcoder/modint>\n#include <cassert>\n#include <vector>\n\n//\u039F(N^2)\n\
    struct bostan_mori_ll {\npublic:\n\tbostan_mori_ll(const std::vector<long long>\
    \ &a) {\n\t\tauto pq1 = find_generating_function(std::vector<mint1>{a.begin(),\
    \ a.end()});\n\t\tp1 = std::move(pq1.first);\n\t\tq1 = std::move(pq1.second);\n\
    \t\tauto pq2 = find_generating_function(std::vector<mint2>{a.begin(), a.end()});\n\
    \t\tp2 = std::move(pq2.first);\n\t\tq2 = std::move(pq2.second);\n\t\td = q1.size();\n\
    \t\tassert(q1[0] == 1 and p1.size() + 1 <= q1.size());\n\t}\n\n\tlong long kth_term(long\
    \ long k) {\n\t\tlong long r1, r2;\n\t\t{\n\t\t\tlong long c = k;\n\t\t\tif(d\
    \ == 1)\n\t\t\t\treturn 0;\n\t\t\tauto p = p1, q = q1;\n\t\t\twhile(c) {\n\t\t\
    \t\tauto q_minus = q;\n\t\t\t\tfor(int i = 1; i < d; i += 2)\n\t\t\t\t\tq_minus[i]\
    \ *= -1;\n\t\t\t\tp = atcoder::convolution(p, q_minus);\n\t\t\t\tq = atcoder::convolution(q,\
    \ q_minus);\n\t\t\t\tfor(int i = 0; i < d - 1; i++)\n\t\t\t\t\tp[i] = p[(i <<\
    \ 1) | (c & 1)];\n\t\t\t\tfor(int i = 0; i < d; i++)\n\t\t\t\t\tq[i] = q[i <<\
    \ 1];\n\t\t\t\tp.resize(d - 1);\n\t\t\t\tq.resize(d);\n\t\t\t\tc >>= 1;\n\t\t\t\
    }\n\t\t\tr1 = p[0].val();\n\t\t}\n\t\t{\n\t\t\tlong long c = k;\n\t\t\tif(d ==\
    \ 1)\n\t\t\t\treturn 0;\n\t\t\tauto p = p2, q = q2;\n\t\t\twhile(c) {\n\t\t\t\t\
    auto q_minus = q;\n\t\t\t\tfor(int i = 1; i < d; i += 2)\n\t\t\t\t\tq_minus[i]\
    \ *= -1;\n\t\t\t\tp = atcoder::convolution(p, q_minus);\n\t\t\t\tq = atcoder::convolution(q,\
    \ q_minus);\n\t\t\t\tfor(int i = 0; i < d - 1; i++)\n\t\t\t\t\tp[i] = p[(i <<\
    \ 1) | (c & 1)];\n\t\t\t\tfor(int i = 0; i < d; i++)\n\t\t\t\t\tq[i] = q[i <<\
    \ 1];\n\t\t\t\tp.resize(d - 1);\n\t\t\t\tq.resize(d);\n\t\t\t\tc >>= 1;\n\t\t\t\
    }\n\t\t\tr2 = p[0].val();\n\t\t}\n\t\treturn garner(r1, r2);\n\t}\n\nprivate:\n\
    \tstatic constexpr int m1 = 998244353;\n\tstatic constexpr int m2 = 1004535809;\n\
    \tstatic constexpr int inv_m1_mod_m2 = 669690699;\n\tusing mint1 = atcoder::static_modint<m1>;\n\
    \tusing mint2 = atcoder::static_modint<m2>;\n\tint d;\n\tstd::vector<mint1> p1,\
    \ q1;\n\tstd::vector<mint2> p2, q2;\n\n\tlong long garner(long long r1, long long\
    \ r2) {\n\t\tlong long t = atcoder::internal::safe_mod((r2 - r1) * inv_m1_mod_m2,\
    \ m2);\n\t\tr1 += t * m1;\n\t\treturn r1;\n\t}\n\n\ttemplate <class T>\n\tstd::vector<T>\
    \ Berlekamp_Massey(const std::vector<T> &a) {\n\t\tint n = a.size();\n\t\tstd::vector<T>\
    \ c{-1}, c2{0};\n\t\tT r2 = 1;\n\t\tint i2 = -1;\n\t\tfor(int i = 0; i < n; i++)\
    \ {\n\t\t\tT r = 0;\n\t\t\tint d = c.size();\n\t\t\tfor(int j = 0; j < d; j++)\
    \ r += c[j] * a[i - j];\n\t\t\tif(r == 0) continue;\n\t\t\tT coef = -r / r2;\n\
    \t\t\tint d2 = c2.size();\n\t\t\tif(d - i >= d2 - i2) {\n\t\t\t\tfor(int j = 0;\
    \ j < d2; j++)\n\t\t\t\t\tc[j + i - i2] += c2[j] * coef;\n\t\t\t} else {\n\t\t\
    \t\tstd::vector<T> tmp(c);\n\t\t\t\tc.resize(d2 + i - i2);\n\t\t\t\tfor(int j\
    \ = 0; j < d2; j++) c[j + i - i2] += c2[j] * coef;\n\t\t\t\tc2 = std::move(tmp);\n\
    \t\t\t\ti2 = i, r2 = r;\n\t\t\t}\n\t\t}\n\t\tc[0] = 1;\n\t\treturn c;\n\t}\n\n\
    \ttemplate <class T>\n\tstd::pair<std::vector<T>, std::vector<T>> find_generating_function(std::vector<T>\
    \ a) {\n\t\tauto q = Berlekamp_Massey(a);\n\t\tint d = q.size() - 1;\n\t\ta.resize(d);\n\
    \t\tfor(int i = 1; i < (int)q.size(); i++) q[i] *= -1;\n\t\ta = atcoder::convolution(a,\
    \ q);\n\t\ta.resize(d);\n\t\treturn {a, q};\n\t}\n};\n"
  code: "#include <atcoder/convolution>\n#include <atcoder/modint>\n#include <cassert>\n\
    #include <vector>\n\n//\u039F(N^2)\nstruct bostan_mori_ll {\npublic:\n\tbostan_mori_ll(const\
    \ std::vector<long long> &a) {\n\t\tauto pq1 = find_generating_function(std::vector<mint1>{a.begin(),\
    \ a.end()});\n\t\tp1 = std::move(pq1.first);\n\t\tq1 = std::move(pq1.second);\n\
    \t\tauto pq2 = find_generating_function(std::vector<mint2>{a.begin(), a.end()});\n\
    \t\tp2 = std::move(pq2.first);\n\t\tq2 = std::move(pq2.second);\n\t\td = q1.size();\n\
    \t\tassert(q1[0] == 1 and p1.size() + 1 <= q1.size());\n\t}\n\n\tlong long kth_term(long\
    \ long k) {\n\t\tlong long r1, r2;\n\t\t{\n\t\t\tlong long c = k;\n\t\t\tif(d\
    \ == 1)\n\t\t\t\treturn 0;\n\t\t\tauto p = p1, q = q1;\n\t\t\twhile(c) {\n\t\t\
    \t\tauto q_minus = q;\n\t\t\t\tfor(int i = 1; i < d; i += 2)\n\t\t\t\t\tq_minus[i]\
    \ *= -1;\n\t\t\t\tp = atcoder::convolution(p, q_minus);\n\t\t\t\tq = atcoder::convolution(q,\
    \ q_minus);\n\t\t\t\tfor(int i = 0; i < d - 1; i++)\n\t\t\t\t\tp[i] = p[(i <<\
    \ 1) | (c & 1)];\n\t\t\t\tfor(int i = 0; i < d; i++)\n\t\t\t\t\tq[i] = q[i <<\
    \ 1];\n\t\t\t\tp.resize(d - 1);\n\t\t\t\tq.resize(d);\n\t\t\t\tc >>= 1;\n\t\t\t\
    }\n\t\t\tr1 = p[0].val();\n\t\t}\n\t\t{\n\t\t\tlong long c = k;\n\t\t\tif(d ==\
    \ 1)\n\t\t\t\treturn 0;\n\t\t\tauto p = p2, q = q2;\n\t\t\twhile(c) {\n\t\t\t\t\
    auto q_minus = q;\n\t\t\t\tfor(int i = 1; i < d; i += 2)\n\t\t\t\t\tq_minus[i]\
    \ *= -1;\n\t\t\t\tp = atcoder::convolution(p, q_minus);\n\t\t\t\tq = atcoder::convolution(q,\
    \ q_minus);\n\t\t\t\tfor(int i = 0; i < d - 1; i++)\n\t\t\t\t\tp[i] = p[(i <<\
    \ 1) | (c & 1)];\n\t\t\t\tfor(int i = 0; i < d; i++)\n\t\t\t\t\tq[i] = q[i <<\
    \ 1];\n\t\t\t\tp.resize(d - 1);\n\t\t\t\tq.resize(d);\n\t\t\t\tc >>= 1;\n\t\t\t\
    }\n\t\t\tr2 = p[0].val();\n\t\t}\n\t\treturn garner(r1, r2);\n\t}\n\nprivate:\n\
    \tstatic constexpr int m1 = 998244353;\n\tstatic constexpr int m2 = 1004535809;\n\
    \tstatic constexpr int inv_m1_mod_m2 = 669690699;\n\tusing mint1 = atcoder::static_modint<m1>;\n\
    \tusing mint2 = atcoder::static_modint<m2>;\n\tint d;\n\tstd::vector<mint1> p1,\
    \ q1;\n\tstd::vector<mint2> p2, q2;\n\n\tlong long garner(long long r1, long long\
    \ r2) {\n\t\tlong long t = atcoder::internal::safe_mod((r2 - r1) * inv_m1_mod_m2,\
    \ m2);\n\t\tr1 += t * m1;\n\t\treturn r1;\n\t}\n\n\ttemplate <class T>\n\tstd::vector<T>\
    \ Berlekamp_Massey(const std::vector<T> &a) {\n\t\tint n = a.size();\n\t\tstd::vector<T>\
    \ c{-1}, c2{0};\n\t\tT r2 = 1;\n\t\tint i2 = -1;\n\t\tfor(int i = 0; i < n; i++)\
    \ {\n\t\t\tT r = 0;\n\t\t\tint d = c.size();\n\t\t\tfor(int j = 0; j < d; j++)\
    \ r += c[j] * a[i - j];\n\t\t\tif(r == 0) continue;\n\t\t\tT coef = -r / r2;\n\
    \t\t\tint d2 = c2.size();\n\t\t\tif(d - i >= d2 - i2) {\n\t\t\t\tfor(int j = 0;\
    \ j < d2; j++)\n\t\t\t\t\tc[j + i - i2] += c2[j] * coef;\n\t\t\t} else {\n\t\t\
    \t\tstd::vector<T> tmp(c);\n\t\t\t\tc.resize(d2 + i - i2);\n\t\t\t\tfor(int j\
    \ = 0; j < d2; j++) c[j + i - i2] += c2[j] * coef;\n\t\t\t\tc2 = std::move(tmp);\n\
    \t\t\t\ti2 = i, r2 = r;\n\t\t\t}\n\t\t}\n\t\tc[0] = 1;\n\t\treturn c;\n\t}\n\n\
    \ttemplate <class T>\n\tstd::pair<std::vector<T>, std::vector<T>> find_generating_function(std::vector<T>\
    \ a) {\n\t\tauto q = Berlekamp_Massey(a);\n\t\tint d = q.size() - 1;\n\t\ta.resize(d);\n\
    \t\tfor(int i = 1; i < (int)q.size(); i++) q[i] *= -1;\n\t\ta = atcoder::convolution(a,\
    \ q);\n\t\ta.resize(d);\n\t\treturn {a, q};\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/bostan_mori_ll.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/bostan_mori_ll.hpp
layout: document
redirect_from:
- /library/math/bostan_mori_ll.hpp
- /library/math/bostan_mori_ll.hpp.html
title: math/bostan_mori_ll.hpp
---
