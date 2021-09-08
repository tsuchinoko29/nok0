---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':question:'
    path: atcoder/dsu.hpp
    title: atcoder/dsu.hpp
  - icon: ':question:'
    path: atcoder/fenwicktree.hpp
    title: atcoder/fenwicktree.hpp
  - icon: ':question:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':question:'
    path: atcoder/internal_csr.hpp
    title: atcoder/internal_csr.hpp
  - icon: ':question:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':question:'
    path: atcoder/internal_queue.hpp
    title: atcoder/internal_queue.hpp
  - icon: ':question:'
    path: atcoder/internal_scc.hpp
    title: atcoder/internal_scc.hpp
  - icon: ':question:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':question:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':question:'
    path: atcoder/math.hpp
    title: atcoder/math.hpp
  - icon: ':question:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  - icon: ':question:'
    path: atcoder/mincostflow.hpp
    title: atcoder/mincostflow.hpp
  - icon: ':question:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':question:'
    path: atcoder/scc.hpp
    title: atcoder/scc.hpp
  - icon: ':question:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':question:'
    path: atcoder/string.hpp
    title: atcoder/string.hpp
  - icon: ':question:'
    path: atcoder/twosat.hpp
    title: atcoder/twosat.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/li_chao_tree.hpp
    title: data_structure/li_chao_tree.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo-line_add_get_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#line 1 \"data_structure/li_chao_tree.hpp\"\
    \n#include <algorithm>\n#include <limits>\n#include <vector>\n\ntemplate <class\
    \ T>\nstruct li_chao_tree {\npublic:\n\tconst T INF = std::numeric_limits<T>::max();\n\
    \n\tli_chao_tree(const std::vector<T>& xs_) : xs(xs_) {\n\t\tsort(xs.begin(),\
    \ xs.end());\n\t\txs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\t\t\
    n = xs.size();\n\t\tfs.assign(n << 1, line(T(0), INF));\n\t}\n\n\t//add f(x) =\
    \ ax + b\n\tvoid add_line(T a, T b) { update(a, b, 0, n); }\n\n\t//add f(x) =\
    \ ax + b\u3000(x \u2208 [xl, xr) (if closed, [xl, xr]))\n\tvoid add_segment(T\
    \ a, T b, T xl, T xr, bool closed = false) {\n\t\tint l = index(xl), r = index(xr);\n\
    \t\tif(closed) r++;\n\t\tupdate(a, b, l, r);\n\t}\n\n\tT get_min(T x) const {\n\
    \t\tint i = index(x);\n\t\tT ret = INF;\n\t\tfor(i += n; i; i >>= 1) ret = std::min(ret,\
    \ fs[i](x));\n\t\treturn ret;\n\t}\n\nprivate:\n\tstruct line {\n\t\tT a, b;\n\
    \t\tline(T a, T b) : a(a), b(b) {}\n\t\tT operator()(T x) const { return a * x\
    \ + b; }\n\t};\n\tint n;\n\tstd::vector<line> fs;\n\tstd::vector<T> xs;\n\n\t\
    int index(T x) const { return std::distance(xs.begin(), std::lower_bound(xs.begin(),\
    \ xs.end(), x)); }\n\n\tvoid update(T a, T b, int l, int r) {\n\t\tline g(a, b);\n\
    \t\tfor(l += n, r += n; l < r; l >>= 1, r >>= 1) {\n\t\t\tif(l & 1) descend(g,\
    \ l++);\n\t\t\tif(r & 1) descend(g, --r);\n\t\t}\n\t}\n\n\tvoid descend(line g,\
    \ int i) {\n\t\tint l = i, r = i + 1;\n\t\twhile(l < n) l <<= 1, r <<= 1;\n\t\t\
    while(l < r) {\n\t\t\tint c = (l + r) >> 1;\n\t\t\tT xl = xs[l - n], xr = xs[r\
    \ - 1 - n], xc = xs[c - n];\n\t\t\tline& f = fs[i];\n\t\t\tif(f(xl) <= g(xl) and\
    \ f(xr) <= g(xr)) return;\n\t\t\tif(f(xl) >= g(xl) and f(xr) >= g(xr)) {\n\t\t\
    \t\tf = g;\n\t\t\t\treturn;\n\t\t\t}\n\t\t\tif(f(xc) > g(xc)) std::swap(f, g);\n\
    \t\t\tif(f(xl) > g(xl))\n\t\t\t\ti = i << 1 | 0, r = c;\n\t\t\telse\n\t\t\t\t\
    i = i << 1 | 1, l = c;\n\t\t}\n\t}\n};\n#line 1 \"template.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#if __has_include(<atcoder/all>)\n#include <atcoder/all>\n\
    using namespace atcoder;\n#endif\n\n#pragma region Macros\n// rep macro\n#define\
    \ foa(v, a) for(auto &v : a)\n#define REPname(a, b, c, d, e, ...) e\n#define REP(...)\
    \ REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)\n#define REP0(x) for(int\
    \ i = 0; i < (x); ++i)\n#define REP1(i, x) for(int i = 0; i < (x); ++i)\n#define\
    \ REP2(i, l, r) for(int i = (l); i < (r); ++i)\n#define REP3(i, l, r, c) for(int\
    \ i = (l); i < (r); i += (c))\n#define REPSname(a, b, c, ...) c\n#define REPS(...)\
    \ REPSname(__VA_ARGS__, REPS1, REPS0)(__VA_ARGS__)\n#define REPS0(x) for(int i\
    \ = 1; i <= (x); ++i)\n#define REPS1(i, x) for(int i = 1; i <= (x); ++i)\n#define\
    \ RREPname(a, b, c, d, e, ...) e\n#define RREP(...) RREPname(__VA_ARGS__, RREP3,\
    \ RREP2, RREP1, RREP0)(__VA_ARGS__)\n#define RREP0(x) for(int i = (x)-1; i >=\
    \ 0; --i)\n#define RREP1(i, x) for(int i = (x)-1; i >= 0; --i)\n#define RREP2(i,\
    \ r, l) for(int i = (r)-1; i >= (l); --i)\n#define RREP3(i, r, l, c) for(int i\
    \ = (r)-1; i >= (l); i -= (c))\n#define RREPSname(a, b, c, ...) c\n#define RREPS(...)\
    \ RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS__)\n#define RREPS0(x) for(int\
    \ i = (x); i >= 1; --i)\n#define RREPS1(i, x) for(int i = (x); i >= 1; --i)\n\n\
    // name macro\n#define pb push_back\n#define eb emplace_back\n#define SZ(x) ((int)(x).size())\n\
    #define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n\
    #define popcnt(x) __builtin_popcountll(x)\ntemplate <class T = int>\nusing V =\
    \ std::vector<T>;\ntemplate <class T = int>\nusing VV = std::vector<std::vector<T>>;\n\
    template <class T>\nusing pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\
    using ll = long long;\nusing ld = long double;\nusing int128 = __int128_t;\nusing\
    \ pii = std::pair<int, int>;\nusing pll = std::pair<long long, long long>;\n\n\
    // input macro\ntemplate <class T, class U>\nstd::istream &operator>>(std::istream\
    \ &is, std::pair<T, U> &p) {\n\tis >> p.first >> p.second;\n\treturn is;\n}\n\
    template <class T>\nstd::istream &operator>>(std::istream &is, std::vector<T>\
    \ &v) {\n\tfor(T &i : v) is >> i;\n\treturn is;\n}\nstd::istream &operator>>(std::istream\
    \ &is, __int128_t &a) {\n\tstd::string s;\n\tis >> s;\n\t__int128_t ret = 0;\n\
    \tfor(int i = 0; i < s.length(); i++)\n\t\tif('0' <= s[i] and s[i] <= '9')\n\t\
    \t\tret = 10 * ret + s[i] - '0';\n\ta = ret * (s[0] == '-' ? -1 : 1);\n\treturn\
    \ is;\n}\n#if __has_include(<atcoder/all>)\nstd::istream &operator>>(std::istream\
    \ &is, atcoder::modint998244353 &a) {\n\tlong long v;\n\tis >> v;\n\ta = v;\n\t\
    return is;\n}\nstd::istream &operator>>(std::istream &is, atcoder::modint1000000007\
    \ &a) {\n\tlong long v;\n\tis >> v;\n\ta = v;\n\treturn is;\n}\ntemplate <int\
    \ m>\nstd::istream &operator>>(std::istream &is, atcoder::static_modint<m> &a)\
    \ {\n\tlong long v;\n\tis >> v;\n\ta = v;\n\treturn is;\n}\ntemplate <int m>\n\
    std::istream &operator>>(std::istream &is, atcoder::dynamic_modint<m> &a) {\n\t\
    long long v;\n\tis >> v;\n\ta = v;\n\treturn is;\n}\n#endif\nnamespace scanner\
    \ {\nvoid scan(int &a) { std::cin >> a; }\nvoid scan(long long &a) { std::cin\
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
    \nint main() {\n\tmain_();\n\treturn 0;\n}\n#line 5 \"test/yosupo-line_add_get_min.test.cpp\"\
    \n\nvoid main_() {\n\tINT(n, q);\n\tV<ll> a(n), b(n), t(q), c(q), d(q), x;\n\t\
    REP(i, n) { cin >> a[i] >> b[i]; }\n\tREP(i, q) {\n\t\tcin >> t[i];\n\t\tif(!t[i])\n\
    \t\t\tcin >> c[i] >> d[i];\n\t\telse {\n\t\t\tcin >> c[i];\n\t\t\tx.pb(c[i]);\n\
    \t\t}\n\t}\n\tli_chao_tree<ll> lct(x);\n\tREP(i, n) { lct.add_line(a[i], b[i]);\
    \ }\n\tREP(i, q) {\n\t\tif(!t[i])\n\t\t\tlct.add_line(c[i], d[i]);\n\t\telse\n\
    \t\t\tprint(lct.get_min(c[i]));\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"data_structure/li_chao_tree.hpp\"\n#include \"template.hpp\"\n\nvoid\
    \ main_() {\n\tINT(n, q);\n\tV<ll> a(n), b(n), t(q), c(q), d(q), x;\n\tREP(i,\
    \ n) { cin >> a[i] >> b[i]; }\n\tREP(i, q) {\n\t\tcin >> t[i];\n\t\tif(!t[i])\n\
    \t\t\tcin >> c[i] >> d[i];\n\t\telse {\n\t\t\tcin >> c[i];\n\t\t\tx.pb(c[i]);\n\
    \t\t}\n\t}\n\tli_chao_tree<ll> lct(x);\n\tREP(i, n) { lct.add_line(a[i], b[i]);\
    \ }\n\tREP(i, q) {\n\t\tif(!t[i])\n\t\t\tlct.add_line(c[i], d[i]);\n\t\telse\n\
    \t\t\tprint(lct.get_min(c[i]));\n\t}\n}"
  dependsOn:
  - data_structure/li_chao_tree.hpp
  - template.hpp
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
  path: test/yosupo-line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2021-09-08 20:41:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-line_add_get_min.test.cpp
- /verify/test/yosupo-line_add_get_min.test.cpp.html
title: test/yosupo-line_add_get_min.test.cpp
---
