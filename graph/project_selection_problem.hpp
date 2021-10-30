#pragma once

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

namespace project_selection_problem_impl {

template <typename flow_t>
struct dinic {
private:
	const flow_t INF;
	struct edge {
		int to;
		flow_t cap;
		int rev;
		bool isrev;
		int idx;
	};
	std::vector<std::vector<edge>> graph;
	std::vector<int> min_cost, iter;

	bool bfs(int s, int t) {
		min_cost.assign(graph.size(), -1);
		std::queue<int> que;
		min_cost[s] = 0;
		que.push(s);
		while(!que.empty() and min_cost[t] == -1) {
			int p = que.front();
			que.pop();
			for(auto &e : graph[p]) {
				if(e.cap > 0 and min_cost[e.to] == -1) {
					min_cost[e.to] = min_cost[p] + 1;
					que.push(e.to);
				}
			}
		}
		return min_cost[t] != -1;
	}

	flow_t dfs(int idx, const int t, flow_t flow) {
		if(idx == t) return flow;
		for(int &i = iter[idx]; i < SZ(graph[idx]); i++) {
			edge &e = graph[idx][i];
			if(e.cap > 0 and min_cost[idx] < min_cost[e.to]) {
				flow_t d = dfs(e.to, t, min(flow, e.cap));
				if(d > 0) {
					e.cap -= d;
					graph[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

public:
	dinic(int v = 0) : INF(std::numeric_limits<flow_t>::max()), graph(v) {}

	void add_edge(int from, int to, flow_t cap, int idx = -1) {
		graph[from].emplace_back(edge{to, cap, int(graph[to].size()), false, idx});
		graph[to].emplace_back(edge{from, 0, int(graph[from].size()) - 1, true, idx});
	}

	flow_t max_flow(int s, int t) {
		flow_t flow = 0;
		while(bfs(s, t)) {
			iter.assign(graph.size(), 0);
			flow_t f = 0;
			while((f = dfs(s, t, INF)) > 0) flow += f;
		}
		return flow;
	}

	void output() {
		for(int i = 0; i < (int)graph.size(); i++) {
			for(auto &e : graph[i]) {
				if(e.isrev) continue;
				auto &rev_e = graph[e.to][e.rev];
				std::cout << i << "->" << e.to << " (flow:" << rev_e.cap << "/" << e.cap + rev_e.cap << ")\n";
			}
		}
	}

	void resize(int x) { graph.resize(x); }

	int size() { return graph.size(); }
};

template <typename T>
struct project_selection_problem {
private:
	int n;
	const T INF;
	T res = 0;
	dinic<T> mf;

public:
	project_selection_problem(int n_) : n(n_), INF(std::numeric_limits<T>::max()), mf(n + 2) {}

	void x_and_noty_loss(int x, int y, T loss) {
		assert(loss >= 0);
		mf.add_edge(x, y, loss);
	}

	void x_xor_y_loss(int x, int y, T loss) {
		x_and_noty_loss(x, y, loss);
		x_and_noty_loss(y, x, loss);
	}

	void x_get(int x, T get) {
		if(get < 0) {
			mf.add_edge(x, n + 1, -get);
			return;
		}
		res += get;
		notx_loss(x, get);
	}

	void x_loss(int x, T loss) {
		if(loss < 0) {
			x_get(x, -loss);
			return;
		}
		mf.add_edge(x, n + 1, loss);
	}

	void notx_get(int x, T get) {
		if(get < 0) {
			mf.add_edge(n, x, -get);
			return;
		}
		res += get;
		x_loss(x, get);
	}

	void notx_loss(int x, T loss) {
		if(loss < 0) {
			notx_get(x, -loss);
			return;
		}
		mf.add_edge(n, x, loss);
	}

	void x_and_y_get(int x, int y, T get) {
		assert(get >= 0);
		res += get;
		mf.resize(mf.size() + 1);
		int w = mf.size() - 1;
		mf.add_edge(n, w, get);
		mf.add_edge(w, x, INF);
		mf.add_edge(w, y, INF);
	}

	void x_nor_y_get(int x, int y, T get) {
		assert(get >= 0);
		res += get;
		mf.resize(mf.size() + 1);
		int w = mf.size() - 1;
		mf.add_edge(w, n + 1, get);
		mf.add_edge(x, w, INF);
		mf.add_edge(y, w, INF);
	}

	void x_equal_y_get(int x, int y, T get) {
		x_and_y_get(x, y, get);
		x_nor_y_get(x, y, get);
	}

	T min_lost() {
		return mf.max_flow(n, n + 1) - res;
	}

	T max_profit() {
		return -min_lost();
	}
};
}  // namespace project_selection_problem_impl

using project_selection_problem_impl::project_selection_problem;
