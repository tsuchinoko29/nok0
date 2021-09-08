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
  bundledCode: "#line 2 \"math/formal_power_series.hpp\"\n#include <atcoder/convolution>\n\
    #include <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \nenum Mode {\n\tFAST = 1,\n\tNAIVE = -1,\n};\ntemplate <class T, Mode mode =\
    \ FAST>\nstruct FormalPowerSeries : std::vector<T> {\n\tusing std::vector<T>::vector;\n\
    \tusing std::vector<T>::size;\n\tusing std::vector<T>::resize;\n\tusing std::vector<T>::begin;\n\
    \tusing std::vector<T>::insert;\n\tusing std::vector<T>::erase;\n\tusing F = FormalPowerSeries;\n\
    \tusing S = std::vector<std::pair<int, T>>;\n\n\tF &operator+=(const F &g) {\n\
    \t\tfor(int i = 0; i < int(std::min((*this).size(), g.size())); i++) (*this)[i]\
    \ += g[i];\n\t\treturn *this;\n\t}\n\n\tF &operator+=(const T &t) {\n\t\tassert(int((*this).size()));\n\
    \t\t(*this)[0] += t;\n\t\treturn *this;\n\t}\n\n\tF &operator-=(const F &g) {\n\
    \t\tfor(int i = 0; i < int(std::min((*this).size(), g.size())); i++) (*this)[i]\
    \ -= g[i];\n\t\treturn *this;\n\t}\n\n\tF &operator-=(const T &t) {\n\t\tassert(int((*this).size()));\n\
    \t\t(*this)[0] -= t;\n\t\treturn *this;\n\t}\n\n\tF &operator*=(const T &t) {\n\
    \t\tfor(int i = 0; i < int((*this).size()); ++i) (*this)[i] *= t;\n\t\treturn\
    \ *this;\n\t}\n\n\tF &operator/=(const T &t) {\n\t\tT div = t.inv();\n\t\tfor(int\
    \ i = 0; i < int((*this).size()); ++i) (*this)[i] *= div;\n\t\treturn *this;\n\
    \t}\n\n\tF &operator>>=(const int sz) {\n\t\tassert(sz >= 0);\n\t\tint n = (*this).size();\n\
    \t\t(*this).erase((*this).begin(), (*this).begin() + std::min(sz, n));\n\t\t(*this).resize(n);\n\
    \t\treturn *this;\n\t}\n\n\tF &operator<<=(const int sz) {\n\t\tassert(sz >= 0);\n\
    \t\tint n = (*this).size();\n\t\t(*this).insert((*this).begin(), sz, T(0));\n\t\
    \t(*this).resize(n);\n\t\treturn *this;\n\t}\n\n\tF poly_div(const F &g) {\n\t\
    \tif(this->size() < g.size()) {\n\t\t\tF ret(this->size());\n\t\t\treturn ret;\n\
    \t\t}\n\t\tif(mode == FAST) {\n\t\t\tauto ret = *this;\n\t\t\tint old = this->size();\n\
    \t\t\tint n = old - g.size() + 1;\n\t\t\tret = ((*this).rev().pre(n) * g.rev().inv(n));\n\
    \t\t\tret.rev_inplace();\n\t\t\tret.resize(old);\n\t\t\treturn ret;\n\t\t} else\
    \ {\n\t\t\tassert(g.back() != T(0));\n\t\t\tT igb = g.back().inv();\n\t\t\tint\
    \ n = (*this).size(), m = g.size();\n\t\t\tF this_copy(*this);\n\t\t\tF ret(n);\n\
    \t\t\tfor(int i = n - 1; i >= m - 1; --i) {\n\t\t\t\tT mul = this_copy[i] * igb;\n\
    \t\t\t\tret[i - m + 1] = mul;\n\t\t\t\tfor(int j = i; j > i - m; j--)\n\t\t\t\t\
    \tthis_copy[j] -= g[j - i + m - 1] * mul;\n\t\t\t}\n\t\t\treturn ret;\n\t\t}\n\
    \t}\n\n\t//\u3053\u308C\u306E\u307F\u591A\u9805\u5F0F\u306E\u9664\u7B97\u3068\u3057\
    \u3066\u6271\u3046\n\tF &operator%=(const F &g) {\n\t\treturn *this -= this->poly_div(g)\
    \ * g;\n\t}\n\n\tF &operator=(const std::vector<T> &v) {\n\t\tint n = (*this).size();\n\
    \t\tfor(int i = 0; i < n; ++i) (*this)[i] = v[i];\n\t\treturn *this;\n\t}\n\n\t\
    F operator-() const {\n\t\tF ret = *this;\n\t\treturn ret * -1;\n\t}\n\n\tF &operator*=(const\
    \ F &g) {\n\t\tif(mode == FAST) {\n\t\t\tint n = (*this).size();\n\t\t\tauto tmp\
    \ = atcoder::convolution(*this, g);\n\t\t\tfor(int i = 0; i < n; ++i) (*this)[i]\
    \ = tmp[i];\n\t\t\treturn *this;\n\t\t} else {\n\t\t\tint n = (*this).size(),\
    \ m = g.size();\n\t\t\tfor(int i = n - 1; i >= 0; --i) {\n\t\t\t\t(*this)[i] *=\
    \ g[0];\n\t\t\t\tfor(int j = 1; j < std::min(i + 1, m); j++)\n\t\t\t\t\t(*this)[i]\
    \ += (*this)[i - j] * g[j];\n\t\t\t}\n\t\t\treturn *this;\n\t\t}\n\t}\n\n\tF &operator/=(const\
    \ F &g) {\n\t\tif((*this).size() < g.size()) {\n\t\t\t(*this).assign((*this).size(),\
    \ T(0));\n\t\t\treturn *this;\n\t\t}\n\t\tif(mode == FAST) {\n\t\t\t*this *= g.inv();\n\
    \t\t\treturn *this;\n\t\t} else {\n\t\t\tassert(g[0] != T(0));\n\t\t\tT ig0 =\
    \ g[0].inv();\n\t\t\tint n = (*this).size(), m = g.size();\n\t\t\tfor(int i =\
    \ 0; i < n; ++i) {\n\t\t\t\tfor(int j = 1; j < std::min(i + 1, m); ++j)\n\t\t\t\
    \t\t(*this)[i] -= (*this)[i - j] * g[j];\n\t\t\t\t(*this)[i] *= ig0;\n\t\t\t}\n\
    \t\t\treturn *this;\n\t\t}\n\t}\n\n\tF &operator*=(S g) {\n\t\tint n = (*this).size();\n\
    \t\tauto [d, c] = g.front();\n\t\tif(!d)\n\t\t\tg.erase(g.begin());\n\t\telse\n\
    \t\t\tc = 0;\n\t\tfor(int i = n - 1; i >= 0; --i) {\n\t\t\t(*this)[i] *= c;\n\t\
    \t\tfor(auto &[j, b] : g) {\n\t\t\t\tif(j > i) break;\n\t\t\t\t(*this)[i] += (*this)[i\
    \ - j] * b;\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tF &operator/=(S g) {\n\
    \t\tint n = (*this).size();\n\t\tauto [d, c] = g.front();\n\t\tassert(!d and c\
    \ != 0);\n\t\tT ic = c.inv();\n\t\tg.erase(g.begin());\n\t\tfor(int i = 0; i <\
    \ n; ++i) {\n\t\t\tfor(auto &[j, b] : g) {\n\t\t\t\tif(j > i) break;\n\t\t\t\t\
    (*this)[i] -= (*this)[i - j] * b;\n\t\t\t}\n\t\t\t(*this)[i] *= ic;\n\t\t}\n\t\
    \treturn *this;\n\t}\n\n\tF operator+(const F &g) const { return F(*this) += g;\
    \ }\n\n\tF operator+(const T &t) const { return F(*this) += t; }\n\n\tF operator-(const\
    \ F &g) const { return F(*this) -= g; }\n\n\tF operator-(const T &t) const { return\
    \ F(*this) -= t; }\n\n\tF operator*(const F &g) const { return F(*this) *= g;\
    \ }\n\n\tF operator*(const T &t) const { return F(*this) *= t; }\n\n\tF operator/(const\
    \ F &g) const { return F(*this) /= g; }\n\n\tF operator/(const T &t) const { return\
    \ F(*this) /= t; }\n\n\tF operator%(const F &g) const { return F(*this) %= g;\
    \ }\n\n\tF operator*=(const S &g) const { return F(*this) *= g; }\n\n\tF operator/=(const\
    \ S &g) const { return F(*this) /= g; }\n\n\tF pre(int d) const { return F((*this).begin(),\
    \ (*this).begin() + std::min((int)(*this).size(), d)); }\n\n\tF &shrink() {\n\t\
    \twhile((int)(*this).size() > 1 and (*this).back() == T(0)) (*this).pop_back();\n\
    \t\treturn *this;\n\t}\n\n\tF &rev_inplace() {\n\t\treverse((*this).begin(), (*this).end());\n\
    \t\treturn *this;\n\t}\n\tF rev() const { return F(*this).rev_inplace(); }\n\n\
    \t// *=(1 + cz^d)\n\tF &multiply(const int d, const T c) {\n\t\tint n = (*this).size();\n\
    \t\tif(c == T(1))\n\t\t\tfor(int i = n - d - 1; i >= 0; --i)\n\t\t\t\t(*this)[i\
    \ + d] += (*this)[i];\n\t\telse if(c == T(-1))\n\t\t\tfor(int i = n - d - 1; i\
    \ >= 0; --i)\n\t\t\t\t(*this)[i + d] -= (*this)[i];\n\t\telse\n\t\t\tfor(int i\
    \ = n - d - 1; i >= 0; --i)\n\t\t\t\t(*this)[i + d] += (*this)[i] * c;\n\t\treturn\
    \ *this;\n\t}\n\t// /=(1 + cz^d)\n\tF &divide(const int d, const T c) {\n\t\t\
    int n = (*this).size();\n\t\tif(c == T(1))\n\t\t\tfor(int i = 0; i < n - d; ++i)\
    \ (*this)[i + d] -= (*this)[i];\n\t\telse if(c == T(-1))\n\t\t\tfor(int i = 0;\
    \ i < n - d; ++i) (*this)[i + d] += (*this)[i];\n\t\telse\n\t\t\tfor(int i = 0;\
    \ i < n - d; ++i) (*this)[i + d] -= (*this)[i] * c;\n\t\treturn *this;\n\t}\n\n\
    \t//\u039F(N)\n\tT eval(const T &t) const {\n\t\tint n = (*this).size();\n\t\t\
    T res = 0, tmp = 1;\n\t\tfor(int i = 0; i < n; ++i) res += (*this)[i] * tmp, tmp\
    \ *= t;\n\t\treturn res;\n\t}\n\n\tF inv(int deg = -1) const {\n\t\tint n = (*this).size();\n\
    \t\tassert(mode == FAST and n and (*this)[0] != 0);\n\t\tif(deg == -1) deg = n;\n\
    \t\tassert(deg > 0);\n\t\tF res{(*this)[0].inv()};\n\t\twhile(int(res.size())\
    \ < deg) {\n\t\t\tint m = res.size();\n\t\t\tF f((*this).begin(), (*this).begin()\
    \ + std::min(n, m * 2)), r(res);\n\t\t\tf.resize(m * 2), atcoder::internal::butterfly(f);\n\
    \t\t\tr.resize(m * 2), atcoder::internal::butterfly(r);\n\t\t\tfor(int i = 0;\
    \ i < m * 2; ++i) f[i] *= r[i];\n\t\t\tatcoder::internal::butterfly_inv(f);\n\t\
    \t\tf.erase(f.begin(), f.begin() + m);\n\t\t\tf.resize(m * 2), atcoder::internal::butterfly(f);\n\
    \t\t\tfor(int i = 0; i < m * 2; ++i) f[i] *= r[i];\n\t\t\tatcoder::internal::butterfly_inv(f);\n\
    \t\t\tT iz = T(m * 2).inv();\n\t\t\tiz *= -iz;\n\t\t\tfor(int i = 0; i < m; ++i)\
    \ f[i] *= iz;\n\t\t\tres.insert(res.end(), f.begin(), f.begin() + m);\n\t\t}\n\
    \t\tres.resize(deg);\n\t\treturn res;\n\t}\n\n\t//\u039F(N)\n\tF &diff_inplace()\
    \ {\n\t\tint n = (*this).size();\n\t\tfor(int i = 1; i < n; ++i) (*this)[i - 1]\
    \ = (*this)[i] * i;\n\t\t(*this)[n - 1] = 0;\n\t\treturn *this;\n\t}\n\tF diff()\
    \ const { F(*this).diff_inplace(); }\n\n\t//\u039F(N)\n\tF &integral_inplace()\
    \ {\n\t\tint n = (*this).size(), mod = T::mod();\n\t\tstd::vector<T> inv(n);\n\
    \t\t{\n\t\t\tinv[1] = 1;\n\t\t\tfor(int i = 2; i < n; ++i)\n\t\t\t\tinv[i] = T(mod)\
    \ - inv[mod % i] * (mod / i);\n\t\t}\n\t\tfor(int i = n - 2; i >= 0; --i) (*this)[i\
    \ + 1] = (*this)[i] * inv[i + 1];\n\t\t(*this)[0] = 0;\n\t\treturn *this;\n\t\
    }\n\tF integral() const { return F(*this).integral_inplace(); }\n\n\t//\u039F\
    (NlogN)\n\tF &log_inplace() {\n\t\tint n = (*this).size();\n\t\tassert(n and (*this)[0]\
    \ == 1);\n\t\tF f_inv = (*this).inv();\n\t\t(*this).diff_inplace();\n\t\t(*this)\
    \ *= f_inv;\n\t\t(*this).integral_inplace();\n\t\treturn *this;\n\t}\n\tF log()\
    \ const { return F(*this).log_inplace(); }\n\n\t//\u039F(NlogN)\n\tF &deriv_inplace()\
    \ {\n\t\tint n = (*this).size();\n\t\tassert(n);\n\t\tfor(int i = 2; i < n; ++i)\
    \ (*this)[i] *= i;\n\t\t(*this).erase((*this).begin());\n\t\t(*this).push_back(0);\n\
    \t\treturn *this;\n\t}\n\tF deriv() const { return F(*this).deriv_inplace(); }\n\
    \n\t//\u039F(NlogN)\n\tF &exp_inplace() {\n\t\tint n = (*this).size();\n\t\tassert(n\
    \ and (*this)[0] == 0);\n\t\tF g{1};\n\t\t(*this)[0] = 1;\n\t\tF h_drv((*this).deriv());\n\
    \t\tfor(int m = 1; m < n; m *= 2) {\n\t\t\tF f((*this).begin(), (*this).begin()\
    \ + m);\n\t\t\tf.resize(2 * m), atcoder::internal::butterfly(f);\n\t\t\tauto mult_f\
    \ = [&](F &p) {\n\t\t\t\tp.resize(2 * m);\n\t\t\t\tatcoder::internal::butterfly(p);\n\
    \t\t\t\tfor(int i = 0; i < 2 * m; ++i) p[i] *= f[i];\n\t\t\t\tatcoder::internal::butterfly_inv(p);\n\
    \t\t\t\tp /= 2 * m;\n\t\t\t};\n\t\t\tif(m > 1) {\n\t\t\t\tF g_(g);\n\t\t\t\tg_.resize(2\
    \ * m), atcoder::internal::butterfly(g_);\n\t\t\t\tfor(int i = 0; i < 2 * m; ++i)\
    \ g_[i] *= g_[i] * f[i];\n\t\t\t\tatcoder::internal::butterfly_inv(g_);\n\t\t\t\
    \tT iz = T(-2 * m).inv();\n\t\t\t\tg_ *= iz;\n\t\t\t\tg.insert(g.end(), g_.begin()\
    \ + m / 2, g_.begin() + m);\n\t\t\t}\n\t\t\tF t((*this).begin(), (*this).begin()\
    \ + m);\n\t\t\tt.deriv_inplace();\n\t\t\t{\n\t\t\t\tF r{h_drv.begin(), h_drv.begin()\
    \ + m - 1};\n\t\t\t\tmult_f(r);\n\t\t\t\tfor(int i = 0; i < m; ++i) t[i] -= r[i]\
    \ + r[m + i];\n\t\t\t}\n\t\t\tt.insert(t.begin(), t.back());\n\t\t\tt.pop_back();\n\
    \t\t\tt *= g;\n\t\t\tF v((*this).begin() + m, (*this).begin() + std::min(n, 2\
    \ * m));\n\t\t\tv.resize(m);\n\t\t\tt.insert(t.begin(), m - 1, 0);\n\t\t\tt.push_back(0);\n\
    \t\t\tt.integral_inplace();\n\t\t\tfor(int i = 0; i < m; ++i) v[i] -= t[m + i];\n\
    \t\t\tmult_f(v);\n\t\t\tfor(int i = 0; i < std::min(n - m, m); ++i)\n\t\t\t\t\
    (*this)[m + i] = v[i];\n\t\t}\n\t\treturn *this;\n\t}\n\tF exp() const { return\
    \ F(*this).exp_inplace(); }\n\n\t//\u039F(NlogN)\n\tF &pow_inplace(long long k)\
    \ {\n\t\tint n = (*this).size(), l = 0;\n\t\tassert(k >= 0);\n\t\tif(!k) {\n\t\
    \t\tfor(int i = 0; i < n; ++i) (*this)[i] = !i;\n\t\t\treturn *this;\n\t\t}\n\t\
    \twhile(l < n and (*this)[l] == 0) ++l;\n\t\tif(l > (n - 1) / k or l == n) return\
    \ *this = F(n);\n\t\tT c = (*this)[l];\n\t\t(*this).erase((*this).begin(), (*this).begin()\
    \ + l);\n\t\t(*this) /= c;\n\t\t(*this).log_inplace();\n\t\t(*this).resize(n -\
    \ l * k);\n\t\t(*this) *= k;\n\t\t(*this).exp_inplace();\n\t\t(*this) *= c.pow(k);\n\
    \t\t(*this).insert((*this).begin(), l * k, 0);\n\t\treturn *this;\n\t}\n\tF pow(const\
    \ long long k) const { return F(*this).pow_inplace(k); }\n\n\t//\u039F(NlogN)\n\
    \tF sqrt(int deg = -1) const {\n\t\tauto SQRT = [&](T t) {\n\t\t\tint mod = T::mod();\n\
    \t\t\tif(t == 0 or t == 1) return t;\n\t\t\tint v = (mod - 1) / 2;\n\t\t\tif(t.pow(v)\
    \ != 1) return T(-1);\n\t\t\tint q = mod - 1, m = 0;\n\t\t\twhile(~q & 1) q >>=\
    \ 1, m++;\n\t\t\tstd::mt19937 mt;\n\t\t\tT z = mt();\n\t\t\twhile(z.pow(v) !=\
    \ mod - 1) z = mt();\n\t\t\tT c = z.pow(q), u = t.pow(q), r = t.pow((q + 1) /\
    \ 2);\n\t\t\tfor(; m > 1; m--) {\n\t\t\t\tT tmp = u.pow(1 << (m - 2));\n\t\t\t\
    \tif(tmp != 1) r = r * c, u = u * c * c;\n\t\t\t\tc = c * c;\n\t\t\t}\n\t\t\t\
    return T(std::min(r.val(), mod - r.val()));\n\t\t};\n\t\tint n = (*this).size();\n\
    \t\tif(deg == -1) deg = n;\n\t\tif((*this)[0] == 0) {\n\t\t\tfor(int i = 1; i\
    \ < n; i++) {\n\t\t\t\tif((*this)[i] != 0) {\n\t\t\t\t\tif(i & 1) return F(0);\n\
    \t\t\t\t\tif(deg - i / 2 <= 0) break;\n\t\t\t\t\tauto ret = (*this);\n\t\t\t\t\
    \tret >>= i;\n\t\t\t\t\tret.resize(n - i);\n\t\t\t\t\tret = ret.sqrt(deg - i /\
    \ 2);\n\t\t\t\t\tif(ret.empty()) return F(0);\n\t\t\t\t\tret <<= (i / 2);\n\t\t\
    \t\t\tret.resize(deg);\n\t\t\t\t\treturn ret;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ F(deg);\n\t\t}\n\t\tauto sqr = SQRT((*this)[0]);\n\t\tif(sqr * sqr != (*this)[0])\
    \ return F(0);\n\t\tF ret{sqr};\n\t\tT ti = T(1) / T(2);\n\t\tfor(int i = 1; i\
    \ < deg; i <<= 1) {\n\t\t\tauto u = (*this);\n\t\t\tu.resize(i << 1);\n\t\t\t\
    ret = (ret.inv(i << 1) * u + ret) * ti;\n\t\t}\n\t\tret.resize(deg);\n\t\treturn\
    \ ret;\n\t}\n\n\tvoid sparse_pow(const int n, const int d, const T c, const int\
    \ k);\n\tvoid sparse_pow_inv(const int n, const int d, const T c, const int k);\n\
    \tvoid stirling_first(int n);\n\tvoid stirling_second(int n);\n\tstd::vector<T>\
    \ multipoint_evaluation(const std::vector<T> &p);\n};\n"
  code: "#pragma once\n#include <atcoder/convolution>\n#include <cassert>\n#include\
    \ <iostream>\n#include <random>\n#include <vector>\n\nenum Mode {\n\tFAST = 1,\n\
    \tNAIVE = -1,\n};\ntemplate <class T, Mode mode = FAST>\nstruct FormalPowerSeries\
    \ : std::vector<T> {\n\tusing std::vector<T>::vector;\n\tusing std::vector<T>::size;\n\
    \tusing std::vector<T>::resize;\n\tusing std::vector<T>::begin;\n\tusing std::vector<T>::insert;\n\
    \tusing std::vector<T>::erase;\n\tusing F = FormalPowerSeries;\n\tusing S = std::vector<std::pair<int,\
    \ T>>;\n\n\tF &operator+=(const F &g) {\n\t\tfor(int i = 0; i < int(std::min((*this).size(),\
    \ g.size())); i++) (*this)[i] += g[i];\n\t\treturn *this;\n\t}\n\n\tF &operator+=(const\
    \ T &t) {\n\t\tassert(int((*this).size()));\n\t\t(*this)[0] += t;\n\t\treturn\
    \ *this;\n\t}\n\n\tF &operator-=(const F &g) {\n\t\tfor(int i = 0; i < int(std::min((*this).size(),\
    \ g.size())); i++) (*this)[i] -= g[i];\n\t\treturn *this;\n\t}\n\n\tF &operator-=(const\
    \ T &t) {\n\t\tassert(int((*this).size()));\n\t\t(*this)[0] -= t;\n\t\treturn\
    \ *this;\n\t}\n\n\tF &operator*=(const T &t) {\n\t\tfor(int i = 0; i < int((*this).size());\
    \ ++i) (*this)[i] *= t;\n\t\treturn *this;\n\t}\n\n\tF &operator/=(const T &t)\
    \ {\n\t\tT div = t.inv();\n\t\tfor(int i = 0; i < int((*this).size()); ++i) (*this)[i]\
    \ *= div;\n\t\treturn *this;\n\t}\n\n\tF &operator>>=(const int sz) {\n\t\tassert(sz\
    \ >= 0);\n\t\tint n = (*this).size();\n\t\t(*this).erase((*this).begin(), (*this).begin()\
    \ + std::min(sz, n));\n\t\t(*this).resize(n);\n\t\treturn *this;\n\t}\n\n\tF &operator<<=(const\
    \ int sz) {\n\t\tassert(sz >= 0);\n\t\tint n = (*this).size();\n\t\t(*this).insert((*this).begin(),\
    \ sz, T(0));\n\t\t(*this).resize(n);\n\t\treturn *this;\n\t}\n\n\tF poly_div(const\
    \ F &g) {\n\t\tif(this->size() < g.size()) {\n\t\t\tF ret(this->size());\n\t\t\
    \treturn ret;\n\t\t}\n\t\tif(mode == FAST) {\n\t\t\tauto ret = *this;\n\t\t\t\
    int old = this->size();\n\t\t\tint n = old - g.size() + 1;\n\t\t\tret = ((*this).rev().pre(n)\
    \ * g.rev().inv(n));\n\t\t\tret.rev_inplace();\n\t\t\tret.resize(old);\n\t\t\t\
    return ret;\n\t\t} else {\n\t\t\tassert(g.back() != T(0));\n\t\t\tT igb = g.back().inv();\n\
    \t\t\tint n = (*this).size(), m = g.size();\n\t\t\tF this_copy(*this);\n\t\t\t\
    F ret(n);\n\t\t\tfor(int i = n - 1; i >= m - 1; --i) {\n\t\t\t\tT mul = this_copy[i]\
    \ * igb;\n\t\t\t\tret[i - m + 1] = mul;\n\t\t\t\tfor(int j = i; j > i - m; j--)\n\
    \t\t\t\t\tthis_copy[j] -= g[j - i + m - 1] * mul;\n\t\t\t}\n\t\t\treturn ret;\n\
    \t\t}\n\t}\n\n\t//\u3053\u308C\u306E\u307F\u591A\u9805\u5F0F\u306E\u9664\u7B97\
    \u3068\u3057\u3066\u6271\u3046\n\tF &operator%=(const F &g) {\n\t\treturn *this\
    \ -= this->poly_div(g) * g;\n\t}\n\n\tF &operator=(const std::vector<T> &v) {\n\
    \t\tint n = (*this).size();\n\t\tfor(int i = 0; i < n; ++i) (*this)[i] = v[i];\n\
    \t\treturn *this;\n\t}\n\n\tF operator-() const {\n\t\tF ret = *this;\n\t\treturn\
    \ ret * -1;\n\t}\n\n\tF &operator*=(const F &g) {\n\t\tif(mode == FAST) {\n\t\t\
    \tint n = (*this).size();\n\t\t\tauto tmp = atcoder::convolution(*this, g);\n\t\
    \t\tfor(int i = 0; i < n; ++i) (*this)[i] = tmp[i];\n\t\t\treturn *this;\n\t\t\
    } else {\n\t\t\tint n = (*this).size(), m = g.size();\n\t\t\tfor(int i = n - 1;\
    \ i >= 0; --i) {\n\t\t\t\t(*this)[i] *= g[0];\n\t\t\t\tfor(int j = 1; j < std::min(i\
    \ + 1, m); j++)\n\t\t\t\t\t(*this)[i] += (*this)[i - j] * g[j];\n\t\t\t}\n\t\t\
    \treturn *this;\n\t\t}\n\t}\n\n\tF &operator/=(const F &g) {\n\t\tif((*this).size()\
    \ < g.size()) {\n\t\t\t(*this).assign((*this).size(), T(0));\n\t\t\treturn *this;\n\
    \t\t}\n\t\tif(mode == FAST) {\n\t\t\t*this *= g.inv();\n\t\t\treturn *this;\n\t\
    \t} else {\n\t\t\tassert(g[0] != T(0));\n\t\t\tT ig0 = g[0].inv();\n\t\t\tint\
    \ n = (*this).size(), m = g.size();\n\t\t\tfor(int i = 0; i < n; ++i) {\n\t\t\t\
    \tfor(int j = 1; j < std::min(i + 1, m); ++j)\n\t\t\t\t\t(*this)[i] -= (*this)[i\
    \ - j] * g[j];\n\t\t\t\t(*this)[i] *= ig0;\n\t\t\t}\n\t\t\treturn *this;\n\t\t\
    }\n\t}\n\n\tF &operator*=(S g) {\n\t\tint n = (*this).size();\n\t\tauto [d, c]\
    \ = g.front();\n\t\tif(!d)\n\t\t\tg.erase(g.begin());\n\t\telse\n\t\t\tc = 0;\n\
    \t\tfor(int i = n - 1; i >= 0; --i) {\n\t\t\t(*this)[i] *= c;\n\t\t\tfor(auto\
    \ &[j, b] : g) {\n\t\t\t\tif(j > i) break;\n\t\t\t\t(*this)[i] += (*this)[i -\
    \ j] * b;\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tF &operator/=(S g) {\n\t\
    \tint n = (*this).size();\n\t\tauto [d, c] = g.front();\n\t\tassert(!d and c !=\
    \ 0);\n\t\tT ic = c.inv();\n\t\tg.erase(g.begin());\n\t\tfor(int i = 0; i < n;\
    \ ++i) {\n\t\t\tfor(auto &[j, b] : g) {\n\t\t\t\tif(j > i) break;\n\t\t\t\t(*this)[i]\
    \ -= (*this)[i - j] * b;\n\t\t\t}\n\t\t\t(*this)[i] *= ic;\n\t\t}\n\t\treturn\
    \ *this;\n\t}\n\n\tF operator+(const F &g) const { return F(*this) += g; }\n\n\
    \tF operator+(const T &t) const { return F(*this) += t; }\n\n\tF operator-(const\
    \ F &g) const { return F(*this) -= g; }\n\n\tF operator-(const T &t) const { return\
    \ F(*this) -= t; }\n\n\tF operator*(const F &g) const { return F(*this) *= g;\
    \ }\n\n\tF operator*(const T &t) const { return F(*this) *= t; }\n\n\tF operator/(const\
    \ F &g) const { return F(*this) /= g; }\n\n\tF operator/(const T &t) const { return\
    \ F(*this) /= t; }\n\n\tF operator%(const F &g) const { return F(*this) %= g;\
    \ }\n\n\tF operator*=(const S &g) const { return F(*this) *= g; }\n\n\tF operator/=(const\
    \ S &g) const { return F(*this) /= g; }\n\n\tF pre(int d) const { return F((*this).begin(),\
    \ (*this).begin() + std::min((int)(*this).size(), d)); }\n\n\tF &shrink() {\n\t\
    \twhile((int)(*this).size() > 1 and (*this).back() == T(0)) (*this).pop_back();\n\
    \t\treturn *this;\n\t}\n\n\tF &rev_inplace() {\n\t\treverse((*this).begin(), (*this).end());\n\
    \t\treturn *this;\n\t}\n\tF rev() const { return F(*this).rev_inplace(); }\n\n\
    \t// *=(1 + cz^d)\n\tF &multiply(const int d, const T c) {\n\t\tint n = (*this).size();\n\
    \t\tif(c == T(1))\n\t\t\tfor(int i = n - d - 1; i >= 0; --i)\n\t\t\t\t(*this)[i\
    \ + d] += (*this)[i];\n\t\telse if(c == T(-1))\n\t\t\tfor(int i = n - d - 1; i\
    \ >= 0; --i)\n\t\t\t\t(*this)[i + d] -= (*this)[i];\n\t\telse\n\t\t\tfor(int i\
    \ = n - d - 1; i >= 0; --i)\n\t\t\t\t(*this)[i + d] += (*this)[i] * c;\n\t\treturn\
    \ *this;\n\t}\n\t// /=(1 + cz^d)\n\tF &divide(const int d, const T c) {\n\t\t\
    int n = (*this).size();\n\t\tif(c == T(1))\n\t\t\tfor(int i = 0; i < n - d; ++i)\
    \ (*this)[i + d] -= (*this)[i];\n\t\telse if(c == T(-1))\n\t\t\tfor(int i = 0;\
    \ i < n - d; ++i) (*this)[i + d] += (*this)[i];\n\t\telse\n\t\t\tfor(int i = 0;\
    \ i < n - d; ++i) (*this)[i + d] -= (*this)[i] * c;\n\t\treturn *this;\n\t}\n\n\
    \t//\u039F(N)\n\tT eval(const T &t) const {\n\t\tint n = (*this).size();\n\t\t\
    T res = 0, tmp = 1;\n\t\tfor(int i = 0; i < n; ++i) res += (*this)[i] * tmp, tmp\
    \ *= t;\n\t\treturn res;\n\t}\n\n\tF inv(int deg = -1) const {\n\t\tint n = (*this).size();\n\
    \t\tassert(mode == FAST and n and (*this)[0] != 0);\n\t\tif(deg == -1) deg = n;\n\
    \t\tassert(deg > 0);\n\t\tF res{(*this)[0].inv()};\n\t\twhile(int(res.size())\
    \ < deg) {\n\t\t\tint m = res.size();\n\t\t\tF f((*this).begin(), (*this).begin()\
    \ + std::min(n, m * 2)), r(res);\n\t\t\tf.resize(m * 2), atcoder::internal::butterfly(f);\n\
    \t\t\tr.resize(m * 2), atcoder::internal::butterfly(r);\n\t\t\tfor(int i = 0;\
    \ i < m * 2; ++i) f[i] *= r[i];\n\t\t\tatcoder::internal::butterfly_inv(f);\n\t\
    \t\tf.erase(f.begin(), f.begin() + m);\n\t\t\tf.resize(m * 2), atcoder::internal::butterfly(f);\n\
    \t\t\tfor(int i = 0; i < m * 2; ++i) f[i] *= r[i];\n\t\t\tatcoder::internal::butterfly_inv(f);\n\
    \t\t\tT iz = T(m * 2).inv();\n\t\t\tiz *= -iz;\n\t\t\tfor(int i = 0; i < m; ++i)\
    \ f[i] *= iz;\n\t\t\tres.insert(res.end(), f.begin(), f.begin() + m);\n\t\t}\n\
    \t\tres.resize(deg);\n\t\treturn res;\n\t}\n\n\t//\u039F(N)\n\tF &diff_inplace()\
    \ {\n\t\tint n = (*this).size();\n\t\tfor(int i = 1; i < n; ++i) (*this)[i - 1]\
    \ = (*this)[i] * i;\n\t\t(*this)[n - 1] = 0;\n\t\treturn *this;\n\t}\n\tF diff()\
    \ const { F(*this).diff_inplace(); }\n\n\t//\u039F(N)\n\tF &integral_inplace()\
    \ {\n\t\tint n = (*this).size(), mod = T::mod();\n\t\tstd::vector<T> inv(n);\n\
    \t\t{\n\t\t\tinv[1] = 1;\n\t\t\tfor(int i = 2; i < n; ++i)\n\t\t\t\tinv[i] = T(mod)\
    \ - inv[mod % i] * (mod / i);\n\t\t}\n\t\tfor(int i = n - 2; i >= 0; --i) (*this)[i\
    \ + 1] = (*this)[i] * inv[i + 1];\n\t\t(*this)[0] = 0;\n\t\treturn *this;\n\t\
    }\n\tF integral() const { return F(*this).integral_inplace(); }\n\n\t//\u039F\
    (NlogN)\n\tF &log_inplace() {\n\t\tint n = (*this).size();\n\t\tassert(n and (*this)[0]\
    \ == 1);\n\t\tF f_inv = (*this).inv();\n\t\t(*this).diff_inplace();\n\t\t(*this)\
    \ *= f_inv;\n\t\t(*this).integral_inplace();\n\t\treturn *this;\n\t}\n\tF log()\
    \ const { return F(*this).log_inplace(); }\n\n\t//\u039F(NlogN)\n\tF &deriv_inplace()\
    \ {\n\t\tint n = (*this).size();\n\t\tassert(n);\n\t\tfor(int i = 2; i < n; ++i)\
    \ (*this)[i] *= i;\n\t\t(*this).erase((*this).begin());\n\t\t(*this).push_back(0);\n\
    \t\treturn *this;\n\t}\n\tF deriv() const { return F(*this).deriv_inplace(); }\n\
    \n\t//\u039F(NlogN)\n\tF &exp_inplace() {\n\t\tint n = (*this).size();\n\t\tassert(n\
    \ and (*this)[0] == 0);\n\t\tF g{1};\n\t\t(*this)[0] = 1;\n\t\tF h_drv((*this).deriv());\n\
    \t\tfor(int m = 1; m < n; m *= 2) {\n\t\t\tF f((*this).begin(), (*this).begin()\
    \ + m);\n\t\t\tf.resize(2 * m), atcoder::internal::butterfly(f);\n\t\t\tauto mult_f\
    \ = [&](F &p) {\n\t\t\t\tp.resize(2 * m);\n\t\t\t\tatcoder::internal::butterfly(p);\n\
    \t\t\t\tfor(int i = 0; i < 2 * m; ++i) p[i] *= f[i];\n\t\t\t\tatcoder::internal::butterfly_inv(p);\n\
    \t\t\t\tp /= 2 * m;\n\t\t\t};\n\t\t\tif(m > 1) {\n\t\t\t\tF g_(g);\n\t\t\t\tg_.resize(2\
    \ * m), atcoder::internal::butterfly(g_);\n\t\t\t\tfor(int i = 0; i < 2 * m; ++i)\
    \ g_[i] *= g_[i] * f[i];\n\t\t\t\tatcoder::internal::butterfly_inv(g_);\n\t\t\t\
    \tT iz = T(-2 * m).inv();\n\t\t\t\tg_ *= iz;\n\t\t\t\tg.insert(g.end(), g_.begin()\
    \ + m / 2, g_.begin() + m);\n\t\t\t}\n\t\t\tF t((*this).begin(), (*this).begin()\
    \ + m);\n\t\t\tt.deriv_inplace();\n\t\t\t{\n\t\t\t\tF r{h_drv.begin(), h_drv.begin()\
    \ + m - 1};\n\t\t\t\tmult_f(r);\n\t\t\t\tfor(int i = 0; i < m; ++i) t[i] -= r[i]\
    \ + r[m + i];\n\t\t\t}\n\t\t\tt.insert(t.begin(), t.back());\n\t\t\tt.pop_back();\n\
    \t\t\tt *= g;\n\t\t\tF v((*this).begin() + m, (*this).begin() + std::min(n, 2\
    \ * m));\n\t\t\tv.resize(m);\n\t\t\tt.insert(t.begin(), m - 1, 0);\n\t\t\tt.push_back(0);\n\
    \t\t\tt.integral_inplace();\n\t\t\tfor(int i = 0; i < m; ++i) v[i] -= t[m + i];\n\
    \t\t\tmult_f(v);\n\t\t\tfor(int i = 0; i < std::min(n - m, m); ++i)\n\t\t\t\t\
    (*this)[m + i] = v[i];\n\t\t}\n\t\treturn *this;\n\t}\n\tF exp() const { return\
    \ F(*this).exp_inplace(); }\n\n\t//\u039F(NlogN)\n\tF &pow_inplace(long long k)\
    \ {\n\t\tint n = (*this).size(), l = 0;\n\t\tassert(k >= 0);\n\t\tif(!k) {\n\t\
    \t\tfor(int i = 0; i < n; ++i) (*this)[i] = !i;\n\t\t\treturn *this;\n\t\t}\n\t\
    \twhile(l < n and (*this)[l] == 0) ++l;\n\t\tif(l > (n - 1) / k or l == n) return\
    \ *this = F(n);\n\t\tT c = (*this)[l];\n\t\t(*this).erase((*this).begin(), (*this).begin()\
    \ + l);\n\t\t(*this) /= c;\n\t\t(*this).log_inplace();\n\t\t(*this).resize(n -\
    \ l * k);\n\t\t(*this) *= k;\n\t\t(*this).exp_inplace();\n\t\t(*this) *= c.pow(k);\n\
    \t\t(*this).insert((*this).begin(), l * k, 0);\n\t\treturn *this;\n\t}\n\tF pow(const\
    \ long long k) const { return F(*this).pow_inplace(k); }\n\n\t//\u039F(NlogN)\n\
    \tF sqrt(int deg = -1) const {\n\t\tauto SQRT = [&](T t) {\n\t\t\tint mod = T::mod();\n\
    \t\t\tif(t == 0 or t == 1) return t;\n\t\t\tint v = (mod - 1) / 2;\n\t\t\tif(t.pow(v)\
    \ != 1) return T(-1);\n\t\t\tint q = mod - 1, m = 0;\n\t\t\twhile(~q & 1) q >>=\
    \ 1, m++;\n\t\t\tstd::mt19937 mt;\n\t\t\tT z = mt();\n\t\t\twhile(z.pow(v) !=\
    \ mod - 1) z = mt();\n\t\t\tT c = z.pow(q), u = t.pow(q), r = t.pow((q + 1) /\
    \ 2);\n\t\t\tfor(; m > 1; m--) {\n\t\t\t\tT tmp = u.pow(1 << (m - 2));\n\t\t\t\
    \tif(tmp != 1) r = r * c, u = u * c * c;\n\t\t\t\tc = c * c;\n\t\t\t}\n\t\t\t\
    return T(std::min(r.val(), mod - r.val()));\n\t\t};\n\t\tint n = (*this).size();\n\
    \t\tif(deg == -1) deg = n;\n\t\tif((*this)[0] == 0) {\n\t\t\tfor(int i = 1; i\
    \ < n; i++) {\n\t\t\t\tif((*this)[i] != 0) {\n\t\t\t\t\tif(i & 1) return F(0);\n\
    \t\t\t\t\tif(deg - i / 2 <= 0) break;\n\t\t\t\t\tauto ret = (*this);\n\t\t\t\t\
    \tret >>= i;\n\t\t\t\t\tret.resize(n - i);\n\t\t\t\t\tret = ret.sqrt(deg - i /\
    \ 2);\n\t\t\t\t\tif(ret.empty()) return F(0);\n\t\t\t\t\tret <<= (i / 2);\n\t\t\
    \t\t\tret.resize(deg);\n\t\t\t\t\treturn ret;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ F(deg);\n\t\t}\n\t\tauto sqr = SQRT((*this)[0]);\n\t\tif(sqr * sqr != (*this)[0])\
    \ return F(0);\n\t\tF ret{sqr};\n\t\tT ti = T(1) / T(2);\n\t\tfor(int i = 1; i\
    \ < deg; i <<= 1) {\n\t\t\tauto u = (*this);\n\t\t\tu.resize(i << 1);\n\t\t\t\
    ret = (ret.inv(i << 1) * u + ret) * ti;\n\t\t}\n\t\tret.resize(deg);\n\t\treturn\
    \ ret;\n\t}\n\n\tvoid sparse_pow(const int n, const int d, const T c, const int\
    \ k);\n\tvoid sparse_pow_inv(const int n, const int d, const T c, const int k);\n\
    \tvoid stirling_first(int n);\n\tvoid stirling_second(int n);\n\tstd::vector<T>\
    \ multipoint_evaluation(const std::vector<T> &p);\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/formal_power_series.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/formal_power_series.hpp
layout: document
redirect_from:
- /library/math/formal_power_series.hpp
- /library/math/formal_power_series.hpp.html
title: math/formal_power_series.hpp
---
