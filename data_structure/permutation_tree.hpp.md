---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/permutation_tree.hpp\"\n#include <iostream>\n\
    #include <stack>\n#include <vector>\n\n#line 1 \"atcoder/lazysegtree.hpp\"\n\n\
    \n\n#include <algorithm>\n#include <cassert>\n#line 8 \"atcoder/lazysegtree.hpp\"\
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
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 10 \"atcoder/lazysegtree.hpp\"\
    \n\nnamespace atcoder {\n\ntemplate <class S,\n          S (*op)(S, S),\n    \
    \      S (*e)(),\n          class F,\n          S (*mapping)(F, S),\n        \
    \  F (*composition)(F, F),\n          F (*id)()>\nstruct lazy_segtree {\n  public:\n\
    \    lazy_segtree() : lazy_segtree(0) {}\n    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        log = internal::ceil_pow2(_n);\n        size = 1 << log;\n      \
    \  d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size, id());\n\
    \        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i\
    \ = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n   \
    \ void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n   \
    \     for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return e();\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    S sml = e(), smr = e();\n        while (l < r) {\n            if (l & 1)\
    \ sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n    \
    \        l >>= 1;\n            r >>= 1;\n        }\n\n        return op(sml, smr);\n\
    \    }\n\n    S all_prod() { return d[1]; }\n\n    void apply(int p, F f) {\n\
    \        assert(0 <= p && p < _n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p]);\n        for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n    void apply(int l, int r, F\
    \ f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n       \
    \     int l2 = l, r2 = r;\n            while (l < r) {\n                if (l\
    \ & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r, f);\n   \
    \             l >>= 1;\n                r >>= 1;\n            }\n            l\
    \ = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i <= log; i++)\
    \ {\n            if (((l >> i) << i) != l) update(l >> i);\n            if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n    template <bool\
    \ (*g)(S)> int max_right(int l) {\n        return max_right(l, [](S x) { return\
    \ g(x); });\n    }\n    template <class G> int max_right(int l, G g) {\n     \
    \   assert(0 <= l && l <= _n);\n        assert(g(e()));\n        if (l == _n)\
    \ return _n;\n        l += size;\n        for (int i = log; i >= 1; i--) push(l\
    \ >> i);\n        S sm = e();\n        do {\n            while (l % 2 == 0) l\
    \ >>= 1;\n            if (!g(op(sm, d[l]))) {\n                while (l < size)\
    \ {\n                    push(l);\n                    l = (2 * l);\n        \
    \            if (g(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, d[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \n    template <bool (*g)(S)> int min_left(int r) {\n        return min_left(r,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int min_left(int r,\
    \ G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n      \
    \  if (r == 0) return 0;\n        r += size;\n        for (int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    push(r);\n      \
    \              r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n\
    \                        sm = op(d[r], sm);\n                        r--;\n  \
    \                  }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n  private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2\
    \ * k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n\
    \        if (k < size) lz[k] = composition(f, lz[k]);\n    }\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = id();\n    }\n};\n\n}  // namespace atcoder\n\n\n#line 6 \"data_structure/permutation_tree.hpp\"\
    \n\nnamespace monoid {\nusing S = int;\nS op(S x, S y) { return std::min(x, y);\
    \ }\nS e() { return 1 << 30; }\nusing F = int;\nS mapping(F f, S x) { return f\
    \ + x; }\nF composition(F f, F g) { return f + g; }\nF id() { return 0; }\n} \
    \ // namespace monoid\n\nstruct permutation_tree {\npublic:\n\tint sz;\n\tstd::vector<int>\
    \ parent, typ;\n\tstd::vector<std::vector<int>> children;\n\tstd::vector<std::pair<int,\
    \ int>> range, span;\n\tpermutation_tree(const std::vector<int> &vec) : vec(vec)\
    \ { build(); }\n\nprivate:\n\tstd::vector<int> vec;\n\tstd::stack<int> max_stack,\
    \ min_stack, nodes;\n\n\tusing segtree = atcoder::lazy_segtree<monoid::S,\n\t\
    \                                      monoid::op,\n\t                       \
    \               monoid::e,\n\t                                      monoid::F,\n\
    \t                                      monoid::mapping,\n\t                 \
    \                     monoid::composition,\n\t                               \
    \       monoid::id>;\n\n\tsegtree seg;\n\n\tstd::pair<int, int> get_range(std::pair<int,\
    \ int> x, std::pair<int, int> y) const {\n\t\treturn std::pair(std::min(x.first,\
    \ y.first), std::max(x.second, y.second));\n\t}\n\n\tbool adj(int i, int j) const\
    \ { return range[i].second == range[j].first; }\n\n\tint length(int i) const {\
    \ return range[i].second - range[i].first; }\n\n\tvoid add_edge(int p, int c)\
    \ {\n\t\tparent[c] = p;\n\t\tchildren[p].emplace_back(c);\n\t}\n\n\tvoid build()\
    \ {\n\t\tmax_stack = min_stack = nodes = {};\n\t\tmax_stack.push(-1);\n\t\tmin_stack.push(-1);\n\
    \t\tint n = vec.size();\n\t\tsz = n;\n\t\tparent.assign(n * 2, -1);\n\t\tchildren.assign(n\
    \ * 2, {});\n\t\trange.resize(n * 2);\n\t\tspan.resize(n * 2);\n\t\ttyp.assign(n\
    \ * 2, 0);\n\t\tseg = segtree(std::vector(n * 2, 0));\n\n\t\tfor(int i = 0; i\
    \ < n; i++) {\n\t\t\twhile(max_stack.top() != -1 and vec[max_stack.top()] < vec[i])\
    \ {\n\t\t\t\tconst int tmp = max_stack.top();\n\t\t\t\tmax_stack.pop();\n\t\t\t\
    \tseg.apply(max_stack.top() + 1, tmp + 1, vec[i] - vec[tmp]);\n\t\t\t}\n\t\t\t\
    max_stack.push(i);\n\n\t\t\twhile(min_stack.top() != -1 and vec[min_stack.top()]\
    \ > vec[i]) {\n\t\t\t\tconst int tmp = min_stack.top();\n\t\t\t\tmin_stack.pop();\n\
    \t\t\t\tseg.apply(min_stack.top() + 1, tmp + 1, vec[tmp] - vec[i]);\n\t\t\t}\n\
    \t\t\tmin_stack.push(i);\n\n\t\t\trange[i] = std::pair(vec[i], vec[i] + 1);\n\t\
    \t\tspan[i] = std::pair(i, i + 1);\n\n\t\t\tint cur = i;\n\n\t\t\twhile(true)\
    \ {\n\t\t\t\tif(!nodes.empty() and (adj(nodes.top(), cur) or adj(cur, nodes.top())))\
    \ {\n\t\t\t\t\tif(adj(nodes.top(), cur) and typ[nodes.top()] == 2 or adj(cur,\
    \ nodes.top()) and typ[nodes.top()] == 1) {\n\t\t\t\t\t\tadd_edge(nodes.top(),\
    \ cur);\n\t\t\t\t\t\trange[nodes.top()] = get_range(range[nodes.top()], range[cur]);\n\
    \t\t\t\t\t\tspan[nodes.top()] = get_range(span[nodes.top()], span[cur]);\n\t\t\
    \t\t\t\tcur = nodes.top();\n\t\t\t\t\t\tnodes.pop();\n\t\t\t\t\t} else {\n\t\t\
    \t\t\t\tadd_edge(sz, nodes.top());\n\t\t\t\t\t\tadd_edge(sz, cur);\n\t\t\t\t\t\
    \ttyp[sz] = adj(nodes.top(), cur) ? 2 : 1;\n\t\t\t\t\t\trange[sz] = get_range(range[nodes.top()],\
    \ range[cur]);\n\t\t\t\t\t\tspan[sz] = get_range(span[nodes.top()], span[cur]);\n\
    \t\t\t\t\t\tcur = sz++;\n\t\t\t\t\t\tnodes.pop();\n\t\t\t\t\t}\n\t\t\t\t} else\
    \ if(i + 1 - length(cur) and seg.prod(0, i + 1 - length(cur)) == 0) {\n\t\t\t\t\
    \tint len = length(cur);\n\t\t\t\t\tstd::pair<int, int> rng = range[cur];\n\t\t\
    \t\t\tstd::pair<int, int> sp = span[cur];\n\t\t\t\t\tadd_edge(sz, cur);\n\t\t\t\
    \t\tdo {\n\t\t\t\t\t\tlen += length(nodes.top());\n\t\t\t\t\t\trng = get_range(rng,\
    \ range[nodes.top()]);\n\t\t\t\t\t\tsp = get_range(sp, span[nodes.top()]);\n\t\
    \t\t\t\t\tadd_edge(sz, nodes.top());\n\t\t\t\t\t\tnodes.pop();\n\t\t\t\t\t} while(rng.second\
    \ - rng.first != len);\n\t\t\t\t\tstd::reverse(children[sz].begin(), children[sz].end());\n\
    \t\t\t\t\trange[sz] = rng;\n\t\t\t\t\tspan[sz] = sp;\n\t\t\t\t\tcur = sz++;\n\t\
    \t\t\t} else\n\t\t\t\t\tbreak;\n\t\t\t}\n\t\t\tnodes.push(cur);\n\t\t\tseg.apply(0,\
    \ i + 1, -1);\n\t\t}\n\t\tshrink();\n\t}\n\n\tvoid shrink() {\n\t\tparent.resize(sz);\n\
    \t\tchildren.resize(sz);\n\t\trange.resize(sz);\n\t\tspan.resize(sz);\n\t\ttyp.resize(sz);\n\
    \t}\n};\n"
  code: "#include <iostream>\n#include <stack>\n#include <vector>\n\n#include \"atcoder/lazysegtree\"\
    \n\nnamespace monoid {\nusing S = int;\nS op(S x, S y) { return std::min(x, y);\
    \ }\nS e() { return 1 << 30; }\nusing F = int;\nS mapping(F f, S x) { return f\
    \ + x; }\nF composition(F f, F g) { return f + g; }\nF id() { return 0; }\n} \
    \ // namespace monoid\n\nstruct permutation_tree {\npublic:\n\tint sz;\n\tstd::vector<int>\
    \ parent, typ;\n\tstd::vector<std::vector<int>> children;\n\tstd::vector<std::pair<int,\
    \ int>> range, span;\n\tpermutation_tree(const std::vector<int> &vec) : vec(vec)\
    \ { build(); }\n\nprivate:\n\tstd::vector<int> vec;\n\tstd::stack<int> max_stack,\
    \ min_stack, nodes;\n\n\tusing segtree = atcoder::lazy_segtree<monoid::S,\n\t\
    \                                      monoid::op,\n\t                       \
    \               monoid::e,\n\t                                      monoid::F,\n\
    \t                                      monoid::mapping,\n\t                 \
    \                     monoid::composition,\n\t                               \
    \       monoid::id>;\n\n\tsegtree seg;\n\n\tstd::pair<int, int> get_range(std::pair<int,\
    \ int> x, std::pair<int, int> y) const {\n\t\treturn std::pair(std::min(x.first,\
    \ y.first), std::max(x.second, y.second));\n\t}\n\n\tbool adj(int i, int j) const\
    \ { return range[i].second == range[j].first; }\n\n\tint length(int i) const {\
    \ return range[i].second - range[i].first; }\n\n\tvoid add_edge(int p, int c)\
    \ {\n\t\tparent[c] = p;\n\t\tchildren[p].emplace_back(c);\n\t}\n\n\tvoid build()\
    \ {\n\t\tmax_stack = min_stack = nodes = {};\n\t\tmax_stack.push(-1);\n\t\tmin_stack.push(-1);\n\
    \t\tint n = vec.size();\n\t\tsz = n;\n\t\tparent.assign(n * 2, -1);\n\t\tchildren.assign(n\
    \ * 2, {});\n\t\trange.resize(n * 2);\n\t\tspan.resize(n * 2);\n\t\ttyp.assign(n\
    \ * 2, 0);\n\t\tseg = segtree(std::vector(n * 2, 0));\n\n\t\tfor(int i = 0; i\
    \ < n; i++) {\n\t\t\twhile(max_stack.top() != -1 and vec[max_stack.top()] < vec[i])\
    \ {\n\t\t\t\tconst int tmp = max_stack.top();\n\t\t\t\tmax_stack.pop();\n\t\t\t\
    \tseg.apply(max_stack.top() + 1, tmp + 1, vec[i] - vec[tmp]);\n\t\t\t}\n\t\t\t\
    max_stack.push(i);\n\n\t\t\twhile(min_stack.top() != -1 and vec[min_stack.top()]\
    \ > vec[i]) {\n\t\t\t\tconst int tmp = min_stack.top();\n\t\t\t\tmin_stack.pop();\n\
    \t\t\t\tseg.apply(min_stack.top() + 1, tmp + 1, vec[tmp] - vec[i]);\n\t\t\t}\n\
    \t\t\tmin_stack.push(i);\n\n\t\t\trange[i] = std::pair(vec[i], vec[i] + 1);\n\t\
    \t\tspan[i] = std::pair(i, i + 1);\n\n\t\t\tint cur = i;\n\n\t\t\twhile(true)\
    \ {\n\t\t\t\tif(!nodes.empty() and (adj(nodes.top(), cur) or adj(cur, nodes.top())))\
    \ {\n\t\t\t\t\tif(adj(nodes.top(), cur) and typ[nodes.top()] == 2 or adj(cur,\
    \ nodes.top()) and typ[nodes.top()] == 1) {\n\t\t\t\t\t\tadd_edge(nodes.top(),\
    \ cur);\n\t\t\t\t\t\trange[nodes.top()] = get_range(range[nodes.top()], range[cur]);\n\
    \t\t\t\t\t\tspan[nodes.top()] = get_range(span[nodes.top()], span[cur]);\n\t\t\
    \t\t\t\tcur = nodes.top();\n\t\t\t\t\t\tnodes.pop();\n\t\t\t\t\t} else {\n\t\t\
    \t\t\t\tadd_edge(sz, nodes.top());\n\t\t\t\t\t\tadd_edge(sz, cur);\n\t\t\t\t\t\
    \ttyp[sz] = adj(nodes.top(), cur) ? 2 : 1;\n\t\t\t\t\t\trange[sz] = get_range(range[nodes.top()],\
    \ range[cur]);\n\t\t\t\t\t\tspan[sz] = get_range(span[nodes.top()], span[cur]);\n\
    \t\t\t\t\t\tcur = sz++;\n\t\t\t\t\t\tnodes.pop();\n\t\t\t\t\t}\n\t\t\t\t} else\
    \ if(i + 1 - length(cur) and seg.prod(0, i + 1 - length(cur)) == 0) {\n\t\t\t\t\
    \tint len = length(cur);\n\t\t\t\t\tstd::pair<int, int> rng = range[cur];\n\t\t\
    \t\t\tstd::pair<int, int> sp = span[cur];\n\t\t\t\t\tadd_edge(sz, cur);\n\t\t\t\
    \t\tdo {\n\t\t\t\t\t\tlen += length(nodes.top());\n\t\t\t\t\t\trng = get_range(rng,\
    \ range[nodes.top()]);\n\t\t\t\t\t\tsp = get_range(sp, span[nodes.top()]);\n\t\
    \t\t\t\t\tadd_edge(sz, nodes.top());\n\t\t\t\t\t\tnodes.pop();\n\t\t\t\t\t} while(rng.second\
    \ - rng.first != len);\n\t\t\t\t\tstd::reverse(children[sz].begin(), children[sz].end());\n\
    \t\t\t\t\trange[sz] = rng;\n\t\t\t\t\tspan[sz] = sp;\n\t\t\t\t\tcur = sz++;\n\t\
    \t\t\t} else\n\t\t\t\t\tbreak;\n\t\t\t}\n\t\t\tnodes.push(cur);\n\t\t\tseg.apply(0,\
    \ i + 1, -1);\n\t\t}\n\t\tshrink();\n\t}\n\n\tvoid shrink() {\n\t\tparent.resize(sz);\n\
    \t\tchildren.resize(sz);\n\t\trange.resize(sz);\n\t\tspan.resize(sz);\n\t\ttyp.resize(sz);\n\
    \t}\n};\n"
  dependsOn:
  - atcoder/lazysegtree.hpp
  - atcoder/internal_bit.hpp
  isVerificationFile: false
  path: data_structure/permutation_tree.hpp
  requiredBy: []
  timestamp: '2021-10-04 08:35:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/permutation_tree.hpp
layout: document
redirect_from:
- /library/data_structure/permutation_tree.hpp
- /library/data_structure/permutation_tree.hpp.html
title: data_structure/permutation_tree.hpp
---
