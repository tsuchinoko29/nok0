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
  bundledCode: "#line 1 \"data_structure/permutation_tree.hpp\"\n#include <atcoder/lazysegtree>\n\
    #include <iostream>\n#include <stack>\n#include <vector>\n\nnamespace monoid {\n\
    using S = int;\nS op(S x, S y) { return std::min(x, y); }\nS e() { return 1 <<\
    \ 30; }\nusing F = int;\nS mapping(F f, S x) { return f + x; }\nF composition(F\
    \ f, F g) { return f + g; }\nF id() { return 0; }\n}  // namespace monoid\n\n\
    struct permutation_tree {\npublic:\n\tint sz;\n\tstd::vector<int> parent, typ;\n\
    \tstd::vector<std::vector<int>> children;\n\tstd::vector<std::pair<int, int>>\
    \ range, span;\n\tpermutation_tree(const std::vector<int> &vec) : vec(vec) { build();\
    \ }\n\nprivate:\n\tstd::vector<int> vec;\n\tstd::stack<int> max_stack, min_stack,\
    \ nodes;\n\n\tusing segtree = atcoder::lazy_segtree<monoid::S,\n\t           \
    \                           monoid::op,\n\t                                  \
    \    monoid::e,\n\t                                      monoid::F,\n\t      \
    \                                monoid::mapping,\n\t                        \
    \              monoid::composition,\n\t                                      monoid::id>;\n\
    \n\tsegtree seg;\n\n\tstd::pair<int, int> get_range(std::pair<int, int> x, std::pair<int,\
    \ int> y) const {\n\t\treturn std::pair(std::min(x.first, y.first), std::max(x.second,\
    \ y.second));\n\t}\n\n\tbool adj(int i, int j) const { return range[i].second\
    \ == range[j].first; }\n\n\tint length(int i) const { return range[i].second -\
    \ range[i].first; }\n\n\tvoid add_edge(int p, int c) {\n\t\tparent[c] = p;\n\t\
    \tchildren[p].emplace_back(c);\n\t}\n\n\tvoid build() {\n\t\tmax_stack = min_stack\
    \ = nodes = {};\n\t\tmax_stack.push(-1);\n\t\tmin_stack.push(-1);\n\t\tint n =\
    \ vec.size();\n\t\tsz = n;\n\t\tparent.assign(n * 2, -1);\n\t\tchildren.assign(n\
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
  code: "#include <atcoder/lazysegtree>\n#include <iostream>\n#include <stack>\n#include\
    \ <vector>\n\nnamespace monoid {\nusing S = int;\nS op(S x, S y) { return std::min(x,\
    \ y); }\nS e() { return 1 << 30; }\nusing F = int;\nS mapping(F f, S x) { return\
    \ f + x; }\nF composition(F f, F g) { return f + g; }\nF id() { return 0; }\n\
    }  // namespace monoid\n\nstruct permutation_tree {\npublic:\n\tint sz;\n\tstd::vector<int>\
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
  timestamp: '2021-09-08 15:21:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/permutation_tree.hpp
layout: document
redirect_from:
- /library/data_structure/permutation_tree.hpp
- /library/data_structure/permutation_tree.hpp.html
title: data_structure/permutation_tree.hpp
---
