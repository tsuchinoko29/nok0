#pragma once
#include "graph.hpp"

struct strongly_connected_components {
private:
	enum { CHECKED = -1,
		   UNCHECKED = -2 };
	const graph &graph_given;
	graph graph_reversed;
	std::vector<int> order, group_number; /* at the beginning of the building, 'group_number' is used as 'checked' */

	void dfs(int now) {
		if(group_number[now] != UNCHECKED) return;
		group_number[now] = CHECKED;
		for(auto &e : graph_given[now]) dfs(e.to);
		order.push_back(now);
	}

	void rdfs(int now, int group_count) {
		if(group_number[now] != UNCHECKED) return;
		group_number[now] = group_count;
		for(auto &e : graph_reversed[now]) rdfs(e.to, group_count);
	}

	void build(bool create_compressed_graph) {
		for(int i = 0; i < (int)graph_given.size(); i++) dfs(i);
		reverse(order.begin(), order.end());
		group_number.assign(graph_given.size(), UNCHECKED);
		int group = 0;
		for(auto &i : order)
			if(group_number[i] == UNCHECKED) rdfs(i, group), group++;
		graph_compressed.resize(group);
		groups.resize(group);
		for(int i = 0; i < (int)graph_given.size(); i++) groups[group_number[i]].push_back(i);
		if(create_compressed_graph) {
			std::vector<int> edges(group, -1);
			for(int i = 0; i < group; i++)
				for(auto &vertex : groups[i])
					for(auto &e : graph_given[vertex])
						if(group_number[e.to] != i and edges[group_number[e.to]] != i) {
							edges[group_number[e.to]] = i;
							graph_compressed[i].emplace_back(group_number[e.to], 1);
						}
		}
		return;
	}

public:
	std::vector<std::vector<int>> groups;
	graph graph_compressed;

	strongly_connected_components(const graph &g_, bool create_compressed_graph = false)
	  : graph_given(g_), graph_reversed(g_.size()), group_number(g_.size(), UNCHECKED) {
		for(size_t i = 0; i < g_.size(); i++)
			for(auto &e : graph_given[i]) graph_reversed[e.to].emplace_back(i, 1);
		build(create_compressed_graph);
	}

	const int &operator[](const int k) { return group_number[k]; }
};
