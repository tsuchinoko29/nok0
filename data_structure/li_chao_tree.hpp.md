---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-line_add_get_min.test.cpp
    title: test/yosupo-line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-segment_add_get_min.test.cpp
    title: test/yosupo-segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/li_chao_tree.hpp\"\n#include <algorithm>\n\
    #include <limits>\n#include <vector>\n\ntemplate <class T>\nstruct li_chao_tree\
    \ {\npublic:\n\tconst T INF = std::numeric_limits<T>::max();\n\n\tli_chao_tree(const\
    \ std::vector<T>& xs_) : xs(xs_) {\n\t\tsort(xs.begin(), xs.end());\n\t\txs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n\t\tn = xs.size();\n\t\tfs.assign(n << 1, line(T(0),\
    \ INF));\n\t}\n\n\t//add f(x) = ax + b\n\tvoid add_line(T a, T b) { update(a,\
    \ b, 0, n); }\n\n\t//add f(x) = ax + b\u3000(x \u2208 [xl, xr) (if closed, [xl,\
    \ xr]))\n\tvoid add_segment(T a, T b, T xl, T xr, bool closed = false) {\n\t\t\
    int l = index(xl), r = index(xr);\n\t\tif(closed) r++;\n\t\tupdate(a, b, l, r);\n\
    \t}\n\n\tT get_min(T x) const {\n\t\tint i = index(x);\n\t\tT ret = INF;\n\t\t\
    for(i += n; i; i >>= 1) ret = std::min(ret, fs[i](x));\n\t\treturn ret;\n\t}\n\
    \nprivate:\n\tstruct line {\n\t\tT a, b;\n\t\tline(T a, T b) : a(a), b(b) {}\n\
    \t\tT operator()(T x) const { return a * x + b; }\n\t};\n\tint n;\n\tstd::vector<line>\
    \ fs;\n\tstd::vector<T> xs;\n\n\tint index(T x) const { return std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), x)); }\n\n\tvoid update(T a, T b, int\
    \ l, int r) {\n\t\tline g(a, b);\n\t\tfor(l += n, r += n; l < r; l >>= 1, r >>=\
    \ 1) {\n\t\t\tif(l & 1) descend(g, l++);\n\t\t\tif(r & 1) descend(g, --r);\n\t\
    \t}\n\t}\n\n\tvoid descend(line g, int i) {\n\t\tint l = i, r = i + 1;\n\t\twhile(l\
    \ < n) l <<= 1, r <<= 1;\n\t\twhile(l < r) {\n\t\t\tint c = (l + r) >> 1;\n\t\t\
    \tT xl = xs[l - n], xr = xs[r - 1 - n], xc = xs[c - n];\n\t\t\tline& f = fs[i];\n\
    \t\t\tif(f(xl) <= g(xl) and f(xr) <= g(xr)) return;\n\t\t\tif(f(xl) >= g(xl) and\
    \ f(xr) >= g(xr)) {\n\t\t\t\tf = g;\n\t\t\t\treturn;\n\t\t\t}\n\t\t\tif(f(xc)\
    \ > g(xc)) std::swap(f, g);\n\t\t\tif(f(xl) > g(xl))\n\t\t\t\ti = i << 1 | 0,\
    \ r = c;\n\t\t\telse\n\t\t\t\ti = i << 1 | 1, l = c;\n\t\t}\n\t}\n};\n"
  code: "#include <algorithm>\n#include <limits>\n#include <vector>\n\ntemplate <class\
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
    i = i << 1 | 1, l = c;\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2021-09-08 20:41:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-segment_add_get_min.test.cpp
  - test/yosupo-line_add_get_min.test.cpp
documentation_of: data_structure/li_chao_tree.hpp
layout: document
redirect_from:
- /library/data_structure/li_chao_tree.hpp
- /library/data_structure/li_chao_tree.hpp.html
title: data_structure/li_chao_tree.hpp
---
