---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-dpl-1-d.test.cpp
    title: test/aoj-dpl-1-d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/lis.hpp\"\n#include <vector>\n\n#line 1 \"atcoder/segtree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#line 7 \"atcoder/segtree.hpp\"\
    \n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param n `0 <= n`\n\
    // @return minimum non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n\
    \    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n\
    }\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 <<\
    \ x)) != 0`\nconstexpr int bsf_constexpr(unsigned int n) {\n    int x = 0;\n \
    \   while (!(n & (1 << x))) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n//\
    \ @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned\
    \ int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9 \"atcoder/segtree.hpp\"\
    \n\nnamespace atcoder {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct\
    \ segtree {\n  public:\n    segtree() : segtree(0) {}\n    explicit segtree(int\
    \ n) : segtree(std::vector<S>(n, e())) {}\n    explicit segtree(const std::vector<S>&\
    \ v) : _n(int(v.size())) {\n        log = internal::ceil_pow2(_n);\n        size\
    \ = 1 << log;\n        d = std::vector<S>(2 * size, e());\n        for (int i\
    \ = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1;\
    \ i--) {\n            update(i);\n        }\n    }\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p] = x;\n\
    \        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int\
    \ p) const {\n        assert(0 <= p && p < _n);\n        return d[p + size];\n\
    \    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n        r +=\
    \ size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ const { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int l) const\
    \ {\n        return max_right(l, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int max_right(int l, F f) const {\n        assert(0 <= l && l <= _n);\n\
    \        assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n\
    \            if (!f(op(sm, d[l]))) {\n                while (l < size) {\n   \
    \                 l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n \
    \                       sm = op(sm, d[l]);\n                        l++;\n   \
    \                 }\n                }\n                return l - size;\n   \
    \         }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(S)> int\
    \ min_left(int r) const {\n        return min_left(r, [](S x) { return f(x); });\n\
    \    }\n    template <class F> int min_left(int r, F f) const {\n        assert(0\
    \ <= r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return 0;\n\
    \        r += size;\n        S sm = e();\n        do {\n            r--;\n   \
    \         while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    r = (2 * r + 1);\n\
    \                    if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n\n    void update(int k) { d[k]\
    \ = op(d[2 * k], d[2 * k + 1]); }\n};\n\n}  // namespace atcoder\n\n\n#line 5\
    \ \"math/lis.hpp\"\n\nnamespace longest_increasing_subsequence_impl {\nusing S\
    \ = int;\nS op(S x, S y) {\n\treturn std::max(x, y);\n}\nS e() {\n\treturn 0;\n\
    }\ntemplate <class T>\nint longest_increasing_subsequence(const std::vector<T>\
    \ &vec, bool strictly = true) {\n\tauto tmp = vec;\n\tstd::sort(tmp.begin(), tmp.end());\n\
    \ttmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());\n\tint m = tmp.size();\n\
    \tatcoder::segtree<S, op, e> seg(m);\n\tfor(const auto &v : vec) {\n\t\tint id\
    \ = std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), v));\n\
    \t\tseg.set(id, std::max(seg.get(id), seg.prod(0, id + !strictly) + 1));\n\t}\n\
    \treturn seg.all_prod();\n}\n}  // namespace longest_increasing_subsequence_impl\n\
    using longest_increasing_subsequence_impl::longest_increasing_subsequence;\n"
  code: "#pragma once\n#include <vector>\n\n#include \"atcoder/segtree\"\n\nnamespace\
    \ longest_increasing_subsequence_impl {\nusing S = int;\nS op(S x, S y) {\n\t\
    return std::max(x, y);\n}\nS e() {\n\treturn 0;\n}\ntemplate <class T>\nint longest_increasing_subsequence(const\
    \ std::vector<T> &vec, bool strictly = true) {\n\tauto tmp = vec;\n\tstd::sort(tmp.begin(),\
    \ tmp.end());\n\ttmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());\n\t\
    int m = tmp.size();\n\tatcoder::segtree<S, op, e> seg(m);\n\tfor(const auto &v\
    \ : vec) {\n\t\tint id = std::distance(tmp.begin(), std::lower_bound(tmp.begin(),\
    \ tmp.end(), v));\n\t\tseg.set(id, std::max(seg.get(id), seg.prod(0, id + !strictly)\
    \ + 1));\n\t}\n\treturn seg.all_prod();\n}\n}  // namespace longest_increasing_subsequence_impl\n\
    using longest_increasing_subsequence_impl::longest_increasing_subsequence;\n"
  dependsOn:
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  isVerificationFile: false
  path: math/lis.hpp
  requiredBy: []
  timestamp: '2021-10-26 10:11:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-dpl-1-d.test.cpp
documentation_of: math/lis.hpp
layout: document
redirect_from:
- /library/math/lis.hpp
- /library/math/lis.hpp.html
title: math/lis.hpp
---
