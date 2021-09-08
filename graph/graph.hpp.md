---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/dag_mcf.hpp
    title: graph/dag_mcf.hpp
  - icon: ':heavy_check_mark:'
    path: graph/hld.hpp
    title: graph/hld.hpp
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: graph/low_link.hpp
  - icon: ':warning:'
    path: graph/namori.hpp
    title: graph/namori.hpp
  - icon: ':x:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_doubling.hpp
    title: graph/tree_doubling.hpp
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_cc.hpp
    title: graph/two_edge_cc.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-lca.test.cpp
    title: test/yosupo-lca.test.cpp
  - icon: ':x:'
    path: test/yosupo-scc.test.cpp
    title: test/yosupo-scc.test.cpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <deque>\n#include <iostream>\n#include <queue>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\nstruct Edge {\n\tint to;\n\tlong long cost;\n\
    \tEdge() = default;\n\tEdge(int to_, long long cost_) : to(to_), cost(cost_) {}\n\
    \tbool operator<(const Edge &a) const { return cost < a.cost; }\n\tbool operator>(const\
    \ Edge &a) const { return cost > a.cost; }\n\tfriend std::ostream &operator<<(std::ostream\
    \ &s, Edge &a) {\n\t\ts << \"to: \" << a.to << \", cost: \" << a.cost;\n\t\treturn\
    \ s;\n\t}\n};\n\nclass Graph {\n\tstd::vector<std::vector<Edge>> edges;\n\n\t\
    template <class F>\n\tstruct rec_lambda {\n\t\tF f;\n\t\trec_lambda(F &&f_) :\
    \ f(std::forward<F>(f_)) {}\n\t\ttemplate <class... Args>\n\t\tauto operator()(Args\
    \ &&... args) const {\n\t\t\treturn f(*this, std::forward<Args>(args)...);\n\t\
    \t}\n\t};\n\npublic:\n\tinline const std::vector<Edge> &operator[](int k) const\
    \ { return edges[k]; }\n\tinline std::vector<Edge> &operator[](int k) { return\
    \ edges[k]; }\n\n\tint size() const { return edges.size(); }\n\tvoid resize(const\
    \ int n) { edges.resize(n); }\n\n\tGraph() = default;\n\tGraph(int n) : edges(n)\
    \ {}\n\tGraph(int n, int e, bool weight = 0, bool directed = 0, int idx = 1) :\
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
    \ from root to leaf\n\tGraph root_to_leaf(int root = 0) {\n\t\tGraph res(size());\n\
    \t\tstd::vector<int> chk(size(), 0);\n\t\tchk[root] = 1;\n\t\tauto dfs = [&](auto\
    \ self, int now) -> void {\n\t\t\tfor(auto &e : edges[now]) {\n\t\t\t\tif(chk[e.to]\
    \ == 1) continue;\n\t\t\t\tchk[e.to] = 1;\n\t\t\t\tres.add_edge(now, e.to, e.cost,\
    \ 1, 0);\n\t\t\t\tself(self, e.to);\n\t\t\t}\n\t\t};\n\t\tdfs(dfs, root);\n\t\t\
    return res;\n\t}\n\n\t// \u039F(V+E)\n\t// directed graph from leaf to root\n\t\
    Graph leaf_to_root(int root = 0) {\n\t\tGraph res(size());\n\t\tstd::vector<int>\
    \ chk(size(), 0);\n\t\tchk[root] = 1;\n\t\tauto dfs = [&](auto self, int now)\
    \ -> void {\n\t\t\tfor(auto &e : edges[now]) {\n\t\t\t\tif(chk[e.to] == 1) continue;\n\
    \t\t\t\tchk[e.to] = 1;\n\t\t\t\tres.add_edge(e.to, now, e.cost, 1, 0);\n\t\t\t\
    \tself(self, e.to);\n\t\t\t}\n\t\t};\n\t\tdfs(dfs, root);\n\t\treturn res;\n\t\
    }\n\n\t// long long Chu_Liu_Edmonds(int root = 0) {}\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <deque>\n\
    #include <iostream>\n#include <queue>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\nstruct Edge {\n\tint to;\n\tlong long cost;\n\tEdge() = default;\n\
    \tEdge(int to_, long long cost_) : to(to_), cost(cost_) {}\n\tbool operator<(const\
    \ Edge &a) const { return cost < a.cost; }\n\tbool operator>(const Edge &a) const\
    \ { return cost > a.cost; }\n\tfriend std::ostream &operator<<(std::ostream &s,\
    \ Edge &a) {\n\t\ts << \"to: \" << a.to << \", cost: \" << a.cost;\n\t\treturn\
    \ s;\n\t}\n};\n\nclass Graph {\n\tstd::vector<std::vector<Edge>> edges;\n\n\t\
    template <class F>\n\tstruct rec_lambda {\n\t\tF f;\n\t\trec_lambda(F &&f_) :\
    \ f(std::forward<F>(f_)) {}\n\t\ttemplate <class... Args>\n\t\tauto operator()(Args\
    \ &&... args) const {\n\t\t\treturn f(*this, std::forward<Args>(args)...);\n\t\
    \t}\n\t};\n\npublic:\n\tinline const std::vector<Edge> &operator[](int k) const\
    \ { return edges[k]; }\n\tinline std::vector<Edge> &operator[](int k) { return\
    \ edges[k]; }\n\n\tint size() const { return edges.size(); }\n\tvoid resize(const\
    \ int n) { edges.resize(n); }\n\n\tGraph() = default;\n\tGraph(int n) : edges(n)\
    \ {}\n\tGraph(int n, int e, bool weight = 0, bool directed = 0, int idx = 1) :\
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
    \ from root to leaf\n\tGraph root_to_leaf(int root = 0) {\n\t\tGraph res(size());\n\
    \t\tstd::vector<int> chk(size(), 0);\n\t\tchk[root] = 1;\n\t\tauto dfs = [&](auto\
    \ self, int now) -> void {\n\t\t\tfor(auto &e : edges[now]) {\n\t\t\t\tif(chk[e.to]\
    \ == 1) continue;\n\t\t\t\tchk[e.to] = 1;\n\t\t\t\tres.add_edge(now, e.to, e.cost,\
    \ 1, 0);\n\t\t\t\tself(self, e.to);\n\t\t\t}\n\t\t};\n\t\tdfs(dfs, root);\n\t\t\
    return res;\n\t}\n\n\t// \u039F(V+E)\n\t// directed graph from leaf to root\n\t\
    Graph leaf_to_root(int root = 0) {\n\t\tGraph res(size());\n\t\tstd::vector<int>\
    \ chk(size(), 0);\n\t\tchk[root] = 1;\n\t\tauto dfs = [&](auto self, int now)\
    \ -> void {\n\t\t\tfor(auto &e : edges[now]) {\n\t\t\t\tif(chk[e.to] == 1) continue;\n\
    \t\t\t\tchk[e.to] = 1;\n\t\t\t\tres.add_edge(e.to, now, e.cost, 1, 0);\n\t\t\t\
    \tself(self, e.to);\n\t\t\t}\n\t\t};\n\t\tdfs(dfs, root);\n\t\treturn res;\n\t\
    }\n\n\t// long long Chu_Liu_Edmonds(int root = 0) {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy:
  - graph/low_link.hpp
  - graph/hld.hpp
  - graph/two_edge_cc.hpp
  - graph/dag_mcf.hpp
  - graph/tree_doubling.hpp
  - graph/namori.hpp
  - graph/scc.hpp
  timestamp: '2021-09-07 20:08:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-two_edge_connected_components.test.cpp
  - test/yosupo-tree_diameter.test.cpp
  - test/yosupo-lca.test.cpp
  - test/yosupo-vertex_add_path_sum.test.cpp
  - test/yosupo-vertex_add_subtree_sum.test.cpp
  - test/yosupo-scc.test.cpp
documentation_of: graph/graph.hpp
layout: document
redirect_from:
- /library/graph/graph.hpp
- /library/graph/graph.hpp.html
title: graph/graph.hpp
---
