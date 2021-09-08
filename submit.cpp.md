---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cftemp.hpp
    title: cftemp.hpp
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Barrett_reduction
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397&lang=jp
  bundledCode: "#line 1 \"submit.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397&lang=jp\"\
    \n\n\n#include <cassert>\n#include <numeric>\n#include <type_traits>\n\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\n\n\n#include <utility>\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long long\
    \ x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n\
    // Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m < 2^31`\n    explicit barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n    \
    \    // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0\
    \ <= c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64\
    \ + c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned int v = (unsigned int)(z - x * _m);\n        if (_m <=\
    \ v) v += _m;\n        return v;\n    }\n};\n\n// @param n `0 <= n`\n// @param\
    \ m `1 <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `n < 2^32`\n// @param m `1 <=\
    \ m < 2^32`\n// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)\nunsigned\
    \ long long floor_sum_unsigned(unsigned long long n,\n                       \
    \               unsigned long long m,\n                                      unsigned\
    \ long long a,\n                                      unsigned long long b) {\n\
    \    unsigned long long ans = 0;\n    while (true) {\n        if (a >= m) {\n\
    \            ans += n * (n - 1) / 2 * (a / m);\n            a %= m;\n        }\n\
    \        if (b >= m) {\n            ans += n * (b / m);\n            b %= m;\n\
    \        }\n\n        unsigned long long y_max = a * n + b;\n        if (y_max\
    \ < m) break;\n        // y_max < m * (n + 1)\n        // floor(y_max / m) <=\
    \ n\n        n = (unsigned long long)(y_max / m);\n        b = (unsigned long\
    \ long)(y_max % m);\n        std::swap(m, a);\n    }\n    return ans;\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 226 \"submit.cpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate\
    \ <class T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value ||\n      \
    \                            std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\n\ntemplate <class T>\nusing is_integral\
    \ = typename std::conditional<std::is_integral<T>::value ||\n                \
    \                                  is_signed_int128<T>::value ||\n           \
    \                                       is_unsigned_int128<T>::value,\n      \
    \                                        std::true_type,\n                   \
    \                           std::false_type>::type;\n\ntemplate <class T>\nusing\
    \ is_signed_int = typename std::conditional<(is_integral<T>::value &&\n      \
    \                                           std::is_signed<T>::value) ||\n   \
    \                                                 is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\nnamespace atcoder {\n\
    \nnamespace internal {\n\nstruct modint_base {};\nstruct static_modint_base :\
    \ modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : internal::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if\
    \ (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : internal::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n   \
    \     long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x\
    \ += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n \
    \ private:\n    unsigned int _v;\n    static internal::barrett bt;\n    static\
    \ unsigned int umod() { return bt.umod(); }\n};\ntemplate <int id> internal::barrett\
    \ dynamic_modint<id>::bt(998244353);\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"cftemp.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#pragma region Macros\n//\
    \ rep macro\n#define foa(v, a) for(auto &v : a)\n#define REPname(a, b, c, d, e,\
    \ ...) e\n#define REP(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)\n\
    #define REP0(x) for(int i = 0; i < (x); ++i)\n#define REP1(i, x) for(int i = 0;\
    \ i < (x); ++i)\n#define REP2(i, l, r) for(int i = (l); i < (r); ++i)\n#define\
    \ REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))\n#define REPSname(a, b,\
    \ c, ...) c\n#define REPS(...) REPSname(__VA_ARGS__, REPS1, REPS0)(__VA_ARGS__)\n\
    #define REPS0(x) for(int i = 1; i <= (x); ++i)\n#define REPS1(i, x) for(int i\
    \ = 1; i <= (x); ++i)\n#define RREPname(a, b, c, d, e, ...) e\n#define RREP(...)\
    \ RREPname(__VA_ARGS__, RREP3, RREP2, RREP1, RREP0)(__VA_ARGS__)\n#define RREP0(x)\
    \ for(int i = (x)-1; i >= 0; --i)\n#define RREP1(i, x) for(int i = (x)-1; i >=\
    \ 0; --i)\n#define RREP2(i, r, l) for(int i = (r)-1; i >= (l); --i)\n#define RREP3(i,\
    \ r, l, c) for(int i = (r)-1; i >= (l); i -= (c))\n#define RREPSname(a, b, c,\
    \ ...) c\n#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS__)\n\
    #define RREPS0(x) for(int i = (x); i >= 1; --i)\n#define RREPS1(i, x) for(int\
    \ i = (x); i >= 1; --i)\n\n// name macro\n#define pb push_back\n#define eb emplace_back\n\
    #define SZ(x) ((int)(x).size())\n#define all(x) (x).begin(), (x).end()\n#define\
    \ rall(x) (x).rbegin(), (x).rend()\n#define popcnt(x) __builtin_popcountll(x)\n\
    template <class T = int>\nusing V = std::vector<T>;\ntemplate <class T = int>\n\
    using VV = std::vector<std::vector<T>>;\ntemplate <class T>\nusing pqup = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\nusing ll = long long;\nusing ld = long double;\n\
    using int128 = __int128_t;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<long\
    \ long, long long>;\n\n// input macro\ntemplate <class T, class U>\nstd::istream\
    \ &operator>>(std::istream &is, std::pair<T, U> &p) {\n\tis >> p.first >> p.second;\n\
    \treturn is;\n}\ntemplate <class T>\nstd::istream &operator>>(std::istream &is,\
    \ std::vector<T> &v) {\n\tfor(T &i : v) is >> i;\n\treturn is;\n}\nstd::istream\
    \ &operator>>(std::istream &is, __int128_t &a) {\n\tstd::string s;\n\tis >> s;\n\
    \t__int128_t ret = 0;\n\tfor(int i = 0; i < s.length(); i++)\n\t\tif('0' <= s[i]\
    \ and s[i] <= '9')\n\t\t\tret = 10 * ret + s[i] - '0';\n\ta = ret * (s[0] == '-'\
    \ ? -1 : 1);\n\treturn is;\n}\nnamespace scanner {\nvoid scan(int &a) { std::cin\
    \ >> a; }\nvoid scan(long long &a) { std::cin >> a; }\nvoid scan(std::string &a)\
    \ { std::cin >> a; }\nvoid scan(char &a) { std::cin >> a; }\nvoid scan(char a[])\
    \ { std::scanf(\"%s\", a); }\nvoid scan(double &a) { std::cin >> a; }\nvoid scan(long\
    \ double &a) { std::cin >> a; }\ntemplate <class T, class U>\nvoid scan(std::pair<T,\
    \ U> &p) { std::cin >> p; }\ntemplate <class T>\nvoid scan(std::vector<T> &a)\
    \ { std::cin >> a; }\nvoid INPUT() {}\ntemplate <class Head, class... Tail>\n\
    void INPUT(Head &head, Tail &... tail) {\n\tscan(head);\n\tINPUT(tail...);\n}\n\
    }  // namespace scanner\n#define VEC(type, name, size)     \\\n\tstd::vector<type>\
    \ name(size); \\\n\tscanner::INPUT(name)\n#define VVEC(type, name, h, w)     \
    \                               \\\n\tstd::vector<std::vector<type>> name(h, std::vector<type>(w));\
    \ \\\n\tscanner::INPUT(name)\n#define INT(...)     \\\n\tint __VA_ARGS__; \\\n\
    \tscanner::INPUT(__VA_ARGS__)\n#define LL(...)            \\\n\tlong long __VA_ARGS__;\
    \ \\\n\tscanner::INPUT(__VA_ARGS__)\n#define STR(...)             \\\n\tstd::string\
    \ __VA_ARGS__; \\\n\tscanner::INPUT(__VA_ARGS__)\n#define CHAR(...)     \\\n\t\
    char __VA_ARGS__; \\\n\tscanner::INPUT(__VA_ARGS__)\n#define DOUBLE(...)     \\\
    \n\tdouble __VA_ARGS__; \\\n\tscanner::INPUT(__VA_ARGS__)\n#define LD(...)   \
    \           \\\n\tlong double __VA_ARGS__; \\\n\tscanner::INPUT(__VA_ARGS__)\n\
    \n// output-macro\ntemplate <class T, class U>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T, U> &p) {\n\tos << p.first << \" \" << p.second;\n\t\
    return os;\n}\ntemplate <class T>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::vector<T> &a) {\n\tfor(int i = 0; i < int(a.size()); ++i) {\n\t\t\
    if(i) os << \" \";\n\t\tos << a[i];\n\t}\n\treturn os;\n}\nstd::ostream &operator<<(std::ostream\
    \ &dest, __int128_t &value) {\n\tstd::ostream::sentry s(dest);\n\tif(s) {\n\t\t\
    __uint128_t tmp = value < 0 ? -value : value;\n\t\tchar buffer[128];\n\t\tchar\
    \ *d = std::end(buffer);\n\t\tdo {\n\t\t\t--d;\n\t\t\t*d = \"0123456789\"[tmp\
    \ % 10];\n\t\t\ttmp /= 10;\n\t\t} while(tmp != 0);\n\t\tif(value < 0) {\n\t\t\t\
    --d;\n\t\t\t*d = '-';\n\t\t}\n\t\tint len = std::end(buffer) - d;\n\t\tif(dest.rdbuf()->sputn(d,\
    \ len) != len) {\n\t\t\tdest.setstate(std::ios_base::badbit);\n\t\t}\n\t}\n\t\
    return dest;\n}\ntemplate <class T>\nvoid print(const T a) { std::cout << a <<\
    \ '\\n'; }\ntemplate <class Head, class... Tail>\nvoid print(Head H, Tail... T)\
    \ {\n\tstd::cout << H << ' ';\n\tprint(T...);\n}\ntemplate <class T>\nvoid printel(const\
    \ T a) { std::cout << a << '\\n'; }\ntemplate <class T>\nvoid printel(const std::vector<T>\
    \ &a) {\n\tfor(const auto &v : a)\n\t\tstd::cout << v << '\\n';\n}\ntemplate <class\
    \ Head, class... Tail>\nvoid printel(Head H, Tail... T) {\n\tstd::cout << H <<\
    \ '\\n';\n\tprintel(T...);\n}\nvoid Yes(const bool b = true) { std::cout << (b\
    \ ? \"Yes\\n\" : \"No\\n\"); }\nvoid No() { std::cout << \"No\\n\"; }\nvoid YES(const\
    \ bool b = true) { std::cout << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO() { std::cout\
    \ << \"NO\\n\"; }\nvoid err(const bool b = true) {\n\tif(b) {\n\t\tstd::cout <<\
    \ \"-1\\n\", exit(0);\n\t}\n}\n\n//debug macro\nnamespace debugger {\ntemplate\
    \ <class T>\nvoid view(const std::vector<T> &a) {\n\tstd::cerr << \"{ \";\n\t\
    for(const auto &v : a) {\n\t\tstd::cerr << v << \", \";\n\t}\n\tstd::cerr << \"\
    \\b\\b }\";\n}\ntemplate <class T>\nvoid view(const std::vector<std::vector<T>>\
    \ &a) {\n\tstd::cerr << \"{\\n\";\n\tfor(const auto &v : a) {\n\t\tstd::cerr <<\
    \ \"\\t\";\n\t\tview(v);\n\t\tstd::cerr << \"\\n\";\n\t}\n\tstd::cerr << \"}\"\
    ;\n}\ntemplate <class T, class U>\nvoid view(const std::vector<std::pair<T, U>>\
    \ &a) {\n\tstd::cerr << \"{\\n\";\n\tfor(const auto &p : a) std::cerr << \"\\\
    t(\" << p.first << \", \" << p.second << \")\\n\";\n\tstd::cerr << \"}\";\n}\n\
    template <class T, class U>\nvoid view(const std::map<T, U> &m) {\n\tstd::cerr\
    \ << \"{\\n\";\n\tfor(const auto &p : m) std::cerr << \"\\t[\" << p.first << \"\
    ] : \" << p.second << \"\\n\";\n\tstd::cerr << \"}\";\n}\ntemplate <class T, class\
    \ U>\nvoid view(const std::pair<T, U> &p) { std::cerr << \"(\" << p.first << \"\
    , \" << p.second << \")\"; }\ntemplate <class T>\nvoid view(const std::set<T>\
    \ &s) {\n\tstd::cerr << \"{ \";\n\tfor(auto &v : s) {\n\t\tview(v);\n\t\tstd::cerr\
    \ << \", \";\n\t}\n\tstd::cerr << \"\\b\\b }\";\n}\n\ntemplate <class T>\nvoid\
    \ view(const T &e) { std::cerr << e; }\n}  // namespace debugger\n#ifdef LOCAL\n\
    void debug_out() {}\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n\tdebugger::view(H);\n\tstd::cerr << \", \";\n\tdebug_out(T...);\n\
    }\n#define debug(...)                                                \\\n\tdo\
    \ {                                                          \\\n\t\tstd::cerr\
    \ << __LINE__ << \" [\" << #__VA_ARGS__ << \"] : [\"; \\\n\t\tdebug_out(__VA_ARGS__);\
    \                                   \\\n\t\tstd::cerr << \"\\b\\b]\\n\";     \
    \                              \\\n\t} while(false)\n#else\n#define debug(...)\
    \ (void(0))\n#endif\n\n// vector macro\ntemplate <class T>\nint lb(const std::vector<T>\
    \ &a, const T x) { return std::distance((a).begin(), std::lower_bound((a).begin(),\
    \ (a).end(), (x))); }\ntemplate <class T>\nint ub(const std::vector<T> &a, const\
    \ T x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(),\
    \ (x))); }\ntemplate <class T>\nvoid UNIQUE(std::vector<T> &a) {\n\tstd::sort(a.begin(),\
    \ a.end());\n\ta.erase(std::unique(a.begin(), a.end()), a.end());\n}\ntemplate\
    \ <class T>\nstd::vector<T> press(std::vector<T> &a) {\n\tauto res = a;\n\tUNIQUE(res);\n\
    \tfor(auto &v : a)\n\t\tv = lb(res, v);\n\treturn res;\n}\n#define SORTname(a,\
    \ b, c, ...) c\n#define SORT(...) SORTname(__VA_ARGS__, SORT1, SORT0, ...)(__VA_ARGS__)\n\
    #define SORT0(a) std::sort((a).begin(), (a).end())\n#define SORT1(a, c) std::sort((a).begin(),\
    \ (a).end(), [](const auto x, const auto y) { return x c y; })\ntemplate <class\
    \ T>\nvoid ADD(std::vector<T> &a, const T x = 1) {\n\tfor(auto &v : a) v += x;\n\
    }\ntemplate <class T>\nvoid SUB(std::vector<T> &a, const T x = 1) {\n\tfor(auto\
    \ &v : a) v -= x;\n}\ntemplate <class T>\nvoid MUL(std::vector<T> &a, const T\
    \ x) {\n\tfor(auto &v : a) v *= x;\n}\ntemplate <class T>\nvoid DIV(std::vector<T>\
    \ &a, const T x) {\n\tfor(auto &v : a) v /= x;\n}\nstd::vector<std::pair<char,\
    \ int>> rle(const string &s) {\n\tint n = s.size();\n\tstd::vector<std::pair<char,\
    \ int>> ret;\n\tfor(int l = 0; l < n;) {\n\t\tint r = l + 1;\n\t\tfor(; r < n\
    \ and s[l] == s[r]; r++) {}\n\t\tret.emplace_back(s[l], r - l);\n\t\tl = r;\n\t\
    }\n\treturn ret;\n}\ntemplate <class T>\nstd::vector<std::pair<T, int>> rle(const\
    \ std::vector<T> &v) {\n\tint n = v.size();\n\tstd::vector<std::pair<T, int>>\
    \ ret;\n\tfor(int l = 0; l < n;) {\n\t\tint r = l + 1;\n\t\tfor(; r < n and v[l]\
    \ == v[r]; r++) {}\n\t\tret.emplace_back(v[l], r - l);\n\t\tl = r;\n\t}\n\treturn\
    \ ret;\n}\n\n// math macro\ntemplate <class T, class U>\ninline bool chmin(T &a,\
    \ const U &b) { return a > b ? a = b, true : false; }\ntemplate <class T, class\
    \ U>\ninline bool chmax(T &a, const U &b) { return a < b ? a = b, true : false;\
    \ }\ntemplate <class T>\nT divup(T x, T y) { return (x + y - 1) / y; }\ntemplate\
    \ <class T>\nT POW(T a, long long n) {\n\tT ret = 1;\n\twhile(n) {\n\t\tif(n &\
    \ 1) ret *= a;\n\t\ta *= a;\n\t\tn >>= 1;\n\t}\n\treturn ret;\n}\n// modpow\n\
    long long POW(long long a, long long n, const int mod) {\n\tlong long ret = 1;\n\
    \ta = (a % mod + mod) % mod;\n\twhile(n) {\n\t\tif(n & 1) (ret *= a) %= mod;\n\
    \t\t(a *= a) %= mod;\n\t\tn >>= 1;\n\t}\n\treturn ret;\n}\n\n// others\nstruct\
    \ fast_io {\n\tfast_io() {\n\t\tios::sync_with_stdio(false);\n\t\tcin.tie(nullptr);\n\
    \t\tcout << fixed << setprecision(15);\n\t}\n} fast_io_;\nconst int inf = 1e9;\n\
    const ll INF = 1e18;\n#pragma endregion\n\nvoid main_();\n\nint main() {\n\tmain_();\n\
    \treturn 0;\n}\n#line 5 \"math/matrix.hpp\"\n\ntemplate <class T>\nstruct matrix\
    \ {\nprivate:\n\tstd::vector<std::vector<T>> A;\n\n\tstatic matrix I(size_t n)\
    \ {\n\t\tmatrix mat(n);\n\t\tfor(int i = 0; i < n; i++) mat[i][i] = 1;\n\t\treturn\
    \ mat;\n\t}\n\npublic:\n\tmatrix() = default;\n\n\tmatrix(std::vector<std::vector<T>>\
    \ &vvec) { A = vvec; }\n\n\tmatrix(size_t n, size_t m) : A(n, std::vector<T>(m,\
    \ 0)) {}\n\n\tmatrix(size_t n, size_t m, T init) : A(n, std::vector<T>(m, init))\
    \ {}\n\n\tmatrix(size_t n, std::vector<T> &vec) : A(n, vec) {}\n\n\tmatrix(size_t\
    \ n) : A(n, std::vector<T>(n, 0)) {}\n\n\tsize_t height() const { return A.size();\
    \ }\n\n\tsize_t width() const { return A[0].size(); }\n\n\tinline const std::vector<T>\
    \ &operator[](int k) const {\n\t\treturn A[k];\n\t}\n\n\tinline std::vector<T>\
    \ &operator[](int k) {\n\t\treturn A[k];\n\t}\n\n\tmatrix &operator+=(const matrix\
    \ &B) {\n\t\tsize_t n = height(), m = width();\n\t\tassert(n == B.height() and\
    \ m == B.width());\n\t\tfor(int i = 0; i < n; i++)\n\t\t\tfor(int j = 0; j < m;\
    \ j++)\n\t\t\t\t(*this)[i][j] += B[i][j];\n\t\treturn *this;\n\t}\n\n\tmatrix\
    \ &operator-=(const matrix &B) {\n\t\tsize_t n = height(), m = width();\n\t\t\
    assert(n == B.height() and m == B.width());\n\t\tfor(int i = 0; i < n; i++)\n\t\
    \t\tfor(int j = 0; j < m; j++)\n\t\t\t\t(*this)[i][j] -= B[i][j];\n\t\treturn\
    \ *this;\n\t}\n\n\tmatrix &operator*=(const matrix &B) {\n\t\tsize_t n = height(),\
    \ m = B.width(), p = width();\n\t\tassert(p == B.height());\n\t\tstd::vector<std::vector<T>>\
    \ C(n, std::vector<T>(m, 0));\n\t\tfor(int i = 0; i < n; i++)\n\t\t\tfor(int j\
    \ = 0; j < m; j++)\n\t\t\t\tfor(int k = 0; k < p; k++)\n\t\t\t\t\tC[i][j] += (*this)[i][k]\
    \ * B[k][j];\n\t\tA.swap(C);\n\t\treturn *this;\n\t}\n\n\tmatrix &operator^=(long\
    \ long k) {\n\t\tmatrix B = matrix::I(height());\n\t\twhile(k > 0) {\n\t\t\tif(k\
    \ & 1) B *= (*this);\n\t\t\t*this *= *this;\n\t\t\tk >>= 1ll;\n\t\t}\n\t\tA.swap(B.A);\n\
    \t\treturn *this;\n\t}\n\n\tbool operator==(const matrix &B) {\n\t\tsize_t n =\
    \ height(), m = width();\n\t\tif(n != B.height() or m != B.width()) return false;\n\
    \t\tfor(int i = 0; i < n; i++)\n\t\t\tfor(int j = 0; j < m; j++)\n\t\t\t\tif((*this)[i][j]\
    \ != B[i][j]) return false;\n\t\treturn true;\n\t}\n\n\tmatrix operator+(const\
    \ matrix &B) const {\n\t\treturn (matrix(*this) += B);\n\t}\n\n\tmatrix operator-(const\
    \ matrix &B) const {\n\t\treturn (matrix(*this) -= B);\n\t}\n\n\tmatrix operator*(const\
    \ matrix &B) const {\n\t\treturn (matrix(*this) *= B);\n\t}\n\n\tmatrix operator^(const\
    \ long long &k) const {\n\t\treturn (matrix(*this) ^= k);\n\t}\n\n\tmatrix &operator+=(const\
    \ T &t) {\n\t\tint n = height(), m = width();\n\t\tfor(int i = 0; i < n; i++)\n\
    \t\t\tfor(int j = 0; j < m; j++)\n\t\t\t\t(*this)[i][j] += t;\n\t\treturn *this;\n\
    \t}\n\n\tmatrix &operator-=(const T &t) {\n\t\tint n = height(), m = width();\n\
    \t\tfor(int i = 0; i < n; i++)\n\t\t\tfor(int j = 0; j < m; j++)\n\t\t\t\t(*this)[i][j]\
    \ -= t;\n\t\treturn *this;\n\t}\n\n\tmatrix &operator*=(const T &t) {\n\t\tint\
    \ n = height(), m = width();\n\t\tfor(int i = 0; i < n; i++)\n\t\t\tfor(int j\
    \ = 0; j < m; j++)\n\t\t\t\t(*this)[i][j] *= t;\n\t\treturn *this;\n\t}\n\n\t\
    matrix &operator/=(const T &t) {\n\t\tint n = height(), m = width();\n\t\tfor(int\
    \ i = 0; i < n; i++)\n\t\t\tfor(int j = 0; j < m; j++)\n\t\t\t\t(*this)[i][j]\
    \ /= t;\n\t\treturn *this;\n\t}\n\n\tmatrix operator+(const T &t) const {\n\t\t\
    return (matrix(*this) += t);\n\t}\n\n\tmatrix operator-(const T &t) const {\n\t\
    \treturn (matrix(*this) -= t);\n\t}\n\n\tmatrix operator*(const T &t) const {\n\
    \t\treturn (matrix(*this) *= t);\n\t}\n\n\tmatrix operator/(const T &t) const\
    \ {\n\t\treturn (matrix(*this) /= t);\n\t}\n\n\tfriend std::ostream &operator<<(std::ostream\
    \ &os, matrix &p) {\n\t\tsize_t n = p.height(), m = p.width();\n\t\tfor(int i\
    \ = 0; i < n; i++) {\n\t\t\tos << '[';\n\t\t\tfor(int j = 0; j < m; j++)\n\t\t\
    \t\tos << p[i][j] << (j == m - 1 ? \"]\\n\" : \",\");\n\t\t}\n\t\treturn (os);\n\
    \t}\n\n\tT determinant() {\n\t\tmatrix B(*this);\n\t\tsize_t n = height(), m =\
    \ width();\n\t\tassert(n == m);\n\t\tT ret = 1;\n\t\tfor(int i = 0; i < n; i++)\
    \ {\n\t\t\tint idx = -1;\n\t\t\tfor(int j = i; j < n; j++)\n\t\t\t\tif(B[j][i]\
    \ != 0) idx = j;\n\t\t\tif(idx == -1) return 0;\n\t\t\tif(i != idx) {\n\t\t\t\t\
    ret *= -1;\n\t\t\t\tswap(B[i], B[idx]);\n\t\t\t}\n\t\t\tret *= B[i][i];\n\t\t\t\
    T vv = B[i][i];\n\t\t\tfor(int j = 0; j < n; j++) B[i][j] /= vv;\n\t\t\tfor(int\
    \ j = i + 1; j < n; j++) {\n\t\t\t\tT a = B[j][i];\n\t\t\t\tfor(int k = 0; k <\
    \ n; k++) {\n\t\t\t\t\tB[j][k] -= B[i][k] * a;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    return ret;\n\t}\n};\n#line 582 \"submit.cpp\"\n\nusing mint = atcoder::static_modint<1000000009>;\n\
    mint res;\nint c = 1;\nvoid main_() {\n\twhile(true) {\n\t\tINT(w);\n\t\tLL(h);\n\
    \t\tINT(n);\n\t\tif(w == 0) return;\n\t\tmatrix<mint> dp(1, w);\n\t\tdp[0][0]\
    \ = 1;\n\t\tmatrix<mint> mul(w, w);\n\t\tREP(i, w) {\n\t\t\tREP(j, max(i - 1,\
    \ 0), min(i + 2, w)) {\n\t\t\t\tmul[i][j] = 1;\n\t\t\t}\n\t\t}\n\t\tmap<ll, V<>>\
    \ mp;\n\t\tREP(i, n) {\n\t\t\tLL(x, y);\n\t\t\t--x, --y;\n\t\t\tif(!y) continue;\n\
    \t\t\tmp[y].pb(x);\n\t\t}\n\t\tmp[h - 1].pb(w);\n\t\tll bef = 0;\n\t\tfor(auto\
    \ [val, vec] : mp) {\n\t\t\tdp *= mul ^ (val - bef);\n\t\t\tfoa(v, vec) {\n\t\t\
    \t\tif(v < w)\n\t\t\t\t\tdp[0][v] = 0;\n\t\t\t\telse {\n\t\t\t\t\tcout << \"Case\
    \ \" << c++ << \": \";\n\t\t\t\t\tprint(dp[0].back().val());\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\tbef = val;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397&lang=jp\"\
    \n\n\n#include <cassert>\n#include <numeric>\n#include <type_traits>\n\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\n\n\n#include <utility>\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long long\
    \ x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n\
    // Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m < 2^31`\n    explicit barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n    \
    \    // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0\
    \ <= c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64\
    \ + c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned int v = (unsigned int)(z - x * _m);\n        if (_m <=\
    \ v) v += _m;\n        return v;\n    }\n};\n\n// @param n `0 <= n`\n// @param\
    \ m `1 <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `n < 2^32`\n// @param m `1 <=\
    \ m < 2^32`\n// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)\nunsigned\
    \ long long floor_sum_unsigned(unsigned long long n,\n                       \
    \               unsigned long long m,\n                                      unsigned\
    \ long long a,\n                                      unsigned long long b) {\n\
    \    unsigned long long ans = 0;\n    while (true) {\n        if (a >= m) {\n\
    \            ans += n * (n - 1) / 2 * (a / m);\n            a %= m;\n        }\n\
    \        if (b >= m) {\n            ans += n * (b / m);\n            b %= m;\n\
    \        }\n\n        unsigned long long y_max = a * n + b;\n        if (y_max\
    \ < m) break;\n        // y_max < m * (n + 1)\n        // floor(y_max / m) <=\
    \ n\n        n = (unsigned long long)(y_max / m);\n        b = (unsigned long\
    \ long)(y_max % m);\n        std::swap(m, a);\n    }\n    return ans;\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#include <cassert>\n\
    #include <numeric>\n#include <type_traits>\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128 =\n\
    \    typename std::conditional<std::is_same<T, __int128_t>::value ||\n       \
    \                           std::is_same<T, __int128>::value,\n              \
    \                std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\nnamespace atcoder {\n\
    \nnamespace internal {\n\nstruct modint_base {};\nstruct static_modint_base :\
    \ modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : internal::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if\
    \ (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : internal::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n   \
    \     long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x\
    \ += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n \
    \ private:\n    unsigned int _v;\n    static internal::barrett bt;\n    static\
    \ unsigned int umod() { return bt.umod(); }\n};\ntemplate <int id> internal::barrett\
    \ dynamic_modint<id>::bt(998244353);\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#include \"cftemp.hpp\"\
    \n#include \"math/matrix.hpp\"\n\nusing mint = atcoder::static_modint<1000000009>;\n\
    mint res;\nint c = 1;\nvoid main_() {\n\twhile(true) {\n\t\tINT(w);\n\t\tLL(h);\n\
    \t\tINT(n);\n\t\tif(w == 0) return;\n\t\tmatrix<mint> dp(1, w);\n\t\tdp[0][0]\
    \ = 1;\n\t\tmatrix<mint> mul(w, w);\n\t\tREP(i, w) {\n\t\t\tREP(j, max(i - 1,\
    \ 0), min(i + 2, w)) {\n\t\t\t\tmul[i][j] = 1;\n\t\t\t}\n\t\t}\n\t\tmap<ll, V<>>\
    \ mp;\n\t\tREP(i, n) {\n\t\t\tLL(x, y);\n\t\t\t--x, --y;\n\t\t\tif(!y) continue;\n\
    \t\t\tmp[y].pb(x);\n\t\t}\n\t\tmp[h - 1].pb(w);\n\t\tll bef = 0;\n\t\tfor(auto\
    \ [val, vec] : mp) {\n\t\t\tdp *= mul ^ (val - bef);\n\t\t\tfoa(v, vec) {\n\t\t\
    \t\tif(v < w)\n\t\t\t\t\tdp[0][v] = 0;\n\t\t\t\telse {\n\t\t\t\t\tcout << \"Case\
    \ \" << c++ << \": \";\n\t\t\t\t\tprint(dp[0].back().val());\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\tbef = val;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - cftemp.hpp
  - math/matrix.hpp
  isVerificationFile: false
  path: submit.cpp
  requiredBy: []
  timestamp: '2021-09-08 00:15:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: submit.cpp
layout: document
redirect_from:
- /library/submit.cpp
- /library/submit.cpp.html
title: submit.cpp
---