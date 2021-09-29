#pragma once
#include "graph/graph.hpp"

struct tree_doubling {
private:
	std::vector<std::vector<int>> parent;
	std::vector<int> depth;
	std::vector<long long> dist;
	int max_jump = 1;

	void build() {
		for(int i = 0; i < max_jump - 1; i++) {
			for(int v = 0; v < (int)dist.size(); v++) {
				if(parent[i][v] == -1)
					parent[i + 1][v] = -1;
				else
					parent[i + 1][v] = parent[i][parent[i][v]];
			}
		}
	}

public:
	tree_doubling() = default;
	tree_doubling(const graph &g, const int root = 0) : dist(g.size()), depth(g.size()) {
		int n = g.size();
		while((1 << max_jump) < n) max_jump++;
		parent.assign(max_jump, std::vector<int>(n, -1));
		auto dfs = [&](auto self, int now, int per, int d, long long cost) -> void {
			parent[0][now] = per;
			depth[now] = d;
			dist[now] = cost;
			for(auto &e : g[now])
				if(e.to != per) self(self, e.to, now, d + 1, cost + e.cost);
		};
		dfs(dfs, root, -1, 0, 0LL);
		build();
	}

	int lowest_common_ancestor(int u, int v) {
		if(depth[u] < depth[v]) std::swap(u, v);
		int k = parent.size();
		for(int i = 0; i < k; i++)
			if((depth[u] - depth[v]) >> i & 1) u = parent[i][u];
		if(u == v) return u;
		for(int i = k - 1; i >= 0; i--)
			if(parent[i][u] != parent[i][v]) u = parent[i][u], v = parent[i][v];
		return parent[0][u];
	}

	long long length_of_path(const int u, const int v) { return dist[u] + dist[v] - dist[lowest_common_ancestor(u, v)] * 2; }

	int level_ancestor(int v, int level) {
		assert(level >= 0);
		if(level >= (1 << max_jump)) return -1;
		for(int jump = 0; jump < max_jump and level; jump++) {
			if(level & 1 and v != -1) v = parent[jump][v];
			level >>= 1;
		}
		return v;
	}
};
