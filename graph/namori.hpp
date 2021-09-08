#pragma once
#include "graph/graph.hpp"

struct namori {
public:
	std::vector<std::vector<int>> cycles;
	std::vector<int> cycle_number, root;
	namori(graph &g) : n(g.size()), g(g) { build(); }

private:
	int n;
	std::vector<bool> dfs_used, dfs_now;
	std::vector<int> dfs_ver;
	graph &g;
	graph forest;
	void build() {
		forest.resize(n);
		dfs_used.assign(n, false);
		dfs_now.assign(n, false);
		dfs_ver.clear();
		cycle_number.assign(n, -1);
		root.assign(n, -1);
		for(int i = 0; i < n; i++) {
			if(dfs_used[i]) continue;
			cycles.emplace_back();
			build_dfs(i, -1, cycles.back());
			if(cycles.back().empty()) cycles.back().push_back(i);
		}
		for(int i = 0; i < (int)cycles.size(); i++)
			for(const auto &v : cycles[i]) cycle_number[v] = i;
		dfs_used.assign(n, false);
		for(int i = 0; i < n; i++)
			if(cycle_number[i] != -1) tree_dfs(i, i);
	}

	void build_dfs(int now, int par, std::vector<int> &cycle) {
		dfs_used[now] = true;
		dfs_now[now] = true;
		dfs_ver.push_back(now);
		bool multiple_par = false;
		for(const auto [to, cost] : g[now]) {
			if(dfs_now[to] and cycle.empty() and (to != par or multiple_par)) {
				for(const auto &v : dfs_ver) {
					if(!cycle.empty() or v == to) cycle.push_back(v);
				}
			}
			if(to == par) multiple_par = true;
			if(dfs_used[to]) continue;
			build_dfs(to, now, cycle);
		}
		dfs_now[now] = false;
		dfs_ver.pop_back();
	}

	void tree_dfs(int now, int r) {
		dfs_used[now] = true;
		root[now] = r;
		for(const auto &[to, cost] : g[now]) {
			if(dfs_used[to] or cycle_number[to] != -1) continue;
			forest.add_edge(now, to, cost);
			tree_dfs(to, r);
		}
	}
};
