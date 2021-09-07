#pragma once

#include "graph/graph.hpp"

struct low_link {
private:
	const Graph &graph_given;
	int order_next;

	void build() {
		int n = graph_given.size();
		order.resize(n, -1);
		low.resize(n);
		order_next = 0;
		for(int i = 0; i < n; i++)
			if(order[i] == -1) dfs(i);
	}

	void dfs(int now, int par = -1) {
		low[now] = order[now] = order_next++;
		bool is_articulation = false;
		int cnt = 0, cnt_par = 0;
		for(const auto &ed : graph_given[now]) {
			const int &nxt = ed.to;
			if(order[nxt] == -1) {
				cnt++;
				dfs(nxt, now);
				if(order[now] < low[nxt]) bridge.push_back(std::minmax(now, nxt));
				if(order[now] <= low[nxt]) is_articulation = true;
				low[now] = std::min(low[now], low[nxt]);
			} else if(nxt != par or cnt_par++ == 1) {
				low[now] = std::min(low[now], order[nxt]);
			}
		}
		if(par == -1 and cnt < 2) is_articulation = false;
		if(is_articulation) articulation.push_back(now);
		return;
	}

public:
	std::vector<int> order, low, articulation;
	std::vector<std::pair<int, int>> bridge;
	low_link() = default;
	low_link(const Graph &g_) : graph_given(g_) { build(); }
};
