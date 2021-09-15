---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':heavy_check_mark:'
    path: math/factorial.hpp
    title: math/factorial.hpp
  _extendedRequiredBy:
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
    path: test/yosupo-multipoint_evaluation.test.cpp
    title: test/yosupo-multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-polynomial_taylor_shift.test.cpp
    title: test/yosupo-polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-pow_of_formal_power_series.test.cpp
    title: test/yosupo-pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-sqrt_of_formal_power_series.test.cpp
    title: test/yosupo-sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-stirling_number_of_the_first_kind.test.cpp
    title: test/yosupo-stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo-stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/formal_power_series.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <iostream>\n#include <random>\n#include <vector>\n\n#line\
    \ 1 \"atcoder/convolution.hpp\"\n\n\n\n#line 5 \"atcoder/convolution.hpp\"\n#include\
    \ <array>\n#line 7 \"atcoder/convolution.hpp\"\n#include <type_traits>\n#line\
    \ 9 \"atcoder/convolution.hpp\"\n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n\
    #ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative `x` s.t.\
    \ `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return\
    \ minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int bsf_constexpr(unsigned\
    \ int n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n\
    }\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 <<\
    \ x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1\
    \ \"atcoder/modint.hpp\"\n\n\n\n#line 5 \"atcoder/modint.hpp\"\n#include <numeric>\n\
    #line 7 \"atcoder/modint.hpp\"\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\
    \n#line 1 \"atcoder/internal_math.hpp\"\n\n\n\n#include <utility>\n\n#ifdef _MSC_VER\n\
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
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#line 7 \"atcoder/internal_type_traits.hpp\"\n\nnamespace atcoder {\n\n\
    namespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value ||\n   \
    \                               std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
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
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 14 \"atcoder/modint.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\nstruct modint_base {};\nstruct\
    \ static_modint_base : modint_base {};\n\ntemplate <class T> using is_modint =\
    \ std::is_base_of<modint_base, T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 12 \"atcoder/convolution.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate <class mint,\n   \
    \       int g = internal::primitive_root<mint::mod()>,\n          internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstruct fft_info {\n    static constexpr int rank2 = bsf_constexpr(mint::mod()\
    \ - 1);\n    std::array<mint, rank2 + 1> root;   // root[i]^(2^i) == 1\n    std::array<mint,\
    \ rank2 + 1> iroot;  // root[i] * iroot[i] == 1\n\n    std::array<mint, std::max(0,\
    \ rank2 - 2 + 1)> rate2;\n    std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;\n\
    \n    std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;\n    std::array<mint,\
    \ std::max(0, rank2 - 3 + 1)> irate3;\n\n    fft_info() {\n        root[rank2]\
    \ = mint(g).pow((mint::mod() - 1) >> rank2);\n        iroot[rank2] = root[rank2].inv();\n\
    \        for (int i = rank2 - 1; i >= 0; i--) {\n            root[i] = root[i\
    \ + 1] * root[i + 1];\n            iroot[i] = iroot[i + 1] * iroot[i + 1];\n \
    \       }\n\n        {\n            mint prod = 1, iprod = 1;\n            for\
    \ (int i = 0; i <= rank2 - 2; i++) {\n                rate2[i] = root[i + 2] *\
    \ prod;\n                irate2[i] = iroot[i + 2] * iprod;\n                prod\
    \ *= iroot[i + 2];\n                iprod *= root[i + 2];\n            }\n   \
    \     }\n        {\n            mint prod = 1, iprod = 1;\n            for (int\
    \ i = 0; i <= rank2 - 3; i++) {\n                rate3[i] = root[i + 3] * prod;\n\
    \                irate3[i] = iroot[i + 3] * iprod;\n                prod *= iroot[i\
    \ + 3];\n                iprod *= root[i + 3];\n            }\n        }\n   \
    \ }\n};\n\ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    void butterfly(std::vector<mint>& a) {\n    int n = int(a.size());\n    int h\
    \ = internal::ceil_pow2(n);\n\n    static const fft_info<mint> info;\n\n    int\
    \ len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n    while (len\
    \ < h) {\n        if (h - len == 1) {\n            int p = 1 << (h - len - 1);\n\
    \            mint rot = 1;\n            for (int s = 0; s < (1 << len); s++) {\n\
    \                int offset = s << (h - len);\n                for (int i = 0;\
    \ i < p; i++) {\n                    auto l = a[i + offset];\n               \
    \     auto r = a[i + offset + p] * rot;\n                    a[i + offset] = l\
    \ + r;\n                    a[i + offset + p] = l - r;\n                }\n  \
    \              if (s + 1 != (1 << len))\n                    rot *= info.rate2[bsf(~(unsigned\
    \ int)(s))];\n            }\n            len++;\n        } else {\n          \
    \  // 4-base\n            int p = 1 << (h - len - 2);\n            mint rot =\
    \ 1, imag = info.root[2];\n            for (int s = 0; s < (1 << len); s++) {\n\
    \                mint rot2 = rot * rot;\n                mint rot3 = rot2 * rot;\n\
    \                int offset = s << (h - len);\n                for (int i = 0;\
    \ i < p; i++) {\n                    auto mod2 = 1ULL * mint::mod() * mint::mod();\n\
    \                    auto a0 = 1ULL * a[i + offset].val();\n                 \
    \   auto a1 = 1ULL * a[i + offset + p].val() * rot.val();\n                  \
    \  auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();\n              \
    \      auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();\n          \
    \          auto a1na3imag =\n                        1ULL * mint(a1 + mod2 - a3).val()\
    \ * imag.val();\n                    auto na2 = mod2 - a2;\n                 \
    \   a[i + offset] = a0 + a2 + a1 + a3;\n                    a[i + offset + 1 *\
    \ p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n                    a[i + offset + 2\
    \ * p] = a0 + na2 + a1na3imag;\n                    a[i + offset + 3 * p] = a0\
    \ + na2 + (mod2 - a1na3imag);\n                }\n                if (s + 1 !=\
    \ (1 << len))\n                    rot *= info.rate3[bsf(~(unsigned int)(s))];\n\
    \            }\n            len += 2;\n        }\n    }\n}\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nvoid butterfly_inv(std::vector<mint>&\
    \ a) {\n    int n = int(a.size());\n    int h = internal::ceil_pow2(n);\n\n  \
    \  static const fft_info<mint> info;\n\n    int len = h;  // a[i, i+(n>>len),\
    \ i+2*(n>>len), ..] is transformed\n    while (len) {\n        if (len == 1) {\n\
    \            int p = 1 << (h - len);\n            mint irot = 1;\n           \
    \ for (int s = 0; s < (1 << (len - 1)); s++) {\n                int offset = s\
    \ << (h - len + 1);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto l = a[i + offset];\n                    auto r = a[i + offset\
    \ + p];\n                    a[i + offset] = l + r;\n                    a[i +\
    \ offset + p] =\n                        (unsigned long long)(mint::mod() + l.val()\
    \ - r.val()) *\n                        irot.val();\n                    ;\n \
    \               }\n                if (s + 1 != (1 << (len - 1)))\n          \
    \          irot *= info.irate2[bsf(~(unsigned int)(s))];\n            }\n    \
    \        len--;\n        } else {\n            // 4-base\n            int p =\
    \ 1 << (h - len);\n            mint irot = 1, iimag = info.iroot[2];\n       \
    \     for (int s = 0; s < (1 << (len - 2)); s++) {\n                mint irot2\
    \ = irot * irot;\n                mint irot3 = irot2 * irot;\n               \
    \ int offset = s << (h - len + 2);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto a0 = 1ULL * a[i + offset + 0 * p].val();\n     \
    \               auto a1 = 1ULL * a[i + offset + 1 * p].val();\n              \
    \      auto a2 = 1ULL * a[i + offset + 2 * p].val();\n                    auto\
    \ a3 = 1ULL * a[i + offset + 3 * p].val();\n\n                    auto a2na3iimag\
    \ =\n                        1ULL *\n                        mint((mint::mod()\
    \ + a2 - a3) * iimag.val()).val();\n\n                    a[i + offset] = a0 +\
    \ a1 + a2 + a3;\n                    a[i + offset + 1 * p] =\n               \
    \         (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();\n             \
    \       a[i + offset + 2 * p] =\n                        (a0 + a1 + (mint::mod()\
    \ - a2) + (mint::mod() - a3)) *\n                        irot2.val();\n      \
    \              a[i + offset + 3 * p] =\n                        (a0 + (mint::mod()\
    \ - a1) + (mint::mod() - a2na3iimag)) *\n                        irot3.val();\n\
    \                }\n                if (s + 1 != (1 << (len - 2)))\n         \
    \           irot *= info.irate3[bsf(~(unsigned int)(s))];\n            }\n   \
    \         len -= 2;\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> convolution_naive(const std::vector<mint>& a,\n\
    \                                    const std::vector<mint>& b) {\n    int n\
    \ = int(a.size()), m = int(b.size());\n    std::vector<mint> ans(n + m - 1);\n\
    \    if (n < m) {\n        for (int j = 0; j < m; j++) {\n            for (int\
    \ i = 0; i < n; i++) {\n                ans[i + j] += a[i] * b[j];\n         \
    \   }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n      \
    \      for (int j = 0; j < m; j++) {\n                ans[i + j] += a[i] * b[j];\n\
    \            }\n        }\n    }\n    return ans;\n}\n\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution_fft(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int n = int(a.size()), m = int(b.size());\n \
    \   int z = 1 << internal::ceil_pow2(n + m - 1);\n    a.resize(z);\n    internal::butterfly(a);\n\
    \    b.resize(z);\n    internal::butterfly(b);\n    for (int i = 0; i < z; i++)\
    \ {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(n\
    \ + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i < n + m - 1;\
    \ i++) a[i] *= iz;\n    return a;\n}\n\n}  // namespace internal\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(std::vector<mint>&&\
    \ a, std::vector<mint>&& b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n    if (std::min(n, m) <= 60) return convolution_naive(a,\
    \ b);\n    return internal::convolution_fft(a, b);\n}\n\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& a,\n                              const std::vector<mint>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n    if (std::min(n, m) <= 60) return convolution_naive(a, b);\n    return\
    \ internal::convolution_fft(a, b);\n}\n\ntemplate <unsigned int mod = 998244353,\n\
    \          class T,\n          std::enable_if_t<internal::is_integral<T>::value>*\
    \ = nullptr>\nstd::vector<T> convolution(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n\n    using mint = static_modint<mod>;\n    std::vector<mint> a2(n), b2(m);\n\
    \    for (int i = 0; i < n; i++) {\n        a2[i] = mint(a[i]);\n    }\n    for\
    \ (int i = 0; i < m; i++) {\n        b2[i] = mint(b[i]);\n    }\n    auto c2 =\
    \ convolution(move(a2), move(b2));\n    std::vector<T> c(n + m - 1);\n    for\
    \ (int i = 0; i < n + m - 1; i++) {\n        c[i] = c2[i].val();\n    }\n    return\
    \ c;\n}\n\nstd::vector<long long> convolution_ll(const std::vector<long long>&\
    \ a,\n                                      const std::vector<long long>& b) {\n\
    \    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\
    \n    static constexpr unsigned long long MOD1 = 754974721;  // 2^24\n    static\
    \ constexpr unsigned long long MOD2 = 167772161;  // 2^25\n    static constexpr\
    \ unsigned long long MOD3 = 469762049;  // 2^26\n    static constexpr unsigned\
    \ long long M2M3 = MOD2 * MOD3;\n    static constexpr unsigned long long M1M3\
    \ = MOD1 * MOD3;\n    static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n\
    \    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n    static\
    \ constexpr unsigned long long i1 =\n        internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n\
    \    static constexpr unsigned long long i2 =\n        internal::inv_gcd(MOD1\
    \ * MOD3, MOD2).second;\n    static constexpr unsigned long long i3 =\n      \
    \  internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n\n    auto c1 = convolution<MOD1>(a,\
    \ b);\n    auto c2 = convolution<MOD2>(a, b);\n    auto c3 = convolution<MOD3>(a,\
    \ b);\n\n    std::vector<long long> c(n + m - 1);\n    for (int i = 0; i < n +\
    \ m - 1; i++) {\n        unsigned long long x = 0;\n        x += (c1[i] * i1)\
    \ % MOD1 * M2M3;\n        x += (c2[i] * i2) % MOD2 * M1M3;\n        x += (c3[i]\
    \ * i3) % MOD3 * M1M2;\n        // B = 2^63, -B <= x, r(real value) < B\n    \
    \    // (x, x - M, x - 2M, or x - 3M) = r (mod 2B)\n        // r = c1[i] (mod\
    \ MOD1)\n        // focus on MOD1\n        // r = x, x - M', x - 2M', x - 3M'\
    \ (M' = M % 2^64) (mod 2B)\n        // r = x,\n        //     x - M' + (0 or 2B),\n\
    \        //     x - 2M' + (0, 2B or 4B),\n        //     x - 3M' + (0, 2B, 4B\
    \ or 6B) (without mod!)\n        // (r - x) = 0, (0)\n        //           - M'\
    \ + (0 or 2B), (1)\n        //           -2M' + (0 or 2B or 4B), (2)\n       \
    \ //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)\n        // we checked\
    \ that\n        //   ((1) mod MOD1) mod 5 = 2\n        //   ((2) mod MOD1) mod\
    \ 5 = 3\n        //   ((3) mod MOD1) mod 5 = 4\n        long long diff =\n   \
    \         c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));\n   \
    \     if (diff < 0) diff += MOD1;\n        static constexpr unsigned long long\
    \ offset[5] = {\n            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n        x\
    \ -= offset[diff % 5];\n        c[i] = x;\n    }\n\n    return c;\n}\n\n}  //\
    \ namespace atcoder\n\n\n#line 4 \"math/factorial.hpp\"\n\n#line 6 \"math/factorial.hpp\"\
    \n\ntemplate <class T>\nstruct factorial {\npublic:\n\tstatic int MAX;\n\tstatic\
    \ std::vector<T> fac, finv, inv;\n\n\tfactorial() {}\n\n\tT binom(int n, int r)\
    \ {\n\t\tif(n < r or n < 0 or r < 0) return T(0);\n\t\tassert(n < MAX);\n\t\t\
    return fac[n] * finv[r] * finv[n - r];\n\t}\n\n\tT large_binom(int n, int r) {\n\
    \t\tif(n < r or n < 0 or r < 0) return T(0);\n\t\tassert(r < MAX);\n\t\tT ret\
    \ = finv[r];\n\t\tfor(int i = 1; i <= r; ++i)\n\t\t\tret *= (n + 1 - i);\n\t\t\
    return ret;\n\t}\n\n\tstatic void set_size(int n = 3000000) {\n\t\tMAX = (n >\
    \ 1 ? n : 1) + 1;\n\t\tif((int)fac.size() >= MAX) return;\n\t\tfac.resize(MAX);\n\
    \t\tfinv.resize(MAX);\n\t\tinv.resize(MAX);\n\t\tconst int MOD = T::mod();\n\t\
    \tfac[0] = fac[1] = 1;\n\t\tfinv[0] = finv[1] = 1;\n\t\tinv[1] = 1;\n\t\tfor(int\
    \ i = 2; i < MAX; i++) {\n\t\t\tfac[i] = fac[i - 1] * i;\n\t\t\tinv[i] = (T)MOD\
    \ - inv[MOD % i] * (MOD / i);\n\t\t\tfinv[i] = finv[i - 1] * inv[i];\n\t\t}\n\t\
    }\n};\ntemplate <class T>\nint factorial<T>::MAX = 0;\ntemplate <class T>\nstd::vector<T>\
    \ factorial<T>::fac;\ntemplate <class T>\nstd::vector<T> factorial<T>::finv;\n\
    template <class T>\nstd::vector<T> factorial<T>::inv;\n#line 10 \"math/formal_power_series.hpp\"\
    \n\nenum Mode {\n\tFAST = 1,\n\tNAIVE = -1,\n};\ntemplate <class T, Mode mode\
    \ = FAST>\nstruct formal_power_series : std::vector<T> {\n\tfactorial<T> fact;\n\
    \tusing std::vector<T>::vector;\n\tusing std::vector<T>::size;\n\tusing std::vector<T>::resize;\n\
    \tusing std::vector<T>::begin;\n\tusing std::vector<T>::insert;\n\tusing std::vector<T>::erase;\n\
    \tusing F = formal_power_series;\n\tusing S = std::vector<std::pair<int, T>>;\n\
    \n\tF &operator+=(const F &g) {\n\t\tfor(int i = 0; i < int(std::min((*this).size(),\
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
    \twhile(!(*this).empty() and (*this).back() == T(0)) (*this).pop_back();\n\t\t\
    return *this;\n\t}\n\n\tF &rev_inplace() {\n\t\treverse((*this).begin(), (*this).end());\n\
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
    \ k) {\n\t\tF ret(n);\n\t\tT tmp = 1;\n\t\tif(k >= 0) {\n\t\t\tfor(int i = 0;\
    \ i < n; i += d) {\n\t\t\t\tret[i] = fact.binom(k, i / d) * tmp;\n\t\t\t\ttmp\
    \ *= c;\n\t\t\t}\n\t\t} else {\n\t\t\tfor(int i = 0; i < n; i += d) {\n\t\t\t\t\
    ret[i] = fact.binom(i / d - k - 1, -k - 1) * tmp;\n\t\t\t\ttmp *= -c;\n\t\t\t\
    }\n\t\t}\n\t\t(*this) = ret;\n\t}\n\n\tvoid sparse_pow_inv(const int n, const\
    \ int d, const T c, const int k) { return sparse_pow(n, d, c, -k); }\n\n\tvoid\
    \ stirling_first(int n) {\n\t\tif(!n) {\n\t\t\t*this = F{1};\n\t\t\treturn;\n\t\
    \t}\n\t\tint m = 1;\n\t\tF res(n + 1);\n\t\tres[1] = 1;\n\t\tfor(int k = 30 -\
    \ __builtin_clz(n); k >= 0; --k) {\n\t\t\tF as(m * 2 + 1), bs(m + 1);\n\t\t\t\
    for(int i = 0; i <= m; i++)\n\t\t\t\tas[i] = fact.fac[i] * res[i];\n\n\t\t\tbs[m]\
    \ = 1;\n\t\t\tfor(int i = m - 1; i >= 0; i--)\n\t\t\t\tbs[i] -= bs[i + 1] * m;\n\
    \n\t\t\tfor(int i = 0; i <= m; i++)\n\t\t\t\tbs[m - i] *= fact.finv[i];\n\n\t\t\
    \tF cs = as * bs, ds(m + 1);\n\t\t\tfor(int i = 0; i <= m; i++)\n\t\t\t\tds[i]\
    \ = cs[m + i] * fact.finv[i];\n\n\t\t\tres *= ds;\n\t\t\tm <<= 1;\n\t\t\tif(n\
    \ >> k & 1) {\n\t\t\t\tF g(n + 1);\n\t\t\t\tfor(int i = 0; i <= m; i++) {\n\t\t\
    \t\t\tg[i] -= res[i] * m;\n\t\t\t\t\tg[i + 1] += res[i];\n\t\t\t\t}\n\t\t\t\t\
    res = g;\n\t\t\t\tm |= 1;\n\t\t\t}\n\t\t}\n\t\t*this = res;\n\t}\n\n\tvoid stirling_second(int\
    \ n) {\n\t\tF f(n + 1), g(n + 1);\n\t\tfor(int i = 0; i <= n; i++) {\n\t\t\tf[i]\
    \ = T(i).pow(n) * fact.finv[i];\n\t\t\tg[i] = fact.finv[i] * (i % 2 ? -1 : 1);\n\
    \t\t}\n\t\tf *= g;\n\t\t*this = f;\n\t}\n\n\t//return f(x + c)\n\tF taylor_shift(int\
    \ c) {\n\t\tF f(*this);\n\t\tint n = this->size();\n\t\tfor(int i = 0; i < n;\
    \ i++) f[i] *= fact.fac[i];\n\t\treverse(f.begin(), f.end());\n\t\tF g(n, 1);\n\
    \t\tT mul = 1;\n\t\tfor(int i = 1; i < n; i++)\n\t\t\tg[i] = (mul *= c) * fact.finv[i];\n\
    \t\tf *= g;\n\t\treverse(f.begin(), f.end());\n\t\tfor(int i = 0; i < n; i++)\
    \ f[i] *= fact.finv[i];\n\t\treturn f;\n\t}\n\tF taylor_shift(T c) { return taylor_shift(c.val());\
    \ }\n\n\ttemplate <class U>\n\tstd::vector<T> multipoint_evaluation(const std::vector<U>\
    \ &p) {\n\t\tusing fps = formal_power_series<T, mode>;\n\t\tint m = p.size();\n\
    \t\tint n = 1 << std::max(atcoder::internal::ceil_pow2(m), 1);\n\t\tstd::vector<fps>\
    \ subproducts(2 * n, F{1}), rem(2 * n);\n\t\tfor(int i = n; i < n + m; i++) subproducts[i]\
    \ = fps({-p[i - n], 1});\n\t\tfor(int i = n - 1; i; i--) {\n\t\t\tint x = subproducts[i\
    \ << 1].size(), y = subproducts[i << 1 | 1].size();\n\t\t\tsubproducts[i] = subproducts[i\
    \ << 1];\n\t\t\tsubproducts[i].resize(x + y - 1);\n\t\t\tsubproducts[i] *= subproducts[i\
    \ << 1 | 1];\n\t\t}\n\t\trem[1] = *this;\n\t\tfor(int i = 1; i < n; i++) {\n\t\
    \t\trem[i << 1] = rem[i] % subproducts[i << 1];\n\t\t\trem[i << 1].shrink();\n\
    \t\t\trem[i << 1 | 1] = rem[i] % subproducts[i << 1 | 1];\n\t\t\trem[i << 1 |\
    \ 1].shrink();\n\t\t}\n\t\tstd::vector<T> res(m);\n\t\tfor(int i = 0; i < m; i++)\
    \ res[i] = (!rem[i + n].empty() ? rem[i + n][0] : 0);\n\t\treturn res;\n\t}\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n\
    #include <random>\n#include <vector>\n\n#include \"atcoder/convolution\"\n#include\
    \ \"math/factorial.hpp\"\n\nenum Mode {\n\tFAST = 1,\n\tNAIVE = -1,\n};\ntemplate\
    \ <class T, Mode mode = FAST>\nstruct formal_power_series : std::vector<T> {\n\
    \tfactorial<T> fact;\n\tusing std::vector<T>::vector;\n\tusing std::vector<T>::size;\n\
    \tusing std::vector<T>::resize;\n\tusing std::vector<T>::begin;\n\tusing std::vector<T>::insert;\n\
    \tusing std::vector<T>::erase;\n\tusing F = formal_power_series;\n\tusing S =\
    \ std::vector<std::pair<int, T>>;\n\n\tF &operator+=(const F &g) {\n\t\tfor(int\
    \ i = 0; i < int(std::min((*this).size(), g.size())); i++) (*this)[i] += g[i];\n\
    \t\treturn *this;\n\t}\n\n\tF &operator+=(const T &t) {\n\t\tassert(int((*this).size()));\n\
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
    \twhile(!(*this).empty() and (*this).back() == T(0)) (*this).pop_back();\n\t\t\
    return *this;\n\t}\n\n\tF &rev_inplace() {\n\t\treverse((*this).begin(), (*this).end());\n\
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
    \ k) {\n\t\tF ret(n);\n\t\tT tmp = 1;\n\t\tif(k >= 0) {\n\t\t\tfor(int i = 0;\
    \ i < n; i += d) {\n\t\t\t\tret[i] = fact.binom(k, i / d) * tmp;\n\t\t\t\ttmp\
    \ *= c;\n\t\t\t}\n\t\t} else {\n\t\t\tfor(int i = 0; i < n; i += d) {\n\t\t\t\t\
    ret[i] = fact.binom(i / d - k - 1, -k - 1) * tmp;\n\t\t\t\ttmp *= -c;\n\t\t\t\
    }\n\t\t}\n\t\t(*this) = ret;\n\t}\n\n\tvoid sparse_pow_inv(const int n, const\
    \ int d, const T c, const int k) { return sparse_pow(n, d, c, -k); }\n\n\tvoid\
    \ stirling_first(int n) {\n\t\tif(!n) {\n\t\t\t*this = F{1};\n\t\t\treturn;\n\t\
    \t}\n\t\tint m = 1;\n\t\tF res(n + 1);\n\t\tres[1] = 1;\n\t\tfor(int k = 30 -\
    \ __builtin_clz(n); k >= 0; --k) {\n\t\t\tF as(m * 2 + 1), bs(m + 1);\n\t\t\t\
    for(int i = 0; i <= m; i++)\n\t\t\t\tas[i] = fact.fac[i] * res[i];\n\n\t\t\tbs[m]\
    \ = 1;\n\t\t\tfor(int i = m - 1; i >= 0; i--)\n\t\t\t\tbs[i] -= bs[i + 1] * m;\n\
    \n\t\t\tfor(int i = 0; i <= m; i++)\n\t\t\t\tbs[m - i] *= fact.finv[i];\n\n\t\t\
    \tF cs = as * bs, ds(m + 1);\n\t\t\tfor(int i = 0; i <= m; i++)\n\t\t\t\tds[i]\
    \ = cs[m + i] * fact.finv[i];\n\n\t\t\tres *= ds;\n\t\t\tm <<= 1;\n\t\t\tif(n\
    \ >> k & 1) {\n\t\t\t\tF g(n + 1);\n\t\t\t\tfor(int i = 0; i <= m; i++) {\n\t\t\
    \t\t\tg[i] -= res[i] * m;\n\t\t\t\t\tg[i + 1] += res[i];\n\t\t\t\t}\n\t\t\t\t\
    res = g;\n\t\t\t\tm |= 1;\n\t\t\t}\n\t\t}\n\t\t*this = res;\n\t}\n\n\tvoid stirling_second(int\
    \ n) {\n\t\tF f(n + 1), g(n + 1);\n\t\tfor(int i = 0; i <= n; i++) {\n\t\t\tf[i]\
    \ = T(i).pow(n) * fact.finv[i];\n\t\t\tg[i] = fact.finv[i] * (i % 2 ? -1 : 1);\n\
    \t\t}\n\t\tf *= g;\n\t\t*this = f;\n\t}\n\n\t//return f(x + c)\n\tF taylor_shift(int\
    \ c) {\n\t\tF f(*this);\n\t\tint n = this->size();\n\t\tfor(int i = 0; i < n;\
    \ i++) f[i] *= fact.fac[i];\n\t\treverse(f.begin(), f.end());\n\t\tF g(n, 1);\n\
    \t\tT mul = 1;\n\t\tfor(int i = 1; i < n; i++)\n\t\t\tg[i] = (mul *= c) * fact.finv[i];\n\
    \t\tf *= g;\n\t\treverse(f.begin(), f.end());\n\t\tfor(int i = 0; i < n; i++)\
    \ f[i] *= fact.finv[i];\n\t\treturn f;\n\t}\n\tF taylor_shift(T c) { return taylor_shift(c.val());\
    \ }\n\n\ttemplate <class U>\n\tstd::vector<T> multipoint_evaluation(const std::vector<U>\
    \ &p) {\n\t\tusing fps = formal_power_series<T, mode>;\n\t\tint m = p.size();\n\
    \t\tint n = 1 << std::max(atcoder::internal::ceil_pow2(m), 1);\n\t\tstd::vector<fps>\
    \ subproducts(2 * n, F{1}), rem(2 * n);\n\t\tfor(int i = n; i < n + m; i++) subproducts[i]\
    \ = fps({-p[i - n], 1});\n\t\tfor(int i = n - 1; i; i--) {\n\t\t\tint x = subproducts[i\
    \ << 1].size(), y = subproducts[i << 1 | 1].size();\n\t\t\tsubproducts[i] = subproducts[i\
    \ << 1];\n\t\t\tsubproducts[i].resize(x + y - 1);\n\t\t\tsubproducts[i] *= subproducts[i\
    \ << 1 | 1];\n\t\t}\n\t\trem[1] = *this;\n\t\tfor(int i = 1; i < n; i++) {\n\t\
    \t\trem[i << 1] = rem[i] % subproducts[i << 1];\n\t\t\trem[i << 1].shrink();\n\
    \t\t\trem[i << 1 | 1] = rem[i] % subproducts[i << 1 | 1];\n\t\t\trem[i << 1 |\
    \ 1].shrink();\n\t\t}\n\t\tstd::vector<T> res(m);\n\t\tfor(int i = 0; i < m; i++)\
    \ res[i] = (!rem[i + n].empty() ? rem[i + n][0] : 0);\n\t\treturn res;\n\t}\n\
    };\n"
  dependsOn:
  - atcoder/convolution.hpp
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - math/factorial.hpp
  isVerificationFile: false
  path: math/formal_power_series.hpp
  requiredBy:
  - math/multipoint_evaluation.hpp
  timestamp: '2021-09-12 23:05:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-stirling_number_of_the_second_kind.test.cpp
  - test/yosupo-division_of_polynomials.test.cpp
  - test/yosupo-inv_of_formal_power_series.test.cpp
  - test/yosupo-multipoint_evaluation.test.cpp
  - test/yosupo-log_of_formal_power_series.test.cpp
  - test/yosupo-pow_of_formal_power_series.test.cpp
  - test/yosupo-polynomial_taylor_shift.test.cpp
  - test/yosupo-sqrt_of_formal_power_series.test.cpp
  - test/yosupo-stirling_number_of_the_first_kind.test.cpp
  - test/yosupo-exp_of_formal_power_series.test.cpp
documentation_of: math/formal_power_series.hpp
layout: document
redirect_from:
- /library/math/formal_power_series.hpp
- /library/math/formal_power_series.hpp.html
title: math/formal_power_series.hpp
---
