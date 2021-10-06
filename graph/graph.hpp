#pragma once
#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

struct Edge {
	int to;
	long long cost;
	Edge() = default;
	Edge(int to_, long long cost_) : to(to_), cost(cost_) {}
	bool operator<(const Edge &a) const { return cost < a.cost; }
	bool operator>(const Edge &a) const { return cost > a.cost; }
	friend std::ostream &operator<<(std::ostream &s, Edge &a) {
		s << "to: " << a.to << ", cost: " << a.cost;
		return s;
	}
};

class graph {
	std::vector<std::vector<Edge>> edges;

	template <class F>
	struct rec_lambda {
		F f;
		rec_lambda(F &&f_) : f(std::forward<F>(f_)) {}
		template <class... Args>
		auto operator()(Args &&...args) const {
			return f(*this, std::forward<Args>(args)...);
		}
	};

public:
	inline const std::vector<Edge> &operator[](int k) const { return edges[k]; }
	inline std::vector<Edge> &operator[](int k) { return edges[k]; }

	int size() const { return edges.size(); }
	void resize(const int n) { edges.resize(n); }

	graph() = default;
	graph(int n) : edges(n) {}
	graph(int n, int e, bool weight = 0, bool directed = 0, int idx = 1) : edges(n) { input(e, weight, directed, idx); }
	const long long INF = 3e18;

	void input(int e = -1, bool weight = 0, bool directed = false, int idx = 1) {
		if(e == -1) e = size() - 1;
		while(e--) {
			int u, v;
			long long cost = 1;
			std::cin >> u >> v;
			if(weight) std::cin >> cost;
			u -= idx, v -= idx;
			edges[u].emplace_back(v, cost);
			if(!directed) edges[v].emplace_back(u, cost);
		}
	}

	void add_edge(int u, int v, long long cost = 1, bool directed = false, int idx = 0) {
		u -= idx, v -= idx;
		edges[u].emplace_back(v, cost);
		if(!directed) edges[v].emplace_back(u, cost);
	}

	// Ο(V+E)
	std::vector<long long> bfs(int s) {
		std::vector<long long> dist(size(), INF);
		std::queue<int> que;
		dist[s] = 0;
		que.push(s);
		while(!que.empty()) {
			int v = que.front();
			que.pop();
			for(auto &e : edges[v]) {
				if(dist[e.to] != INF) continue;
				dist[e.to] = dist[v] + e.cost;
				que.push(e.to);
			}
		}
		return dist;
	}

	// Ο(V+E)
	// constraint: cost of each edge is zero or one
	std::vector<long long> zero_one_bfs(int s) {
		std::vector<long long> dist(size(), INF);
		std::deque<int> deq;
		dist[s] = 0;
		deq.push_back(s);
		while(!deq.empty()) {
			int v = deq.front();
			deq.pop_front();
			for(auto &e : edges[v]) {
				assert(0LL <= e.cost and e.cost < 2LL);
				if(e.cost and dist[e.to] > dist[v] + 1) {
					dist[e.to] = dist[v] + 1;
					deq.push_back(e.to);
				} else if(!e.cost and dist[e.to] > dist[v]) {
					dist[e.to] = dist[v];
					deq.push_front(e.to);
				}
			}
		}
		return dist;
	}

	// Ο((E+V)logV)
	// cannot reach: INF
	std::vector<long long> dijkstra(int s) {  // verified
		std::vector<long long> dist(size(), INF);
		const auto compare = [](const std::pair<long long, int> &a, const std::pair<long long, int> &b) { return a.first > b.first; };
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, decltype(compare)> que{compare};
		dist[s] = 0;
		que.emplace(0, s);
		while(!que.empty()) {
			std::pair<long long, int> p = que.top();
			que.pop();
			int v = p.second;
			if(dist[v] < p.first) continue;
			for(auto &e : edges[v]) {
				if(dist[e.to] > dist[v] + e.cost) {
					dist[e.to] = dist[v] + e.cost;
					que.emplace(dist[e.to], e.to);
				}
			}
		}
		return dist;
	}

