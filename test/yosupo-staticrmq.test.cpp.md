---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':question:'
    path: cftemp.hpp
    title: cftemp.hpp
  - icon: ':x:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo-staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 1 \"cftemp.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #pragma region Macros\n// rep macro\n#define foa(v, a) for(auto &v : a)\n#define\
    \ REPname(a, b, c, d, e, ...) e\n#define REP(...) REPname(__VA_ARGS__, REP3, REP2,\
    \ REP1, REP0)(__VA_ARGS__)\n#define REP0(x) for(int i = 0; i < (x); ++i)\n#define\
    \ REP1(i, x) for(int i = 0; i < (x); ++i)\n#define REP2(i, l, r) for(int i = (l);\
    \ i < (r); ++i)\n#define REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))\n\
    #define REPSname(a, b, c, ...) c\n#define REPS(...) REPSname(__VA_ARGS__, REPS1,\
    \ REPS0)(__VA_ARGS__)\n#define REPS0(x) for(int i = 1; i <= (x); ++i)\n#define\
    \ REPS1(i, x) for(int i = 1; i <= (x); ++i)\n#define RREPname(a, b, c, d, e, ...)\
    \ e\n#define RREP(...) RREPname(__VA_ARGS__, RREP3, RREP2, RREP1, RREP0)(__VA_ARGS__)\n\
    #define RREP0(x) for(int i = (x)-1; i >= 0; --i)\n#define RREP1(i, x) for(int\
    \ i = (x)-1; i >= 0; --i)\n#define RREP2(i, r, l) for(int i = (r)-1; i >= (l);\
    \ --i)\n#define RREP3(i, r, l, c) for(int i = (r)-1; i >= (l); i -= (c))\n#define\
    \ RREPSname(a, b, c, ...) c\n#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1,\
    \ RREPS0)(__VA_ARGS__)\n#define RREPS0(x) for(int i = (x); i >= 1; --i)\n#define\
    \ RREPS1(i, x) for(int i = (x); i >= 1; --i)\n\n// name macro\n#define pb push_back\n\
    #define eb emplace_back\n#define SZ(x) ((int)(x).size())\n#define all(x) (x).begin(),\
    \ (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define popcnt(x) __builtin_popcountll(x)\n\
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
    void INPUT(Head &head, Tail &...tail) {\n\tscan(head);\n\tINPUT(tail...);\n}\n\
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
    \ &v : a) v -= x;\n}\nstd::vector<std::pair<char, int>> rle(const string &s) {\n\
    \tint n = s.size();\n\tstd::vector<std::pair<char, int>> ret;\n\tfor(int l = 0;\
    \ l < n;) {\n\t\tint r = l + 1;\n\t\tfor(; r < n and s[l] == s[r]; r++) {}\n\t\
    \tret.emplace_back(s[l], r - l);\n\t\tl = r;\n\t}\n\treturn ret;\n}\ntemplate\
    \ <class T>\nstd::vector<std::pair<T, int>> rle(const std::vector<T> &v) {\n\t\
    int n = v.size();\n\tstd::vector<std::pair<T, int>> ret;\n\tfor(int l = 0; l <\
    \ n;) {\n\t\tint r = l + 1;\n\t\tfor(; r < n and v[l] == v[r]; r++) {}\n\t\tret.emplace_back(v[l],\
    \ r - l);\n\t\tl = r;\n\t}\n\treturn ret;\n}\nstd::vector<int> iota(int n) {\n\
    \tstd::vector<int> p(n);\n\tstd::iota(p.begin(), p.end(), 0);\n\treturn p;\n}\n\
    template <class T>\nstruct cum_vector {\npublic:\n\tcum_vector() = default;\n\t\
    template <class U>\n\tcum_vector(const std::vector<U> &vec) : cum((int)vec.size()\
    \ + 1) {\n\t\tfor(int i = 0; i < (int)vec.size(); i++)\n\t\t\tcum[i + 1] = cum[i]\
    \ + vec[i];\n\t}\n\tT prod(int l, int r) {\n\t\treturn cum[r] - cum[l];\n\t}\n\
    \nprivate:\n\tstd::vector<T> cum;\n};\n\n// math macro\ntemplate <class T, class\
    \ U>\ninline bool chmin(T &a, const U &b) { return a > b ? a = b, true : false;\
    \ }\ntemplate <class T, class U>\ninline bool chmax(T &a, const U &b) { return\
    \ a < b ? a = b, true : false; }\ntemplate <class T>\nT divup(T x, T y) { return\
    \ (x + y - 1) / y; }\ntemplate <class T>\nT POW(T a, long long n) {\n\tT ret =\
    \ 1;\n\twhile(n) {\n\t\tif(n & 1) ret *= a;\n\t\ta *= a;\n\t\tn >>= 1;\n\t}\n\t\
    return ret;\n}\n// modpow\nlong long POW(long long a, long long n, const int mod)\
    \ {\n\tlong long ret = 1;\n\ta = (a % mod + mod) % mod;\n\twhile(n) {\n\t\tif(n\
    \ & 1) (ret *= a) %= mod;\n\t\t(a *= a) %= mod;\n\t\tn >>= 1;\n\t}\n\treturn ret;\n\
    }\ntemplate <class T, class F>\nT bin_search(T ok, T ng, const F &f) {\n\twhile(abs(ok\
    \ - ng) > 1) {\n\t\tT mid = (ok + ng) >> 1;\n\t\t(f(mid) ? ok : ng) = mid;\n\t\
    }\n\treturn ok;\n}\ntemplate <class T, class F>\nT bin_search(T ok, T ng, const\
    \ F &f, int loop) {\n\tfor(int i = 0; i < loop; i++) {\n\t\tT mid = (ok + ng)\
    \ / 2;\n\t\t(f(mid) ? ok : ng) = mid;\n\t}\n\treturn ok;\n}\n\n// others\nstruct\
    \ fast_io {\n\tfast_io() {\n\t\tios::sync_with_stdio(false);\n\t\tcin.tie(nullptr);\n\
    \t\tcout << fixed << setprecision(15);\n\t}\n} fast_io_;\nconst int inf = 1e9;\n\
    const ll INF = 1e18;\n#pragma endregion\n\nvoid main_();\n\nint main() {\n\tmain_();\n\
    \treturn 0;\n}\n#line 3 \"data_structure/sparse_table.hpp\"\n\n#line 1 \"atcoder/internal_bit.hpp\"\
    \n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\n\
    namespace internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U\
    \ << x) < (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n\
    // @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int\
    \ bsf_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1 << x)))\
    \ x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n\
    \    unsigned long index;\n    _BitScanForward(&index, n);\n    return index;\n\
    #else\n    return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace internal\n\n\
    }  // namespace atcoder\n\n\n#line 5 \"data_structure/sparse_table.hpp\"\n\ntemplate\
    \ <class S, S (*op)(S, S)>\nstruct sparse_table {\npublic:\n\tsparse_table() =\
    \ default;\n\texplicit sparse_table(const std::vector<S>& v) : _n(int(v.size())),\
    \ lt(int(v.size()) + 1) {\n\t\tlog = atcoder::internal::ceil_pow2(_n);\n\t\td.assign(log\
    \ + 1, std::vector<S>(_n));\n\t\tfor(int i = 0; i <= log; i++) {\n\t\t\tfor(int\
    \ j = 0; j <= _n - (1 << i); j++) {\n\t\t\t\tif(i)\n\t\t\t\t\td[i][j] = op(d[i\
    \ - 1][j], d[i - 1][j + (1 << i - 1)]);\n\t\t\t\telse\n\t\t\t\t\td[i][j] = v[j];\n\
    \t\t\t}\n\t\t}\n\t\tfor(int i = 2; i <= _n; i++)\n\t\t\tlt[i] = lt[i >> 1] + 1;\n\
    \t}\n\n\tS prod(int l, int r) const {\n\t\tassert(0 <= l && l <= r && r <= _n);\n\
    \t\tint len = r - l;\n\t\treturn op(d[lt[len]][l], d[lt[len]][r - (1 << lt[len])]);\n\
    \t}\n\n\tS all_prod() const { return prod(0, _n); }\n\nprivate:\n\tint _n, size,\
    \ log;\n\tstd::vector<std::vector<S>> d;\n\tstd::vector<int> lt;\n};\n#line 5\
    \ \"test/yosupo-staticrmq.test.cpp\"\n\nusing S = int;\nS op(S x, S y) { return\
    \ min(x, y); }\n\nvoid main_() {\n\tINT(n, q);\n\tVEC(int, a, n);\n\tsparse_table<S,\
    \ op> sp(a);\n\twhile(q--) {\n\t\tINT(l, r);\n\t\tprint(sp.prod(l, r));\n\t}\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"cftemp.hpp\"\n#include \"data_structure/sparse_table.hpp\"\n\nusing S = int;\n\
    S op(S x, S y) { return min(x, y); }\n\nvoid main_() {\n\tINT(n, q);\n\tVEC(int,\
    \ a, n);\n\tsparse_table<S, op> sp(a);\n\twhile(q--) {\n\t\tINT(l, r);\n\t\tprint(sp.prod(l,\
    \ r));\n\t}\n}"
  dependsOn:
  - cftemp.hpp
  - data_structure/sparse_table.hpp
  - atcoder/internal_bit.hpp
  isVerificationFile: true
  path: test/yosupo-staticrmq.test.cpp
  requiredBy: []
  timestamp: '2021-10-18 14:59:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-staticrmq.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-staticrmq.test.cpp
- /verify/test/yosupo-staticrmq.test.cpp.html
title: test/yosupo-staticrmq.test.cpp
---
