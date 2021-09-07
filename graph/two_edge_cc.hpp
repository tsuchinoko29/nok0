#pragma once
#include "graph/graph.hpp"
#include "low_link.hpp"

struct two_edge_connected_components {
private:
	const Graph &graph_given;
	int group_next;
	low_link li;
	std::vector<int> group_number;

	void build(bool create_compressed_graph) {
		int n = graph_given.size();
		group_number.resize(n, -1);
		group_next = 0;
		for(int i = 0; i < n; i++)
			if(group_number[i] == -1) dfs(i);
		groups.resize(group_next);
		for(int i = 0; i < graph_given.size(); i++) groups[group_number[i]].push_back(i);

		if(create_compressed_graph) {
			graph_compressed.resize(group_next);
			for(auto [u, v] : li.bridge) {
				int x = group_number[u], y = group_number[v];
				graph_compressed.add_edge(x, y);
			}
		}
	}

	void dfs(int now, int par = -1) {
		if(par != -1 and li.order[par] >= li.low[now])
			group_number[now] = group_number[par];
		else
			group_number[now] = group_next++;
		for(const auto &e : graph_given[now])
			if(group_number[e.to] == -1) dfs(e.to, now);
	}

public:
	Graph graph_compressed;
	std::vector<std::vector<int>> groups;
	two_edge_connected_components(const Graph &g_, bool create_compressed_graph = false)
	  : graph_given(g_), li(g_) {
		build(create_compressed_graph);
	}

	const int &operator[](const int k) { return group_number[k]; }
};