	// Ο(VE)
	// cannot reach: INF
	// negative cycle: -INF
	std::vector<long long> bellman_ford(int s) {  // verified
		int n = size();
		std::vector<long long> res(n, INF);
		res[s] = 0;
		for(int loop = 0; loop < n - 1; loop++) {
			for(int v = 0; v < n; v++) {
				if(res[v] == INF) continue;
				for(auto &e : edges[v]) {
					res[e.to] = std::min(res[e.to], res[v] + e.cost);
				}
			}
		}
		std::queue<int> que;
		std::vector<int> chk(n);
		for(int v = 0; v < n; v++) {
			if(res[v] == INF) continue;
			for(auto &e : edges[v]) {
				if(res[e.to] > res[v] + e.cost and !chk[e.to]) {
					que.push(e.to);
					chk[e.to] = 1;
				}
			}
		}
		while(!que.empty()) {
			int now = que.front();
			que.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					que.push(e.to);
				}
			}
		}
		for(int i = 0; i < n; i++)
			if(chk[i]) res[i] = -INF;
		return res;
	}

	// Ο(V^3)
	std::vector<std::vector<long long>> warshall_floyd() {  // verified
		int n = size();
		std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, INF));
		for(int i = 0; i < n; i++) dist[i][i] = 0;
		for(int i = 0; i < n; i++)
			for(auto &e : edges[i]) dist[i][e.to] = std::min(dist[i][e.to], e.cost);
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++) {
				if(dist[i][k] == INF) continue;
				for(int j = 0; j < n; j++) {
					if(dist[k][j] == INF) continue;
					dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		return dist;
	}

	// Ο(V) (using DFS)
	// if a directed cycle exists, return {}
	std::vector<int> topological_sort() {  // verified
		std::vector<int> res;
		int n = size();
		std::vector<int> used(n, 0);
		bool not_DAG = false;
		for(int i = 0; i < n; i++) {
			rec_lambda([&](auto &&dfs, int k) -> void {
				if(not_DAG) return;
				if(used[k]) {
					if(used[k] == 1) not_DAG = true;
					return;
				}
				used[k] = 1;
				for(auto &e : edges[k]) dfs(e.to);
				used[k] = 2;
				res.push_back(k);
			})(i);
		}
		if(not_DAG) return std::vector<int>{};
		std::reverse(res.begin(), res.end());
		return res;
	}

	bool is_DAG() { return !topological_sort().empty(); }  // verified

	// Ο(V)
	// array of the distance from each vertex to the most distant vertex
	std::vector<long long> height() {  // verified
		auto vec1 = bfs(0);
		int v1 = -1, v2 = -1;
		long long dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec1[i]) dia = vec1[i], v1 = i;
		vec1 = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec1[i]) dia = vec1[i], v2 = i;
		auto vec2 = bfs(v2);
		for(int i = 0; i < int(size()); i++)
			if(vec1[i] < vec2[i]) vec1[i] = vec2[i];
		return vec1;
	}

	// O(V+E)
	// vector<(int)(0 or 1)>
	// if it is not bipartite, return {}
	std::vector<int> bipartite_grouping() {
		std::vector<int> colors(size(), -1);
		auto dfs = [&](auto self, int now, int col) -> bool {
			colors[now] = col;
			for(auto &e : edges[now]) {
				if(col == colors[e.to]) return false;
				if(colors[e.to] == -1 and !self(self, e.to, !col)) return false;
			}
			return true;
		};
		for(int i = 0; i < int(size()); i++)
			if(colors[i] == -1 and !dfs(dfs, i, 0)) return std::vector<int>{};
		return colors;
	}

	bool is_bipartite() { return !bipartite_grouping().empty(); }

	// Ο(V+E)
	// ((v1, v2), diameter)
	std::pair<std::pair<int, int>, long long> diameter() {  // verified
		auto vec = bfs(0);
		int v1 = -1, v2 = -1;
		long long dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec[i]) dia = vec[i], v1 = i;
		vec = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec[i]) dia = vec[i], v2 = i;
		std::pair<std::pair<int, int>, long long> res = {{v1, v2}, dia};
		return res;
	}

	// Ο(V+E)
	// return {s, v1, v2, ... t}
	std::vector<int> diameter_path() {
		auto vec = bfs(0);
		int v1 = -1, v2 = -1;
		long long dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec[i]) dia = vec[i], v1 = i;
		auto vec2 = bfs(v1);
		dia = -1;
		for(int i = 0; i < int(size()); i++)
			if(dia < vec2[i]) dia = vec2[i], v2 = i;
		vec = bfs(v2);
		std::vector<int> ret;
		auto dfs = [&](auto self, int now, int p) -> void {
			ret.emplace_back(now);
			if(now == v2) return;
			for(auto &[to, cost] : (*this)[now]) {
				if(vec[to] + vec2[to] == dia and to != p)
					self(self, to, now);
			}
		};
		dfs(dfs, v1, -1);
		return ret;
	}

	// Ο(V+E)
	// return subtree_size, root = root
	std::vector<int> subtree_size(const int root) {
		int n = size();
		std::vector<int> ret(n, 1);
		rec_lambda([&](auto &&dfs, int now, int p) -> void {
			for(auto &[to, cost] : (*this)[now]) {
				if(to == p) continue;
				dfs(to, now);
				ret[now] += ret[to];
			}
		})(root, -1);
		return ret;
	}

	// Ο(ElogV)
	long long prim() {  // verified
		long long res = 0;
		std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> que;
		for(auto &e : edges[0]) que.push(e);
		std::vector<int> chk(size());
		chk[0] = 1;
		int cnt = 1;
		while(cnt < size()) {
			auto e = que.top();
			que.pop();
			if(chk[e.to]) continue;
			cnt++;
			res += e.cost;
			chk[e.to] = 1;
			for(auto &e2 : edges[e.to]) que.push(e2);
		}
		return res;
	}

	// Ο(ElogE)
	long long kruskal() {  // verified
		std::vector<std::tuple<int, int, long long>> Edges;
		for(int i = 0; i < int(size()); i++)
			for(auto &e : edges[i]) Edges.emplace_back(i, e.to, e.cost);
		std::sort(Edges.begin(), Edges.end(), [](const std::tuple<int, int, long long> &a, const std::tuple<int, int, long long> &b) {
			return std::get<2>(a) < std::get<2>(b);
		});
		std::vector<int> uf_data(size(), -1);
		auto root = [&uf_data](auto self, int x) -> int {
			if(uf_data[x] < 0) return x;
			return uf_data[x] = self(self, uf_data[x]);
		};
		auto unite = [&uf_data, &root](int u, int v) -> bool {
			u = root(root, u), v = root(root, v);
			if(u == v) return false;
			if(uf_data[u] > uf_data[v]) std::swap(u, v);
			uf_data[u] += uf_data[v];
			uf_data[v] = u;
			return true;
		};
		long long ret = 0;
		for(auto &e : Edges)
			if(unite(std::get<0>(e), std::get<1>(e))) ret += std::get<2>(e);
		return ret;
	}

	graph build_mst() {
		std::vector<std::tuple<int, int, long long>> Edges;
		for(int i = 0; i < int(size()); i++)
			for(auto &e : edges[i]) Edges.emplace_back(i, e.to, e.cost);
		std::sort(Edges.begin(), Edges.end(), [](const std::tuple<int, int, long long> &a, const std::tuple<int, int, long long> &b) {
			return std::get<2>(a) < std::get<2>(b);
		});
		std::vector<int> uf_data(size(), -1);
		auto root = [&uf_data](auto self, int x) -> int {
			if(uf_data[x] < 0) return x;
			return uf_data[x] = self(self, uf_data[x]);
		};
		auto unite = [&uf_data, &root](int u, int v) -> bool {
			u = root(root, u), v = root(root, v);
			if(u == v) return false;
			if(uf_data[u] > uf_data[v]) std::swap(u, v);
			uf_data[u] += uf_data[v];
			uf_data[v] = u;
			return true;
		};
		graph g(this->size());
		for(auto &e : Edges)
			if(unite(std::get<0>(e), std::get<1>(e))) {
				g.add_edge(std::get<0>(e), std::get<1>(e), std::get<2>(e));
			}
		return g;
	}

	// O(V)
	std::vector<int> centroid() {
		int n = size();
		std::vector<int> centroid, sz(n);
		auto dfs = [&](auto self, int now, int per) -> void {
			sz[now] = 1;
			bool is_centroid = true;
			for(auto &e : edges[now]) {
				if(e.to != per) {
					self(self, e.to, now);
					sz[now] += sz[e.to];
					if(sz[e.to] > n / 2) is_centroid = false;
				}
			}
			if(n - sz[now] > n / 2) is_centroid = false;
			if(is_centroid) centroid.push_back(now);
		};
		dfs(dfs, 0, -1);
		return centroid;
	}

	// Ο(V+E)
	// directed graph from root to leaf
	graph root_to_leaf(int root = 0) {
		graph res(size());
		std::vector<int> chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add_edge(now, e.to, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}

	// Ο(V+E)
	// directed graph from leaf to root
	graph leaf_to_root(int root = 0) {
		graph res(size());
		std::vector<int> chk(size(), 0);
		chk[root] = 1;
		auto dfs = [&](auto self, int now) -> void {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				res.add_edge(e.to, now, e.cost, 1, 0);
				self(self, e.to);
			}
		};
		dfs(dfs, root);
		return res;
	}

	// long long Chu_Liu_Edmonds(int root = 0) {}
};
