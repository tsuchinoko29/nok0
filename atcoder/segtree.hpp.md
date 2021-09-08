---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: multi.hpp
    title: multi.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-2235.test.cpp
    title: test/aoj-2235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-2600.test.cpp
    title: test/aoj-2600.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-2703.test.cpp
    title: test/aoj-2703.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-dsl-2-b.test.cpp
    title: test/aoj-dsl-2-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-a.test.cpp
    title: test/aoj-grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-b.test.cpp
    title: test/aoj-grl-1-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-c.test.cpp
    title: test/aoj-grl-1-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-2-a.test.cpp
    title: test/aoj-grl-2-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-3-a.test.cpp
    title: test/aoj-grl-3-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-3-b.test.cpp
    title: test/aoj-grl-3-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-3-c.test.cpp
    title: test/aoj-grl-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-4-a.test.cpp
    title: test/aoj-grl-4-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-4-b.test.cpp
    title: test/aoj-grl-4-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-a.test.cpp
    title: test/aoj-grl-5-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-b.test.cpp
    title: test/aoj-grl-5-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-c.test.cpp
    title: test/aoj-grl-5-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-d.test.cpp
    title: test/aoj-grl-5-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-5-e.test.cpp
    title: test/aoj-grl-5-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-division_of_polynomials.test.cpp
    title: test/yosupo-division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-exp_of_formal_power_series.test.cpp
    title: test/yosupo-exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-factorize.test.cpp
    title: test/yosupo-factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-inv_of_formal_power_series.test.cpp
    title: test/yosupo-inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-lca.test.cpp
    title: test/yosupo-lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-log_of_formal_power_series.test.cpp
    title: test/yosupo-log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-pow_of_formal_power_series.test.cpp
    title: test/yosupo-pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-predecessor_problem.test.cpp
    title: test/yosupo-predecessor_problem.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-scc.test.cpp
    title: test/yosupo-scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-set_xor_min.test.cpp
    title: test/yosupo-set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-tree_diameter.test.cpp
    title: test/yosupo-tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-two_edge_connected_components.test.cpp
    title: test/yosupo-two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-vertex_add_path_sum.test.cpp
    title: test/yosupo-vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-vertex_add_subtree_sum.test.cpp
    title: test/yosupo-vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/segtree.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n\
    #ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative `x` s.t.\
    \ `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return\
    \ minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int bsf_constexpr(unsigned\
    \ int n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n\
    }\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 <<\
    \ x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9\
    \ \"atcoder/segtree.hpp\"\n\nnamespace atcoder {\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\n  public:\n    segtree() : segtree(0) {}\n \
    \   explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    explicit\
    \ segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        log = internal::ceil_pow2(_n);\n\
    \        size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n      \
    \  for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size\
    \ - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < _n);\n        return d[p +\
    \ size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() const { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) const {\n        return max_right(l, [](S x) { return f(x); });\n    }\n\
    \    template <class F> int max_right(int l, F f) const {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n \
    \       l += size;\n        S sm = e();\n        do {\n            while (l %\
    \ 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
    \ (*f)(S)> int min_left(int r) const {\n        return min_left(r, [](S x) { return\
    \ f(x); });\n    }\n    template <class F> int min_left(int r, F f) const {\n\
    \        assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if (r ==\
    \ 0) return 0;\n        r += size;\n        S sm = e();\n        do {\n      \
    \      r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (2 * r\
    \ + 1);\n                    if (f(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n\n    void\
    \ update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_SEGTREE_HPP\n#define ATCODER_SEGTREE_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n#include \"atcoder/internal_bit\"\n\n\
    namespace atcoder {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct segtree\
    \ {\n  public:\n    segtree() : segtree(0) {}\n    explicit segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        log = internal::ceil_pow2(_n);\n        size = 1 << log;\n      \
    \  d = std::vector<S>(2 * size, e());\n        for (int i = 0; i < _n; i++) d[size\
    \ + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    S get(int p) const {\n        assert(0 <=\
    \ p && p < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(),\
    \ smr = e();\n        l += size;\n        r += size;\n\n        while (l < r)\
    \ {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr\
    \ = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n\n    S all_prod() const { return d[1];\
    \ }\n\n    template <bool (*f)(S)> int max_right(int l) const {\n        return\
    \ max_right(l, [](S x) { return f(x); });\n    }\n    template <class F> int max_right(int\
    \ l, F f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n\
    \        if (l == _n) return _n;\n        l += size;\n        S sm = e();\n  \
    \      do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l = (2 *\
    \ l);\n                    if (f(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    r = (2 * r + 1);\n                    if (f(op(d[r],\
    \ sm))) {\n                        sm = op(d[r], sm);\n                      \
    \  r--;\n                    }\n                }\n                return r +\
    \ 1 - size;\n            }\n            sm = op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n, size, log;\n\
    \    std::vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_SEGTREE_HPP\n"
  dependsOn:
  - atcoder/internal_bit.hpp
  isVerificationFile: false
  path: atcoder/segtree.hpp
  requiredBy:
  - multi.hpp
  - template.hpp
  timestamp: '2021-09-08 15:21:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-two_edge_connected_components.test.cpp
  - test/aoj-grl-3-b.test.cpp
  - test/yosupo-predecessor_problem.test.cpp
  - test/aoj-grl-4-b.test.cpp
  - test/aoj-grl-4-a.test.cpp
  - test/yosupo-tree_diameter.test.cpp
  - test/aoj-grl-1-a.test.cpp
  - test/yosupo-division_of_polynomials.test.cpp
  - test/yosupo-lca.test.cpp
  - test/yosupo-inv_of_formal_power_series.test.cpp
  - test/aoj-grl-3-c.test.cpp
  - test/aoj-grl-5-e.test.cpp
  - test/aoj-2703.test.cpp
  - test/aoj-grl-5-a.test.cpp
  - test/aoj-grl-5-c.test.cpp
  - test/yosupo-set_xor_min.test.cpp
  - test/aoj-grl-1-b.test.cpp
  - test/yosupo-log_of_formal_power_series.test.cpp
  - test/yosupo-vertex_add_path_sum.test.cpp
  - test/aoj-dsl-2-b.test.cpp
  - test/aoj-2235.test.cpp
  - test/aoj-grl-3-a.test.cpp
  - test/aoj-grl-1-c.test.cpp
  - test/yosupo-pow_of_formal_power_series.test.cpp
  - test/aoj-grl-5-d.test.cpp
  - test/aoj-grl-5-b.test.cpp
  - test/yosupo-vertex_add_subtree_sum.test.cpp
  - test/aoj-2600.test.cpp
  - test/aoj-grl-2-a.test.cpp
  - test/yosupo-exp_of_formal_power_series.test.cpp
  - test/yosupo-factorize.test.cpp
  - test/yosupo-scc.test.cpp
documentation_of: atcoder/segtree.hpp
layout: document
redirect_from:
- /library/atcoder/segtree.hpp
- /library/atcoder/segtree.hpp.html
title: atcoder/segtree.hpp
---
