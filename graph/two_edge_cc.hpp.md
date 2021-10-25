---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: graph/low_link.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-two_edge_connected_components.test.cpp
    title: test/yosupo-two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <deque>\n#include <iostream>\n#include <queue>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\nstruct Edge {\n\tint to;\n\tlong long cost;\n\
    \tEdge() = default;\n\tEdge(int to_, long long cost_) : to(to_), cost(cost_) {}\n\
    \tbool operator<(const Edge &a) const { return cost < a.cost; }\n\tbool operator>(const\
    \ Edge &a) const { return cost > a.cost; }\n\tfriend std::ostream &operator<<(std::ostream\
    \ &s, Edge &a) {\n\t\ts << \"to: \" << a.to << \", cost: \" << a.cost;\n\t\treturn\
    \ s;\n\t}\n};\n\nclass graph {\n\tstd::vector<std::vector<Edge>> edges;\n\n\t\
    template <class F>\n\tstruct rec_lambda {\n\t\tF f;\n\t\trec_lambda(F &&f_) :\
    \ f(std::forward<F>(f_)) {}\n\t\ttemplate <class... Args>\n\t\tauto operator()(Args\
    \ &&...args) const {\n\t\t\treturn f(*this, std::forward<Args>(args)...);\n\t\t\
    }\n\t};\n\npublic:\n\tinline const std::vector<Edge> &operator[](int k) const\
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
    \t\treturn ret;\n\t}\n\n\tgraph build_mst() {\n\t\tstd::vector<std::tuple<int,\
    \ int, long long>> Edges;\n\t\tfor(int i = 0; i < int(size()); i++)\n\t\t\tfor(auto\
    \ &e : edges[i]) Edges.emplace_back(i, e.to, e.cost);\n\t\tstd::sort(Edges.begin(),\
    \ Edges.end(), [](const std::tuple<int, int, long long> &a, const std::tuple<int,\
    \ int, long long> &b) {\n\t\t\treturn std::get<2>(a) < std::get<2>(b);\n\t\t});\n\
    \t\tstd::vector<int> uf_data(size(), -1);\n\t\tauto root = [&uf_data](auto self,\
    \ int x) -> int {\n\t\t\tif(uf_data[x] < 0) return x;\n\t\t\treturn uf_data[x]\
    \ = self(self, uf_data[x]);\n\t\t};\n\t\tauto unite = [&uf_data, &root](int u,\
    \ int v) -> bool {\n\t\t\tu = root(root, u), v = root(root, v);\n\t\t\tif(u ==\
    \ v) return false;\n\t\t\tif(uf_data[u] > uf_data[v]) std::swap(u, v);\n\t\t\t\
    uf_data[u] += uf_data[v];\n\t\t\tuf_data[v] = u;\n\t\t\treturn true;\n\t\t};\n\
    \t\tgraph g(this->size());\n\t\tfor(auto &e : Edges)\n\t\t\tif(unite(std::get<0>(e),\
    \ std::get<1>(e))) {\n\t\t\t\tg.add_edge(std::get<0>(e), std::get<1>(e), std::get<2>(e));\n\
    \t\t\t}\n\t\treturn g;\n\t}\n\n\t// O(V)\n\tstd::vector<int> centroid() {\n\t\t\
    int n = size();\n\t\tstd::vector<int> centroid, sz(n);\n\t\tauto dfs = [&](auto\
    \ self, int now, int per) -> void {\n\t\t\tsz[now] = 1;\n\t\t\tbool is_centroid\
    \ = true;\n\t\t\tfor(auto &e : edges[now]) {\n\t\t\t\tif(e.to != per) {\n\t\t\t\
    \t\tself(self, e.to, now);\n\t\t\t\t\tsz[now] += sz[e.to];\n\t\t\t\t\tif(sz[e.to]\
    \ > n / 2) is_centroid = false;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(n - sz[now] > n\
    \ / 2) is_centroid = false;\n\t\t\tif(is_centroid) centroid.push_back(now);\n\t\
    \t};\n\t\tdfs(dfs, 0, -1);\n\t\treturn centroid;\n\t}\n\n\t// \u039F(V+E)\n\t\
    // directed graph from root to leaf\n\tgraph root_to_leaf(int root = 0) {\n\t\t\
    graph res(size());\n\t\tstd::vector<int> chk(size(), 0);\n\t\tchk[root] = 1;\n\
    \t\tauto dfs = [&](auto self, int now) -> void {\n\t\t\tfor(auto &e : edges[now])\
    \ {\n\t\t\t\tif(chk[e.to] == 1) continue;\n\t\t\t\tchk[e.to] = 1;\n\t\t\t\tres.add_edge(now,\
    \ e.to, e.cost, 1, 0);\n\t\t\t\tself(self, e.to);\n\t\t\t}\n\t\t};\n\t\tdfs(dfs,\
    \ root);\n\t\treturn res;\n\t}\n\n\t// \u039F(V+E)\n\t// directed graph from leaf\
    \ to root\n\tgraph leaf_to_root(int root = 0) {\n\t\tgraph res(size());\n\t\t\
    std::vector<int> chk(size(), 0);\n\t\tchk[root] = 1;\n\t\tauto dfs = [&](auto\
    \ self, int now) -> void {\n\t\t\tfor(auto &e : edges[now]) {\n\t\t\t\tif(chk[e.to]\
    \ == 1) continue;\n\t\t\t\tchk[e.to] = 1;\n\t\t\t\tres.add_edge(e.to, now, e.cost,\
    \ 1, 0);\n\t\t\t\tself(self, e.to);\n\t\t\t}\n\t\t};\n\t\tdfs(dfs, root);\n\t\t\
    return res;\n\t}\n\n\t// long long Chu_Liu_Edmonds(int root = 0) {}\n};\n#line\
    \ 2 \"graph/low_link.hpp\"\n\n#line 4 \"graph/low_link.hpp\"\n\nstruct low_link\
    \ {\nprivate:\n\tconst graph &graph_given;\n\tint order_next;\n\n\tvoid build()\
    \ {\n\t\tint n = graph_given.size();\n\t\torder.resize(n, -1);\n\t\tlow.resize(n);\n\
    \t\torder_next = 0;\n\t\tfor(int i = 0; i < n; i++)\n\t\t\tif(order[i] == -1)\
    \ dfs(i);\n\t}\n\n\tvoid dfs(int now, int par = -1) {\n\t\tlow[now] = order[now]\
    \ = order_next++;\n\t\tbool is_articulation = false;\n\t\tint cnt = 0, cnt_par\
    \ = 0;\n\t\tfor(const auto &ed : graph_given[now]) {\n\t\t\tconst int &nxt = ed.to;\n\
    \t\t\tif(order[nxt] == -1) {\n\t\t\t\tcnt++;\n\t\t\t\tdfs(nxt, now);\n\t\t\t\t\
    if(order[now] < low[nxt]) bridge.push_back(std::minmax(now, nxt));\n\t\t\t\tif(order[now]\
    \ <= low[nxt]) is_articulation = true;\n\t\t\t\tlow[now] = std::min(low[now],\
    \ low[nxt]);\n\t\t\t} else if(nxt != par or cnt_par++ == 1) {\n\t\t\t\tlow[now]\
    \ = std::min(low[now], order[nxt]);\n\t\t\t}\n\t\t}\n\t\tif(par == -1 and cnt\
    \ < 2) is_articulation = false;\n\t\tif(is_articulation) articulation.push_back(now);\n\
    \t\treturn;\n\t}\n\npublic:\n\tstd::vector<int> order, low, articulation;\n\t\
    std::vector<std::pair<int, int>> bridge;\n\tlow_link() = default;\n\tlow_link(const\
    \ graph &g_) : graph_given(g_) { build(); }\n};\n#line 4 \"graph/two_edge_cc.hpp\"\
    \n\nstruct two_edge_connected_components {\nprivate:\n\tconst graph &graph_given;\n\
    \tint group_next;\n\tlow_link li;\n\tstd::vector<int> group_number;\n\n\tvoid\
    \ build(bool create_compressed_graph) {\n\t\tint n = graph_given.size();\n\t\t\
    group_number.resize(n, -1);\n\t\tgroup_next = 0;\n\t\tfor(int i = 0; i < n; i++)\n\
    \t\t\tif(group_number[i] == -1) dfs(i);\n\t\tgroups.resize(group_next);\n\t\t\
    for(int i = 0; i < graph_given.size(); i++) groups[group_number[i]].push_back(i);\n\
    \n\t\tif(create_compressed_graph) {\n\t\t\tgraph_compressed.resize(group_next);\n\
    \t\t\tfor(auto [u, v] : li.bridge) {\n\t\t\t\tint x = group_number[u], y = group_number[v];\n\
    \t\t\t\tgraph_compressed.add_edge(x, y);\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid dfs(int\
    \ now, int par = -1) {\n\t\tif(par != -1 and li.order[par] >= li.low[now])\n\t\
    \t\tgroup_number[now] = group_number[par];\n\t\telse\n\t\t\tgroup_number[now]\
    \ = group_next++;\n\t\tfor(const auto &e : graph_given[now])\n\t\t\tif(group_number[e.to]\
    \ == -1) dfs(e.to, now);\n\t}\n\npublic:\n\tgraph graph_compressed;\n\tstd::vector<std::vector<int>>\
    \ groups;\n\ttwo_edge_connected_components(const graph &g_, bool create_compressed_graph\
    \ = false)\n\t  : graph_given(g_), li(g_) {\n\t\tbuild(create_compressed_graph);\n\
    \t}\n\n\tconst int &operator[](const int k) { return group_number[k]; }\n};\n"
  code: "#pragma once\n#include \"graph/graph.hpp\"\n#include \"low_link.hpp\"\n\n\
    struct two_edge_connected_components {\nprivate:\n\tconst graph &graph_given;\n\
    \tint group_next;\n\tlow_link li;\n\tstd::vector<int> group_number;\n\n\tvoid\
    \ build(bool create_compressed_graph) {\n\t\tint n = graph_given.size();\n\t\t\
    group_number.resize(n, -1);\n\t\tgroup_next = 0;\n\t\tfor(int i = 0; i < n; i++)\n\
    \t\t\tif(group_number[i] == -1) dfs(i);\n\t\tgroups.resize(group_next);\n\t\t\
    for(int i = 0; i < graph_given.size(); i++) groups[group_number[i]].push_back(i);\n\
    \n\t\tif(create_compressed_graph) {\n\t\t\tgraph_compressed.resize(group_next);\n\
    \t\t\tfor(auto [u, v] : li.bridge) {\n\t\t\t\tint x = group_number[u], y = group_number[v];\n\
    \t\t\t\tgraph_compressed.add_edge(x, y);\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid dfs(int\
    \ now, int par = -1) {\n\t\tif(par != -1 and li.order[par] >= li.low[now])\n\t\
    \t\tgroup_number[now] = group_number[par];\n\t\telse\n\t\t\tgroup_number[now]\
    \ = group_next++;\n\t\tfor(const auto &e : graph_given[now])\n\t\t\tif(group_number[e.to]\
    \ == -1) dfs(e.to, now);\n\t}\n\npublic:\n\tgraph graph_compressed;\n\tstd::vector<std::vector<int>>\
    \ groups;\n\ttwo_edge_connected_components(const graph &g_, bool create_compressed_graph\
    \ = false)\n\t  : graph_given(g_), li(g_) {\n\t\tbuild(create_compressed_graph);\n\
    \t}\n\n\tconst int &operator[](const int k) { return group_number[k]; }\n};\n"
  dependsOn:
  - graph/graph.hpp
  - graph/low_link.hpp
  isVerificationFile: false
  path: graph/two_edge_cc.hpp
  requiredBy: []
  timestamp: '2021-10-06 20:07:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-two_edge_connected_components.test.cpp
documentation_of: graph/two_edge_cc.hpp
layout: document
redirect_from:
- /library/graph/two_edge_cc.hpp
- /library/graph/two_edge_cc.hpp.html
title: graph/two_edge_cc.hpp
---
