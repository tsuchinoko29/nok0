---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/dsu.hpp
    title: atcoder/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/fenwicktree.hpp
    title: atcoder/fenwicktree.hpp
  - icon: ':question:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_csr.hpp
    title: atcoder/internal_csr.hpp
  - icon: ':question:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_queue.hpp
    title: atcoder/internal_queue.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_scc.hpp
    title: atcoder/internal_scc.hpp
  - icon: ':question:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/math.hpp
    title: atcoder/math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/mincostflow.hpp
    title: atcoder/mincostflow.hpp
  - icon: ':question:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/scc.hpp
    title: atcoder/scc.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/string.hpp
    title: atcoder/string.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/twosat.hpp
    title: atcoder/twosat.hpp
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: multi.hpp
    title: multi.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo-factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n\n#line 1 \"math/factorize.hpp\"\n#include <bits/stdc++.h>\n\nnamespace inner\
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
    \treturn res;\n}\n#line 2 \"multi.hpp\"\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
    #include <atcoder/all>\nusing namespace atcoder;\n#endif\n\n#pragma region Macros\n\
    // rep macro\n#define foa(v, a) for(auto &v : a)\n#define REPname(a, b, c, d,\
    \ e, ...) e\n#define REP(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)\n\
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
    \ ? -1 : 1);\n\treturn is;\n}\n#if __has_include(<atcoder/all>)\nstd::istream\
    \ &operator>>(std::istream &is, atcoder::modint998244353 &a) {\n\tlong long v;\n\
    \tis >> v;\n\ta = v;\n\treturn is;\n}\nstd::istream &operator>>(std::istream &is,\
    \ atcoder::modint1000000007 &a) {\n\tlong long v;\n\tis >> v;\n\ta = v;\n\treturn\
    \ is;\n}\ntemplate <int m>\nstd::istream &operator>>(std::istream &is, atcoder::static_modint<m>\
    \ &a) {\n\tlong long v;\n\tis >> v;\n\ta = v;\n\treturn is;\n}\ntemplate <int\
    \ m>\nstd::istream &operator>>(std::istream &is, atcoder::dynamic_modint<m> &a)\
    \ {\n\tlong long v;\n\tis >> v;\n\ta = v;\n\treturn is;\n}\n#endif\nnamespace\
    \ scanner {\nvoid scan(int &a) { std::cin >> a; }\nvoid scan(long long &a) { std::cin\
    \ >> a; }\nvoid scan(std::string &a) { std::cin >> a; }\nvoid scan(char &a) {\
    \ std::cin >> a; }\nvoid scan(char a[]) { std::scanf(\"%s\", a); }\nvoid scan(double\
    \ &a) { std::cin >> a; }\nvoid scan(long double &a) { std::cin >> a; }\ntemplate\
    \ <class T, class U>\nvoid scan(std::pair<T, U> &p) { std::cin >> p; }\ntemplate\
    \ <class T>\nvoid scan(std::vector<T> &a) { std::cin >> a; }\nvoid INPUT() {}\n\
    template <class Head, class... Tail>\nvoid INPUT(Head &head, Tail &... tail) {\n\
    \tscan(head);\n\tINPUT(tail...);\n}\n}  // namespace scanner\n#define VEC(type,\
    \ name, size)     \\\n\tstd::vector<type> name(size); \\\n\tscanner::INPUT(name)\n\
    #define VVEC(type, name, h, w)                                    \\\n\tstd::vector<std::vector<type>>\
    \ name(h, std::vector<type>(w)); \\\n\tscanner::INPUT(name)\n#define INT(...)\
    \     \\\n\tint __VA_ARGS__; \\\n\tscanner::INPUT(__VA_ARGS__)\n#define LL(...)\
    \            \\\n\tlong long __VA_ARGS__; \\\n\tscanner::INPUT(__VA_ARGS__)\n\
    #define STR(...)             \\\n\tstd::string __VA_ARGS__; \\\n\tscanner::INPUT(__VA_ARGS__)\n\
    #define CHAR(...)     \\\n\tchar __VA_ARGS__; \\\n\tscanner::INPUT(__VA_ARGS__)\n\
    #define DOUBLE(...)     \\\n\tdouble __VA_ARGS__; \\\n\tscanner::INPUT(__VA_ARGS__)\n\
    #define LD(...)              \\\n\tlong double __VA_ARGS__; \\\n\tscanner::INPUT(__VA_ARGS__)\n\
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
    return dest;\n}\n#if __has_include(<atcoder/all>)\nstd::ostream &operator<<(std::ostream\
    \ &os, const atcoder::modint998244353 &a) { return os << a.val(); }\nstd::ostream\
    \ &operator<<(std::ostream &os, const atcoder::modint1000000007 &a) { return os\
    \ << a.val(); }\ntemplate <int m>\nstd::ostream &operator<<(std::ostream &os,\
    \ const atcoder::static_modint<m> &a) { return os << a.val(); }\ntemplate <int\
    \ m>\nstd::ostream &operator<<(std::ostream &os, const atcoder::dynamic_modint<m>\
    \ &a) { return os << a.val(); }\n#endif\ntemplate <class T>\nvoid print(const\
    \ T a) { std::cout << a << '\\n'; }\ntemplate <class Head, class... Tail>\nvoid\
    \ print(Head H, Tail... T) {\n\tstd::cout << H << ' ';\n\tprint(T...);\n}\ntemplate\
    \ <class T>\nvoid printel(const T a) { std::cout << a << '\\n'; }\ntemplate <class\
    \ T>\nvoid printel(const std::vector<T> &a) {\n\tfor(const auto &v : a)\n\t\t\
    std::cout << v << '\\n';\n}\ntemplate <class Head, class... Tail>\nvoid printel(Head\
    \ H, Tail... T) {\n\tstd::cout << H << '\\n';\n\tprintel(T...);\n}\nvoid Yes(const\
    \ bool b = true) { std::cout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No() { std::cout\
    \ << \"No\\n\"; }\nvoid YES(const bool b = true) { std::cout << (b ? \"YES\\n\"\
    \ : \"NO\\n\"); }\nvoid NO() { std::cout << \"NO\\n\"; }\nvoid err(const bool\
    \ b = true) {\n\tif(b) {\n\t\tstd::cout << \"-1\\n\", exit(0);\n\t}\n}\n\n//debug\
    \ macro\nnamespace debugger {\ntemplate <class T>\nvoid view(const std::vector<T>\
    \ &a) {\n\tstd::cerr << \"{ \";\n\tfor(const auto &v : a) {\n\t\tstd::cerr <<\
    \ v << \", \";\n\t}\n\tstd::cerr << \"\\b\\b }\";\n}\ntemplate <class T>\nvoid\
    \ view(const std::vector<std::vector<T>> &a) {\n\tstd::cerr << \"{\\n\";\n\tfor(const\
    \ auto &v : a) {\n\t\tstd::cerr << \"\\t\";\n\t\tview(v);\n\t\tstd::cerr << \"\
    \\n\";\n\t}\n\tstd::cerr << \"}\";\n}\ntemplate <class T, class U>\nvoid view(const\
    \ std::vector<std::pair<T, U>> &a) {\n\tstd::cerr << \"{\\n\";\n\tfor(const auto\
    \ &p : a) std::cerr << \"\\t(\" << p.first << \", \" << p.second << \")\\n\";\n\
    \tstd::cerr << \"}\";\n}\ntemplate <class T, class U>\nvoid view(const std::map<T,\
    \ U> &m) {\n\tstd::cerr << \"{\\n\";\n\tfor(const auto &p : m) std::cerr << \"\
    \\t[\" << p.first << \"] : \" << p.second << \"\\n\";\n\tstd::cerr << \"}\";\n\
    }\ntemplate <class T, class U>\nvoid view(const std::pair<T, U> &p) { std::cerr\
    \ << \"(\" << p.first << \", \" << p.second << \")\"; }\ntemplate <class T>\n\
    void view(const std::set<T> &s) {\n\tstd::cerr << \"{ \";\n\tfor(auto &v : s)\
    \ {\n\t\tview(v);\n\t\tstd::cerr << \", \";\n\t}\n\tstd::cerr << \"\\b\\b }\"\
    ;\n}\n\ntemplate <class T>\nvoid view(const T &e) { std::cerr << e; }\n}  // namespace\
    \ debugger\n#ifdef LOCAL\nvoid debug_out() {}\ntemplate <typename Head, typename...\
    \ Tail>\nvoid debug_out(Head H, Tail... T) {\n\tdebugger::view(H);\n\tstd::cerr\
    \ << \", \";\n\tdebug_out(T...);\n}\n#define debug(...)                      \
    \                          \\\n\tdo {                                        \
    \                  \\\n\t\tstd::cerr << __LINE__ << \" [\" << #__VA_ARGS__ <<\
    \ \"] : [\"; \\\n\t\tdebug_out(__VA_ARGS__);                                 \
    \  \\\n\t\tstd::cerr << \"\\b\\b]\\n\";                                   \\\n\
    \t} while(false)\n#else\n#define debug(...) (void(0))\n#endif\n\n// vector macro\n\
    template <class T>\nint lb(const std::vector<T> &a, const T x) { return std::distance((a).begin(),\
    \ std::lower_bound((a).begin(), (a).end(), (x))); }\ntemplate <class T>\nint ub(const\
    \ std::vector<T> &a, const T x) { return std::distance((a).begin(), std::upper_bound((a).begin(),\
    \ (a).end(), (x))); }\ntemplate <class T>\nvoid UNIQUE(std::vector<T> &a) {\n\t\
    std::sort(a.begin(), a.end());\n\ta.erase(std::unique(a.begin(), a.end()), a.end());\n\
    }\ntemplate <class T>\nstd::vector<T> press(std::vector<T> &a) {\n\tauto res =\
    \ a;\n\tUNIQUE(res);\n\tfor(auto &v : a)\n\t\tv = lb(res, v);\n\treturn res;\n\
    }\n#define SORTname(a, b, c, ...) c\n#define SORT(...) SORTname(__VA_ARGS__, SORT1,\
    \ SORT0, ...)(__VA_ARGS__)\n#define SORT0(a) std::sort((a).begin(), (a).end())\n\
    #define SORT1(a, c) std::sort((a).begin(), (a).end(), [](const auto x, const auto\
    \ y) { return x c y; })\ntemplate <class T>\nvoid ADD(std::vector<T> &a, const\
    \ T x = 1) {\n\tfor(auto &v : a) v += x;\n}\ntemplate <class T>\nvoid SUB(std::vector<T>\
    \ &a, const T x = 1) {\n\tfor(auto &v : a) v -= x;\n}\ntemplate <class T>\nvoid\
    \ MUL(std::vector<T> &a, const T x) {\n\tfor(auto &v : a) v *= x;\n}\ntemplate\
    \ <class T>\nvoid DIV(std::vector<T> &a, const T x) {\n\tfor(auto &v : a) v /=\
    \ x;\n}\nstd::vector<std::pair<char, int>> rle(const string &s) {\n\tint n = s.size();\n\
    \tstd::vector<std::pair<char, int>> ret;\n\tfor(int l = 0; l < n;) {\n\t\tint\
    \ r = l + 1;\n\t\tfor(; r < n and s[l] == s[r]; r++) {}\n\t\tret.emplace_back(s[l],\
    \ r - l);\n\t\tl = r;\n\t}\n\treturn ret;\n}\ntemplate <class T>\nstd::vector<std::pair<T,\
    \ int>> rle(const std::vector<T> &v) {\n\tint n = v.size();\n\tstd::vector<std::pair<T,\
    \ int>> ret;\n\tfor(int l = 0; l < n;) {\n\t\tint r = l + 1;\n\t\tfor(; r < n\
    \ and v[l] == v[r]; r++) {}\n\t\tret.emplace_back(v[l], r - l);\n\t\tl = r;\n\t\
    }\n\treturn ret;\n}\n\n// math macro\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, const U &b) { return a > b ? a = b, true : false; }\ntemplate <class\
    \ T, class U>\ninline bool chmax(T &a, const U &b) { return a < b ? a = b, true\
    \ : false; }\ntemplate <class T>\nT divup(T x, T y) { return (x + y - 1) / y;\
    \ }\ntemplate <class T>\nT POW(T a, long long n) {\n\tT ret = 1;\n\twhile(n) {\n\
    \t\tif(n & 1) ret *= a;\n\t\ta *= a;\n\t\tn >>= 1;\n\t}\n\treturn ret;\n}\n//\
    \ modpow\nlong long POW(long long a, long long n, const int mod) {\n\tlong long\
    \ ret = 1;\n\ta = (a % mod + mod) % mod;\n\twhile(n) {\n\t\tif(n & 1) (ret *=\
    \ a) %= mod;\n\t\t(a *= a) %= mod;\n\t\tn >>= 1;\n\t}\n\treturn ret;\n}\n\n//\
    \ others\nstruct fast_io {\n\tfast_io() {\n\t\tios::sync_with_stdio(false);\n\t\
    \tcin.tie(nullptr);\n\t\tcout << fixed << setprecision(15);\n\t}\n} fast_io_;\n\
    const int inf = 1e9;\nconst ll INF = 1e18;\n#pragma endregion\n\nvoid main_();\n\
    \nint main() {\n\tint t;\n\tcin >> t;\n\twhile(t--) main_();\n\treturn 0;\n}\n\
    #line 5 \"test/yosupo-factorize.test.cpp\"\n\nvoid main_() {\n\tLL(a);\n\tauto\
    \ vec = factorize(a);\n\tSORT(vec);\n\tprint(SZ(vec), vec);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ \"math/factorize.hpp\"\n#include \"multi.hpp\"\n\nvoid main_() {\n\tLL(a);\n\
    \tauto vec = factorize(a);\n\tSORT(vec);\n\tprint(SZ(vec), vec);\n}"
  dependsOn:
  - math/factorize.hpp
  - multi.hpp
  - atcoder/convolution.hpp
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - atcoder/dsu.hpp
  - atcoder/fenwicktree.hpp
  - atcoder/lazysegtree.hpp
  - atcoder/math.hpp
  - atcoder/maxflow.hpp
  - atcoder/internal_queue.hpp
  - atcoder/mincostflow.hpp
  - atcoder/internal_csr.hpp
  - atcoder/scc.hpp
  - atcoder/internal_scc.hpp
  - atcoder/segtree.hpp
  - atcoder/string.hpp
  - atcoder/twosat.hpp
  isVerificationFile: true
  path: test/yosupo-factorize.test.cpp
  requiredBy: []
  timestamp: '2021-09-08 15:21:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-factorize.test.cpp
- /verify/test/yosupo-factorize.test.cpp.html
title: test/yosupo-factorize.test.cpp
---
