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
    path: data_structure/binary_indexed_tree.hpp
    title: data_structure/binary_indexed_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/hld.hpp
    title: graph/hld.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo-vertex_add_path_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 1 \"data_structure/binary_indexed_tree.hpp\"\
    \n#include <vector>\n\ntemplate <typename T>\nstruct binary_indexed_tree {\nprivate:\n\
    \tint n, p;\n\tstd::vector<T> d;\n\npublic:\n\tbinary_indexed_tree() = default;\n\
    \n\tbinary_indexed_tree(int n) : n(n), d(n + 1) {\n\t\tp = 1;\n\t\twhile(p < n)\
    \ p *= 2;\n\t}\n\n\tvoid add(int i, T x = 1) {\n\t\tfor(i++; i <= n; i += i &\
    \ -i) d[i] += x;\n\t}\n\n\t//return sum[0,i)\n\tT sum(int i) {\n\t\tT res = 0;\n\
    \t\tfor(; i; i -= i & -i) res += d[i];\n\t\treturn res;\n\t}\n\n\t//return sum[l,r)\n\
    \tT sum(int l, int r) { return sum(r) - sum(l); }\n\n\t//return min(x) which satisfies\
    \ (v0 + v1 + ... + vx >= w)\n\tint lower_bound(T w) {\n\t\tif(w <= 0) return 0;\n\
    \t\tT x = 0;\n\t\tfor(int i = p; i; i /= 2) {\n\t\t\tif(i + x <= n && d[i + x]\
    \ < w) {\n\t\t\t\tw -= d[i + x];\n\t\t\t\tx += i;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ x;\n\t}\n};\n#line 2 \"graph/graph.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <deque>\n#include <iostream>\n#include <queue>\n#include <tuple>\n#include\
    \ <utility>\n#line 10 \"graph/graph.hpp\"\n\nstruct Edge {\n\tint to;\n\tlong\
    \ long cost;\n\tEdge() = default;\n\tEdge(int to_, long long cost_) : to(to_),\
    \ cost(cost_) {}\n\tbool operator<(const Edge &a) const { return cost < a.cost;\
    \ }\n\tbool operator>(const Edge &a) const { return cost > a.cost; }\n\tfriend\
    \ std::ostream &operator<<(std::ostream &s, Edge &a) {\n\t\ts << \"to: \" << a.to\
    \ << \", cost: \" << a.cost;\n\t\treturn s;\n\t}\n};\n\nclass graph {\n\tstd::vector<std::vector<Edge>>\
    \ edges;\n\n\ttemplate <class F>\n\tstruct rec_lambda {\n\t\tF f;\n\t\trec_lambda(F\
    \ &&f_) : f(std::forward<F>(f_)) {}\n\t\ttemplate <class... Args>\n\t\tauto operator()(Args\
    \ &&... args) const {\n\t\t\treturn f(*this, std::forward<Args>(args)...);\n\t\
    \t}\n\t};\n\npublic:\n\tinline const std::vector<Edge> &operator[](int k) const\
    \ { return edges[k]; }\n\tinline std::vector<Edge> &operator[](int k) { return\
    \ edges[k]; }\n\n\tint size() const { return edges.size(); }\n\tvoid resize(const\
    \ int n) { edges.resize(n); }\n\n\tgraph() = default;\n\tgraph(int n) : edges(n)\
    \ {}\n\tgraph(int n, int e, bool weight = 0, bool directed = 0, int idx = 1) :\
    \ edges(n) { input(e, weight, directed, idx); }\n\tconst long long INF = 3e18;\n\
    \n\tvoid input(int e = -1, bool weight = 0, bool directed = false, int idx = 1)\
    \ {\n\t\tif(e == -1) e = size() - 1;\n\t\twhile(e--) {\n\t\t\tint u, v;\n\t\t\t\
    long long cost = 1;\n\t\t\tstd::cin >> u >> v;\n\t\t\tif(weight) std::cin >> cost;\n\
    \t\t\tu -= idx, v -= idx;\n\t\t\tedges[u].emplace_back(v, cost);\n\t\t\tif(!directed)\
    \ edges[v].emplace_back(u, cost);\n\t\t}\n\t}\n\n\tvoid add_edge(int u, int v,\
    \ long long cost = 1, bool directed = false, int idx = 0) {\n\t\tu -= idx, v -=\
    \ idx;\n\t\tedges[u].emplace_back(v, cost);\n\t\tif(!directed) edges[v].emplace_back(u,\
    \ cost);\n\t}\n\n\t// \u039F(V+E)\n\tstd::vector<long long> bfs(int s) {\n\t\t\
    std::vector<long long> dist(size(), INF);\n\t\tstd::queue<int> que;\n\t\tdist[s]\
    \ = 0;\n\t\tque.push(s);\n\t\twhile(!que.empty()) {\n\t\t\tint v = que.front();\n\
    \t\t\tque.pop();\n\t\t\tfor(auto &e : edges[v]) {\n\t\t\t\tif(dist[e.to] != INF)\
    \ continue;\n\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\tque.push(e.to);\n\
    \t\t\t}\n\t\t}\n\t\treturn dist;\n\t}\n\n\t// \u039F(V+E)\n\t// constraint: cost\
    \ of each edge is zero or one\n\tstd::vector<long long> zero_one_bfs(int s) {\n\
    \t\tstd::vector<long long> dist(size(), INF);\n\t\tstd::deque<int> deq;\n\t\t\
    dist[s] = 0;\n\t\tdeq.push_back(s);\n\t\twhile(!deq.empty()) {\n\t\t\tint v =\
    \ deq.front();\n\t\t\tdeq.pop_front();\n\t\t\tfor(auto &e : edges[v]) {\n\t\t\t\
    \tassert(0LL <= e.cost and e.cost < 2LL);\n\t\t\t\tif(e.cost and dist[e.to] >\
    \ dist[v] + 1) {\n\t\t\t\t\tdist[e.to] = dist[v] + 1;\n\t\t\t\t\tdeq.push_back(e.to);\n\
    \t\t\t\t} else if(!e.cost and dist[e.to] > dist[v]) {\n\t\t\t\t\tdist[e.to] =\
    \ dist[v];\n\t\t\t\t\tdeq.push_front(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn\
    \ dist;\n\t}\n\n\t// \u039F((E+V)logV)\n\t// cannot reach: INF\n\tstd::vector<long\
    \ long> dijkstra(int s) {  // verified\n\t\tstd::vector<long long> dist(size(),\
    \ INF);\n\t\tconst auto compare = [](const std::pair<long long, int> &a, const\
    \ std::pair<long long, int> &b) { return a.first > b.first; };\n\t\tstd::priority_queue<std::pair<long\
    \ long, int>, std::vector<std::pair<long long, int>>, decltype(compare)> que{compare};\n\
    \t\tdist[s] = 0;\n\t\tque.emplace(0, s);\n\t\twhile(!que.empty()) {\n\t\t\tstd::pair<long\
    \ long, int> p = que.top();\n\t\t\tque.pop();\n\t\t\tint v = p.second;\n\t\t\t\
    if(dist[v] < p.first) continue;\n\t\t\tfor(auto &e : edges[v]) {\n\t\t\t\tif(dist[e.to]\
    \ > dist[v] + e.cost) {\n\t\t\t\t\tdist[e.to] = dist[v] + e.cost;\n\t\t\t\t\t\
    que.emplace(dist[e.to], e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn dist;\n\t\
    }\n\n\t// \u039F(VE)\n\t// cannot reach: INF\n\t// negative cycle: -INF\n\tstd::vector<long\
    \ long> bellman_ford(int s) {  // verified\n\t\tint n = size();\n\t\tstd::vector<long\
    \ long> res(n, INF);\n\t\tres[s] = 0;\n\t\tfor(int loop = 0; loop < n - 1; loop++)\
    \ {\n\t\t\tfor(int v = 0; v < n; v++) {\n\t\t\t\tif(res[v] == INF) continue;\n\
    \t\t\t\tfor(auto &e : edges[v]) {\n\t\t\t\t\tres[e.to] = std::min(res[e.to], res[v]\
    \ + e.cost);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tstd::queue<int> que;\n\t\tstd::vector<int>\
    \ chk(n);\n\t\tfor(int v = 0; v < n; v++) {\n\t\t\tif(res[v] == INF) continue;\n\
    \t\t\tfor(auto &e : edges[v]) {\n\t\t\t\tif(res[e.to] > res[v] + e.cost and !chk[e.to])\
    \ {\n\t\t\t\t\tque.push(e.to);\n\t\t\t\t\tchk[e.to] = 1;\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t\twhile(!que.empty()) {\n\t\t\tint now = que.front();\n\t\t\tque.pop();\n\
    \t\t\tfor(auto &e : edges[now]) {\n\t\t\t\tif(!chk[e.to]) {\n\t\t\t\t\tchk[e.to]\
    \ = 1;\n\t\t\t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tfor(int i =\
    \ 0; i < n; i++)\n\t\t\tif(chk[i]) res[i] = -INF;\n\t\treturn res;\n\t}\n\n\t\
    // \u039F(V^3)\n\tstd::vector<std::vector<long long>> warshall_floyd() {  // verified\n\
    \t\tint n = size();\n\t\tstd::vector<std::vector<long long>> dist(n, std::vector<long\
    \ long>(n, INF));\n\t\tfor(int i = 0; i < n; i++) dist[i][i] = 0;\n\t\tfor(int\
    \ i = 0; i < n; i++)\n\t\t\tfor(auto &e : edges[i]) dist[i][e.to] = std::min(dist[i][e.to],\
    \ e.cost);\n\t\tfor(int k = 0; k < n; k++)\n\t\t\tfor(int i = 0; i < n; i++) {\n\
    \t\t\t\tif(dist[i][k] == INF) continue;\n\t\t\t\tfor(int j = 0; j < n; j++) {\n\
    \t\t\t\t\tif(dist[k][j] == INF) continue;\n\t\t\t\t\tdist[i][j] = std::min(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n\t\t\t\t}\n\t\t\t}\n\t\treturn dist;\n\t}\n\n\t//\
    \ \u039F(V) (using DFS)\n\t// if a directed cycle exists, return {}\n\tstd::vector<int>\
    \ topological_sort() {  // verified\n\t\tstd::vector<int> res;\n\t\tint n = size();\n\
    \t\tstd::vector<int> used(n, 0);\n\t\tbool not_DAG = false;\n\t\tfor(int i = 0;\
    \ i < n; i++) {\n\t\t\trec_lambda([&](auto &&dfs, int k) -> void {\n\t\t\t\tif(not_DAG)\
    \ return;\n\t\t\t\tif(used[k]) {\n\t\t\t\t\tif(used[k] == 1) not_DAG = true;\n\
    \t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t\tused[k] = 1;\n\t\t\t\tfor(auto &e : edges[k])\
    \ dfs(e.to);\n\t\t\t\tused[k] = 2;\n\t\t\t\tres.push_back(k);\n\t\t\t})(i);\n\t\
    \t}\n\t\tif(not_DAG) return std::vector<int>{};\n\t\tstd::reverse(res.begin(),\
    \ res.end());\n\t\treturn res;\n\t}\n\n\tbool is_DAG() { return !topological_sort().empty();\
    \ }  // verified\n\n\t// \u039F(V)\n\t// array of the distance from each vertex\
    \ to the most distant vertex\n\tstd::vector<long long> height() {  // verified\n\
    \t\tauto vec1 = bfs(0);\n\t\tint v1 = -1, v2 = -1;\n\t\tlong long dia = -1;\n\t\
    \tfor(int i = 0; i < int(size()); i++)\n\t\t\tif(dia < vec1[i]) dia = vec1[i],\
    \ v1 = i;\n\t\tvec1 = bfs(v1);\n\t\tdia = -1;\n\t\tfor(int i = 0; i < int(size());\
    \ i++)\n\t\t\tif(dia < vec1[i]) dia = vec1[i], v2 = i;\n\t\tauto vec2 = bfs(v2);\n\
    \t\tfor(int i = 0; i < int(size()); i++)\n\t\t\tif(vec1[i] < vec2[i]) vec1[i]\
    \ = vec2[i];\n\t\treturn vec1;\n\t}\n\n\t// O(V+E)\n\t// vector<(int)(0 or 1)>\n\
    \t// if it is not bipartite, return {}\n\tstd::vector<int> bipartite_grouping()\
    \ {\n\t\tstd::vector<int> colors(size(), -1);\n\t\tauto dfs = [&](auto self, int\
    \ now, int col) -> bool {\n\t\t\tcolors[now] = col;\n\t\t\tfor(auto &e : edges[now])\
    \ {\n\t\t\t\tif(col == colors[e.to]) return false;\n\t\t\t\tif(colors[e.to] ==\
    \ -1 and !self(self, e.to, !col)) return false;\n\t\t\t}\n\t\t\treturn true;\n\
    \t\t};\n\t\tfor(int i = 0; i < int(size()); i++)\n\t\t\tif(colors[i] == -1 and\
    \ !dfs(dfs, i, 0)) return std::vector<int>{};\n\t\treturn colors;\n\t}\n\n\tbool\
    \ is_bipartite() { return !bipartite_grouping().empty(); }\n\n\t// \u039F(V+E)\n\
    \t// ((v1, v2), diameter)\n\tstd::pair<std::pair<int, int>, long long> diameter()\
    \ {  // verified\n\t\tauto vec = bfs(0);\n\t\tint v1 = -1, v2 = -1;\n\t\tlong\
    \ long dia = -1;\n\t\tfor(int i = 0; i < int(size()); i++)\n\t\t\tif(dia < vec[i])\
    \ dia = vec[i], v1 = i;\n\t\tvec = bfs(v1);\n\t\tdia = -1;\n\t\tfor(int i = 0;\
    \ i < int(size()); i++)\n\t\t\tif(dia < vec[i]) dia = vec[i], v2 = i;\n\t\tstd::pair<std::pair<int,\
    \ int>, long long> res = {{v1, v2}, dia};\n\t\treturn res;\n\t}\n\n\t// \u039F\
    (V+E)\n\t// return {s, v1, v2, ... t}\n\tstd::vector<int> diameter_path() {\n\t\
    \tauto vec = bfs(0);\n\t\tint v1 = -1, v2 = -1;\n\t\tlong long dia = -1;\n\t\t\
    for(int i = 0; i < int(size()); i++)\n\t\t\tif(dia < vec[i]) dia = vec[i], v1\
    \ = i;\n\t\tauto vec2 = bfs(v1);\n\t\tdia = -1;\n\t\tfor(int i = 0; i < int(size());\
    \ i++)\n\t\t\tif(dia < vec2[i]) dia = vec2[i], v2 = i;\n\t\tvec = bfs(v2);\n\t\
    \tstd::vector<int> ret;\n\t\tauto dfs = [&](auto self, int now, int p) -> void\
    \ {\n\t\t\tret.emplace_back(now);\n\t\t\tif(now == v2) return;\n\t\t\tfor(auto\
    \ &[to, cost] : (*this)[now]) {\n\t\t\t\tif(vec[to] + vec2[to] == dia and to !=\
    \ p)\n\t\t\t\t\tself(self, to, now);\n\t\t\t}\n\t\t};\n\t\tdfs(dfs, v1, -1);\n\
    \t\treturn ret;\n\t}\n\n\t// \u039F(V+E)\n\t// return subtree_size, root = root\n\
    \tstd::vector<int> subtree_size(const int root) {\n\t\tint n = size();\n\t\tstd::vector<int>\
    \ ret(n, 1);\n\t\trec_lambda([&](auto &&dfs, int now, int p) -> void {\n\t\t\t\
    for(auto &[to, cost] : (*this)[now]) {\n\t\t\t\tif(to == p) continue;\n\t\t\t\t\
    dfs(to, now);\n\t\t\t\tret[now] += ret[to];\n\t\t\t}\n\t\t})(root, -1);\n\t\t\
    return ret;\n\t}\n\n\t// \u039F(ElogV)\n\tlong long prim() {  // verified\n\t\t\
    long long res = 0;\n\t\tstd::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>>\
    \ que;\n\t\tfor(auto &e : edges[0]) que.push(e);\n\t\tstd::vector<int> chk(size());\n\
    \t\tchk[0] = 1;\n\t\tint cnt = 1;\n\t\twhile(cnt < size()) {\n\t\t\tauto e = que.top();\n\
    \t\t\tque.pop();\n\t\t\tif(chk[e.to]) continue;\n\t\t\tcnt++;\n\t\t\tres += e.cost;\n\
    \t\t\tchk[e.to] = 1;\n\t\t\tfor(auto &e2 : edges[e.to]) que.push(e2);\n\t\t}\n\
    \t\treturn res;\n\t}\n\n\t// \u039F(ElogE)\n\tlong long kruskal() {  // verified\n\
    \t\tstd::vector<std::tuple<int, int, long long>> Edges;\n\t\tfor(int i = 0; i\
    \ < int(size()); i++)\n\t\t\tfor(auto &e : edges[i]) Edges.emplace_back(i, e.to,\
    \ e.cost);\n\t\tstd::sort(Edges.begin(), Edges.end(), [](const std::tuple<int,\
    \ int, long long> &a, const std::tuple<int, int, long long> &b) {\n\t\t\treturn\
    \ std::get<2>(a) < std::get<2>(b);\n\t\t});\n\t\tstd::vector<int> uf_data(size(),\
    \ -1);\n\t\tauto root = [&uf_data](auto self, int x) -> int {\n\t\t\tif(uf_data[x]\
    \ < 0) return x;\n\t\t\treturn uf_data[x] = self(self, uf_data[x]);\n\t\t};\n\t\
    \tauto unite = [&uf_data, &root](int u, int v) -> bool {\n\t\t\tu = root(root,\
    \ u), v = root(root, v);\n\t\t\tif(u == v) return false;\n\t\t\tif(uf_data[u]\
    \ > uf_data[v]) std::swap(u, v);\n\t\t\tuf_data[u] += uf_data[v];\n\t\t\tuf_data[v]\
    \ = u;\n\t\t\treturn true;\n\t\t};\n\t\tlong long ret = 0;\n\t\tfor(auto &e :\
    \ Edges)\n\t\t\tif(unite(std::get<0>(e), std::get<1>(e))) ret += std::get<2>(e);\n\
    \t\treturn ret;\n\t}\n\n\t// O(V)\n\tstd::vector<int> centroid() {\n\t\tint n\
    \ = size();\n\t\tstd::vector<int> centroid, sz(n);\n\t\tauto dfs = [&](auto self,\
    \ int now, int per) -> void {\n\t\t\tsz[now] = 1;\n\t\t\tbool is_centroid = true;\n\
    \t\t\tfor(auto &e : edges[now]) {\n\t\t\t\tif(e.to != per) {\n\t\t\t\t\tself(self,\
    \ e.to, now);\n\t\t\t\t\tsz[now] += sz[e.to];\n\t\t\t\t\tif(sz[e.to] > n / 2)\
    \ is_centroid = false;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(n - sz[now] > n / 2) is_centroid\
    \ = false;\n\t\t\tif(is_centroid) centroid.push_back(now);\n\t\t};\n\t\tdfs(dfs,\
    \ 0, -1);\n\t\treturn centroid;\n\t}\n\n\t// \u039F(V+E)\n\t// directed graph\
    \ from root to leaf\n\tgraph root_to_leaf(int root = 0) {\n\t\tgraph res(size());\n\
    \t\tstd::vector<int> chk(size(), 0);\n\t\tchk[root] = 1;\n\t\tauto dfs = [&](auto\
    \ self, int now) -> void {\n\t\t\tfor(auto &e : edges[now]) {\n\t\t\t\tif(chk[e.to]\
    \ == 1) continue;\n\t\t\t\tchk[e.to] = 1;\n\t\t\t\tres.add_edge(now, e.to, e.cost,\
    \ 1, 0);\n\t\t\t\tself(self, e.to);\n\t\t\t}\n\t\t};\n\t\tdfs(dfs, root);\n\t\t\
    return res;\n\t}\n\n\t// \u039F(V+E)\n\t// directed graph from leaf to root\n\t\
    graph leaf_to_root(int root = 0) {\n\t\tgraph res(size());\n\t\tstd::vector<int>\
    \ chk(size(), 0);\n\t\tchk[root] = 1;\n\t\tauto dfs = [&](auto self, int now)\
    \ -> void {\n\t\t\tfor(auto &e : edges[now]) {\n\t\t\t\tif(chk[e.to] == 1) continue;\n\
    \t\t\t\tchk[e.to] = 1;\n\t\t\t\tres.add_edge(e.to, now, e.cost, 1, 0);\n\t\t\t\
    \tself(self, e.to);\n\t\t\t}\n\t\t};\n\t\tdfs(dfs, root);\n\t\treturn res;\n\t\
    }\n\n\t// long long Chu_Liu_Edmonds(int root = 0) {}\n};\n#line 3 \"graph/hld.hpp\"\
    \n\nstruct heavy_light_decomposition {\npublic:\n\tstd::vector<int> sz, in, out,\
    \ head, rev, par;\n\nprivate:\n\tgraph &g;\n\n\tvoid dfs_sz(int v, int p = -1)\
    \ {\n\t\tpar[v] = p;\n\t\tif(!g[v].empty() and g[v].front().to == p) std::swap(g[v].front(),\
    \ g[v].back());\n\t\tfor(auto &e : g[v]) {\n\t\t\tif(e.to == p) continue;\n\t\t\
    \tdfs_sz(e.to, v);\n\t\t\tsz[v] += sz[e.to];\n\t\t\tif(sz[g[v].front().to] < sz[e.to])\
    \ std::swap(g[v].front(), e);\n\t\t}\n\t}\n\n\tvoid dfs_hld(int v, int &t, int\
    \ p = -1) {\n\t\tin[v] = t++;\n\t\trev[in[v]] = v;\n\t\tfor(auto &e : g[v]) {\n\
    \t\t\tif(e.to == p) continue;\n\t\t\thead[e.to] = (g[v].front().to == e.to ? head[v]\
    \ : e.to);\n\t\t\tdfs_hld(e.to, t, v);\n\t\t}\n\t\tout[v] = t;\n\t}\n\n\tvoid\
    \ build(int root = 0) {\n\t\tdfs_sz(root);\n\t\tint t = 0;\n\t\thead[root] = root;\n\
    \t\tdfs_hld(root, t);\n\t}\n\npublic:\n\theavy_light_decomposition(graph &g_,\
    \ int root = 0) : g(g_) {\n\t\tint n = g.size();\n\t\tsz.resize(n, 1);\n\t\tin.resize(n);\n\
    \t\tout.resize(n);\n\t\thead.resize(n);\n\t\trev.resize(n);\n\t\tpar.resize(n);\n\
    \t\tbuild(root);\n\t}\n\n\tint level_ancestor(int v, int level) {\n\t\twhile(true)\
    \ {\n\t\t\tint u = head[v];\n\t\t\tif(in[v] - level >= in[u]) return rev[in[v]\
    \ - level];\n\t\t\tlevel -= in[v] - in[u] + 1;\n\t\t\tv = par[u];\n\t\t}\n\t}\n\
    \n\tint lowest_common_ancestor(int u, int v) {\n\t\tfor(;; v = par[head[v]]) {\n\
    \t\t\tif(in[u] > in[v]) std::swap(u, v);\n\t\t\tif(head[u] == head[v]) return\
    \ u;\n\t\t}\n\t}\n\n\t// u, v: vertex, unit: unit, q: query on a path, f: binary\
    \ operation ((T, T) -> T)\n\ttemplate <typename T, typename Q, typename F>\n\t\
    T query(int u, int v, const T &unit, const Q &q, const F &f, bool edge = false)\
    \ {\n\t\tT l = unit, r = unit;\n\t\tfor(;; v = par[head[v]]) {\n\t\t\tif(in[u]\
    \ > in[v]) std::swap(u, v), std::swap(l, r);\n\t\t\tif(head[u] == head[v]) break;\n\
    \t\t\tl = f(q(in[head[v]], in[v] + 1), l);\n\t\t}\n\t\treturn f(f(q(in[u] + edge,\
    \ in[v] + 1), l), r);\n\t}\n\n\t// u, v: vertex, q: update query\n\ttemplate <typename\
    \ Q>\n\tvoid add(int u, int v, const Q &q, bool edge = false) {\n\t\tfor(;; v\
    \ = par[head[v]]) {\n\t\t\tif(in[u] > in[v]) std::swap(u, v);\n\t\t\tif(head[u]\
    \ == head[v]) break;\n\t\t\tq(in[head[v]], in[v] + 1);\n\t\t}\n\t\tq(in[u] + edge,\
    \ in[v] + 1);\n\t}\n\n\tstd::pair<int, int> subtree(int v, bool edge = false)\
    \ { return std::pair<int, int>(in[v] + edge, out[v]); }\n};\n#line 1 \"template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
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
    \nint main() {\n\tmain_();\n\treturn 0;\n}\n#line 7 \"test/yosupo-vertex_add_path_sum.test.cpp\"\
    \n\nvoid main_() {\n\tINT(n, q);\n\tVEC(int, a, n);\n\tgraph g(n, -1, 0, 0, 0);\n\
    \n\theavy_light_decomposition hld(g);\n\n\tbinary_indexed_tree<ll> bt(n);\n\t\
    REP(i, n) { bt.add(hld.in[i], a[i]); }\n\n\tauto f = [](ll a, ll b) { return a\
    \ + b; };\n\tauto query = [&](int l, int r) { return bt.sum(l, r); };\n\n\twhile(q--)\
    \ {\n\t\tINT(type, u, v);\n\t\tif(type == 0)\n\t\t\tbt.add(hld.in[u], v);\n\t\t\
    if(type == 1)\n\t\t\tprint(hld.query(u, v, 0ll, query, f));\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"data_structure/binary_indexed_tree.hpp\"\n#include \"graph/graph.hpp\"\
    \n#include \"graph/hld.hpp\"\n#include \"template.hpp\"\n\nvoid main_() {\n\t\
    INT(n, q);\n\tVEC(int, a, n);\n\tgraph g(n, -1, 0, 0, 0);\n\n\theavy_light_decomposition\
    \ hld(g);\n\n\tbinary_indexed_tree<ll> bt(n);\n\tREP(i, n) { bt.add(hld.in[i],\
    \ a[i]); }\n\n\tauto f = [](ll a, ll b) { return a + b; };\n\tauto query = [&](int\
    \ l, int r) { return bt.sum(l, r); };\n\n\twhile(q--) {\n\t\tINT(type, u, v);\n\
    \t\tif(type == 0)\n\t\t\tbt.add(hld.in[u], v);\n\t\tif(type == 1)\n\t\t\tprint(hld.query(u,\
    \ v, 0ll, query, f));\n\t}\n}"
  dependsOn:
  - data_structure/binary_indexed_tree.hpp
  - graph/graph.hpp
  - graph/hld.hpp
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
  path: test/yosupo-vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2021-09-08 15:21:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-vertex_add_path_sum.test.cpp
- /verify/test/yosupo-vertex_add_path_sum.test.cpp.html
title: test/yosupo-vertex_add_path_sum.test.cpp
---