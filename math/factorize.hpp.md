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
  bundledCode: "#line 1 \"math/factorize.hpp\"\n#include <bits/stdc++.h>\n\n#include\
    \ <atcoder/modint>\n\nnamespace inner {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    using i64 = int64_t;\nusing u128 = __uint128_t;\n\nu64 gcd_impl(u64 n, u64 m)\
    \ {\n\tconstexpr u64 K = 5;\n\tfor(u32 i = 0; i < 80; ++i) {\n\t\tu64 t = n -\
    \ m;\n\t\tu64 s = n - m * K;\n\t\tbool q = t < m;\n\t\tbool p = t < m * K;\n\t\
    \tn = q ? m : t;\n\t\tm = q ? t : m;\n\t\tif(m == 0) return n;\n\t\tn = p ? n\
    \ : s;\n\t}\n\treturn gcd_impl(m, n % m);\n}\n\nu64 gcd_pre(u64 n, u64 m) {\n\t\
    for(u32 i = 0; i < 4; ++i) {\n\t\tu64 t = n - m;\n\t\tbool q = t < m;\n\t\tn =\
    \ q ? m : t;\n\t\tm = q ? t : m;\n\t\tif(m == 0) return n;\n\t}\n\treturn gcd_impl(n,\
    \ m);\n}\n\nu64 gcd_fast(u64 n, u64 m) { return n > m ? gcd_pre(n, m) : gcd_pre(m,\
    \ n); }\n\nstruct modint64 {\n\tusing u64 = uint64_t;\n\npublic:\n\tstatic u64\
    \ mod;\n\tstatic u64 r, n2;\n\tstatic void set_mod(u64 m) {\n\t\tmod = m;\n\t\t\
    n2 = -u128(m) % m;\n\t\tr = get_r();\n\t\tassert(r * mod == 1);\n\t}\n\tmodint64()\
    \ : a(0) {}\n\tmodint64(const i64 &b) : a(reduce((u128(b) + mod) * n2)) {}\n\n\
    \tmodint64 &operator+=(const modint64 &b) {\n\t\tif(i64(a += b.a - 2 * mod) <\
    \ 0) a += 2 * mod;\n\t\treturn *this;\n\t}\n\n\tmodint64 &operator-=(const modint64\
    \ &b) {\n\t\tif(i64(a -= b.a) < 0) a += 2 * mod;\n\t\treturn *this;\n\t}\n\n\t\
    modint64 &operator*=(const modint64 &b) {\n\t\ta = reduce(u128(a) * b.a);\n\t\t\
    return *this;\n\t}\n\n\tmodint64 operator+(const modint64 &b) const { return modint64(*this)\
    \ += b; }\n\tmodint64 operator-(const modint64 &b) const { return modint64(*this)\
    \ -= b; }\n\tmodint64 operator*(const modint64 &b) const { return modint64(*this)\
    \ *= b; }\n\n\tmodint64 pow(u128 n) const {\n\t\tmodint64 ret(1), mul(*this);\n\
    \t\twhile(n > 0) {\n\t\t\tif(n & 1) ret *= mul;\n\t\t\tmul *= mul;\n\t\t\tn >>=\
    \ 1;\n\t\t}\n\t\treturn ret;\n\t}\n\n\tu64 val() const {\n\t\tu64 ret = reduce(a);\n\
    \t\treturn ret >= mod ? ret - mod : ret;\n\t}\n\n\tstatic u64 get_mod() { return\
    \ mod; }\n\nprivate:\n\tu64 a;\n\n\tstatic u64 get_r() {\n\t\tu64 ret = mod;\n\
    \t\tfor(u32 i = 0; i < 5; i++) ret *= 2 - mod * ret;\n\t\treturn ret;\n\t}\n\n\
    \tstatic u64 reduce(const u128 &b) {\n\t\treturn (b + u128(u64(b) * u64(-r)) *\
    \ mod) >> 64;\n\t}\n};\ntypename modint64::u64 modint64::mod, modint64::r, modint64::n2;\n\
    \nu64 rnd() {\n\tstatic u64 x = 10150724397891781847ull;\n\tx ^= x << 7;\n\treturn\
    \ x ^= x >> 9;\n}\n\nconstexpr long long safe_mod(long long x, long long m) {\n\
    \tx %= m;\n\tif(x < 0) x += m;\n\treturn x;\n}\n\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n\tif(m == 1) return 0;\n\tunsigned int _m = (unsigned\
    \ int)(m);\n\tunsigned long long r = 1;\n\tunsigned long long y = safe_mod(x,\
    \ m);\n\twhile(n) {\n\t\tif(n & 1) r = (r * y) % _m;\n\t\ty = (y * y) % _m;\n\t\
    \tn >>= 1;\n\t}\n\treturn r;\n}\n\nbool is_prime(const u64 n) {\n\tif(~n & 1)\
    \ return n == 2;\n\tif(n < (1ll << 30)) {\n\t\tif(n <= 1) return false;\n\t\t\
    if(n == 2 || n == 7 || n == 61) return true;\n\t\tif(n % 2 == 0) return false;\n\
    \t\tlong long d = n - 1;\n\t\twhile(d % 2 == 0) d /= 2;\n\t\tconstexpr long long\
    \ bases[3] = {2, 7, 61};\n\t\tfor(long long a : bases) {\n\t\t\tlong long t =\
    \ d;\n\t\t\tlong long y = pow_mod_constexpr(a, t, n);\n\t\t\twhile(t != n - 1\
    \ && y != 1 && y != n - 1) {\n\t\t\t\ty = y * y % n;\n\t\t\t\tt <<= 1;\n\t\t\t\
    }\n\t\t\tif(y != n - 1 && t % 2 == 0) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\
    }\n\t\treturn true;\n\t}\n\tu64 d = n - 1;\n\twhile(~d & 1) d >>= 1;\n\tif(modint64::get_mod()\
    \ != n) modint64::set_mod(n);\n\tfor(const u64 a : {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\n\t\tif(n <= a) break;\n\t\tmodint64 t = d, y = modint64(a).pow(d);\n\
    \t\twhile(t.val() != n - 1 and y.val() != 1 and y.val() != n - 1) {\n\t\t\ty *=\
    \ y;\n\t\t\tt *= 2;\n\t\t}\n\t\tif(y.val() != n - 1 and ~t.val() & 1) return false;\n\
    \t}\n\treturn true;\n}\n\nu64 pollard_rho(const u64 n) {\n\tif(~n & 1) return\
    \ 2;\n\tif(is_prime(n)) return n;\n\tif(modint64::get_mod() != n) modint64::set_mod(n);\n\
    \tmodint64 R, one = 1;\n\tauto f = [&](modint64 x) { return x * x + R; };\n\t\
    auto rng = [&]() { return rnd() % (n - 2) + 2; };\n\tfor(;;) {\n\t\tmodint64 x,\
    \ y(rng()), ys, q = one;\n\t\tR = rng();\n\t\tu64 g = 1;\n\t\tconstexpr u32 m\
    \ = 128;\n\t\tfor(u32 r = 1; g == 1; r <<= 1) {\n\t\t\tx = y;\n\t\t\tfor(u32 i\
    \ = 0; i < r; i++) y = f(y);\n\t\t\tfor(u32 k = 0; g == 1 and k < r; k += m) {\n\
    \t\t\t\tys = y;\n\t\t\t\tfor(u32 i = 0; i < m and i < r - k; i++) q *= x - (y\
    \ = f(y));\n\t\t\t\tg = gcd_fast(q.val(), n);\n\t\t\t}\n\t\t}\n\t\tif(g == n)\
    \ do\n\t\t\t\tg = gcd_fast((x - (ys = f(ys))).val(), n);\n\t\t\twhile(g == 1);\n\
    \t\tif(g != n) return g;\n\t}\n\texit(1);\n}\n\nstd::vector<u64> factorize(const\
    \ u64 n) {\n\tif(n == 1) return {};\n\tif(is_prime(n)) return {n};\n\tauto d =\
    \ pollard_rho(n);\n\tauto res = factorize(d);\n\tauto sub = factorize(n / d);\n\
    \tstd::copy(sub.begin(), sub.end(), std::back_inserter(res));\n\treturn res;\n\
    }\n\n};  // namespace inner\nusing inner::is_prime;\n\ntemplate <typename T>\n\
    std::vector<T> factorize(const T n) {\n\tauto tmp = inner::factorize(n);\n\tstd::vector<T>\
    \ res{tmp.begin(), tmp.end()};\n\tstd::sort(res.begin(), res.end());\n\treturn\
    \ res;\n}\n\ntemplate <typename T>\nstd::vector<std::pair<T, int>> pair_factorize(const\
    \ T n) {\n\tstd::vector<std::pair<T, int>> res;\n\tauto tmp = factorize(n);\n\t\
    if(tmp.empty()) return {};\n\tT now = tmp.front();\n\tint cnt = 0;\n\tfor(auto\
    \ &v : tmp) {\n\t\tif(now == v)\n\t\t\tcnt++;\n\t\telse {\n\t\t\tres.emplace_back(now,\
    \ cnt);\n\t\t\tnow = v;\n\t\t\tcnt = 1;\n\t\t}\n\t}\n\tres.emplace_back(now, cnt);\n\
    \treturn res;\n}\n"
  code: "#include <bits/stdc++.h>\n\n#include <atcoder/modint>\n\nnamespace inner\
    \ {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i64 = int64_t;\nusing\
    \ u128 = __uint128_t;\n\nu64 gcd_impl(u64 n, u64 m) {\n\tconstexpr u64 K = 5;\n\
    \tfor(u32 i = 0; i < 80; ++i) {\n\t\tu64 t = n - m;\n\t\tu64 s = n - m * K;\n\t\
    \tbool q = t < m;\n\t\tbool p = t < m * K;\n\t\tn = q ? m : t;\n\t\tm = q ? t\
    \ : m;\n\t\tif(m == 0) return n;\n\t\tn = p ? n : s;\n\t}\n\treturn gcd_impl(m,\
    \ n % m);\n}\n\nu64 gcd_pre(u64 n, u64 m) {\n\tfor(u32 i = 0; i < 4; ++i) {\n\t\
    \tu64 t = n - m;\n\t\tbool q = t < m;\n\t\tn = q ? m : t;\n\t\tm = q ? t : m;\n\
    \t\tif(m == 0) return n;\n\t}\n\treturn gcd_impl(n, m);\n}\n\nu64 gcd_fast(u64\
    \ n, u64 m) { return n > m ? gcd_pre(n, m) : gcd_pre(m, n); }\n\nstruct modint64\
    \ {\n\tusing u64 = uint64_t;\n\npublic:\n\tstatic u64 mod;\n\tstatic u64 r, n2;\n\
    \tstatic void set_mod(u64 m) {\n\t\tmod = m;\n\t\tn2 = -u128(m) % m;\n\t\tr =\
    \ get_r();\n\t\tassert(r * mod == 1);\n\t}\n\tmodint64() : a(0) {}\n\tmodint64(const\
    \ i64 &b) : a(reduce((u128(b) + mod) * n2)) {}\n\n\tmodint64 &operator+=(const\
    \ modint64 &b) {\n\t\tif(i64(a += b.a - 2 * mod) < 0) a += 2 * mod;\n\t\treturn\
    \ *this;\n\t}\n\n\tmodint64 &operator-=(const modint64 &b) {\n\t\tif(i64(a -=\
    \ b.a) < 0) a += 2 * mod;\n\t\treturn *this;\n\t}\n\n\tmodint64 &operator*=(const\
    \ modint64 &b) {\n\t\ta = reduce(u128(a) * b.a);\n\t\treturn *this;\n\t}\n\n\t\
    modint64 operator+(const modint64 &b) const { return modint64(*this) += b; }\n\
    \tmodint64 operator-(const modint64 &b) const { return modint64(*this) -= b; }\n\
    \tmodint64 operator*(const modint64 &b) const { return modint64(*this) *= b; }\n\
    \n\tmodint64 pow(u128 n) const {\n\t\tmodint64 ret(1), mul(*this);\n\t\twhile(n\
    \ > 0) {\n\t\t\tif(n & 1) ret *= mul;\n\t\t\tmul *= mul;\n\t\t\tn >>= 1;\n\t\t\
    }\n\t\treturn ret;\n\t}\n\n\tu64 val() const {\n\t\tu64 ret = reduce(a);\n\t\t\
    return ret >= mod ? ret - mod : ret;\n\t}\n\n\tstatic u64 get_mod() { return mod;\
    \ }\n\nprivate:\n\tu64 a;\n\n\tstatic u64 get_r() {\n\t\tu64 ret = mod;\n\t\t\
    for(u32 i = 0; i < 5; i++) ret *= 2 - mod * ret;\n\t\treturn ret;\n\t}\n\n\tstatic\
    \ u64 reduce(const u128 &b) {\n\t\treturn (b + u128(u64(b) * u64(-r)) * mod) >>\
    \ 64;\n\t}\n};\ntypename modint64::u64 modint64::mod, modint64::r, modint64::n2;\n\
    \nu64 rnd() {\n\tstatic u64 x = 10150724397891781847ull;\n\tx ^= x << 7;\n\treturn\
    \ x ^= x >> 9;\n}\n\nconstexpr long long safe_mod(long long x, long long m) {\n\
    \tx %= m;\n\tif(x < 0) x += m;\n\treturn x;\n}\n\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n\tif(m == 1) return 0;\n\tunsigned int _m = (unsigned\
    \ int)(m);\n\tunsigned long long r = 1;\n\tunsigned long long y = safe_mod(x,\
    \ m);\n\twhile(n) {\n\t\tif(n & 1) r = (r * y) % _m;\n\t\ty = (y * y) % _m;\n\t\
    \tn >>= 1;\n\t}\n\treturn r;\n}\n\nbool is_prime(const u64 n) {\n\tif(~n & 1)\
    \ return n == 2;\n\tif(n < (1ll << 30)) {\n\t\tif(n <= 1) return false;\n\t\t\
    if(n == 2 || n == 7 || n == 61) return true;\n\t\tif(n % 2 == 0) return false;\n\
    \t\tlong long d = n - 1;\n\t\twhile(d % 2 == 0) d /= 2;\n\t\tconstexpr long long\
    \ bases[3] = {2, 7, 61};\n\t\tfor(long long a : bases) {\n\t\t\tlong long t =\
    \ d;\n\t\t\tlong long y = pow_mod_constexpr(a, t, n);\n\t\t\twhile(t != n - 1\
    \ && y != 1 && y != n - 1) {\n\t\t\t\ty = y * y % n;\n\t\t\t\tt <<= 1;\n\t\t\t\
    }\n\t\t\tif(y != n - 1 && t % 2 == 0) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\
    }\n\t\treturn true;\n\t}\n\tu64 d = n - 1;\n\twhile(~d & 1) d >>= 1;\n\tif(modint64::get_mod()\
    \ != n) modint64::set_mod(n);\n\tfor(const u64 a : {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\n\t\tif(n <= a) break;\n\t\tmodint64 t = d, y = modint64(a).pow(d);\n\
    \t\twhile(t.val() != n - 1 and y.val() != 1 and y.val() != n - 1) {\n\t\t\ty *=\
    \ y;\n\t\t\tt *= 2;\n\t\t}\n\t\tif(y.val() != n - 1 and ~t.val() & 1) return false;\n\
    \t}\n\treturn true;\n}\n\nu64 pollard_rho(const u64 n) {\n\tif(~n & 1) return\
    \ 2;\n\tif(is_prime(n)) return n;\n\tif(modint64::get_mod() != n) modint64::set_mod(n);\n\
    \tmodint64 R, one = 1;\n\tauto f = [&](modint64 x) { return x * x + R; };\n\t\
    auto rng = [&]() { return rnd() % (n - 2) + 2; };\n\tfor(;;) {\n\t\tmodint64 x,\
    \ y(rng()), ys, q = one;\n\t\tR = rng();\n\t\tu64 g = 1;\n\t\tconstexpr u32 m\
    \ = 128;\n\t\tfor(u32 r = 1; g == 1; r <<= 1) {\n\t\t\tx = y;\n\t\t\tfor(u32 i\
    \ = 0; i < r; i++) y = f(y);\n\t\t\tfor(u32 k = 0; g == 1 and k < r; k += m) {\n\
    \t\t\t\tys = y;\n\t\t\t\tfor(u32 i = 0; i < m and i < r - k; i++) q *= x - (y\
    \ = f(y));\n\t\t\t\tg = gcd_fast(q.val(), n);\n\t\t\t}\n\t\t}\n\t\tif(g == n)\
    \ do\n\t\t\t\tg = gcd_fast((x - (ys = f(ys))).val(), n);\n\t\t\twhile(g == 1);\n\
    \t\tif(g != n) return g;\n\t}\n\texit(1);\n}\n\nstd::vector<u64> factorize(const\
    \ u64 n) {\n\tif(n == 1) return {};\n\tif(is_prime(n)) return {n};\n\tauto d =\
    \ pollard_rho(n);\n\tauto res = factorize(d);\n\tauto sub = factorize(n / d);\n\
    \tstd::copy(sub.begin(), sub.end(), std::back_inserter(res));\n\treturn res;\n\
    }\n\n};  // namespace inner\nusing inner::is_prime;\n\ntemplate <typename T>\n\
    std::vector<T> factorize(const T n) {\n\tauto tmp = inner::factorize(n);\n\tstd::vector<T>\
    \ res{tmp.begin(), tmp.end()};\n\tstd::sort(res.begin(), res.end());\n\treturn\
    \ res;\n}\n\ntemplate <typename T>\nstd::vector<std::pair<T, int>> pair_factorize(const\
    \ T n) {\n\tstd::vector<std::pair<T, int>> res;\n\tauto tmp = factorize(n);\n\t\
    if(tmp.empty()) return {};\n\tT now = tmp.front();\n\tint cnt = 0;\n\tfor(auto\
    \ &v : tmp) {\n\t\tif(now == v)\n\t\t\tcnt++;\n\t\telse {\n\t\t\tres.emplace_back(now,\
    \ cnt);\n\t\t\tnow = v;\n\t\t\tcnt = 1;\n\t\t}\n\t}\n\tres.emplace_back(now, cnt);\n\
    \treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/factorize.hpp
  requiredBy: []
  timestamp: '2021-09-07 20:08:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factorize.hpp
layout: document
redirect_from:
- /library/math/factorize.hpp
- /library/math/factorize.hpp.html
title: math/factorize.hpp
---
