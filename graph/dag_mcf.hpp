#include <atcoder/mincostflow>
#include <iostream>

#include "graph/graph.hpp"

template <class Cap, class Cost>
struct dag_mcf {
public:
	dag_mcf(int n) : mcf(n), g(n) {}

	void add_edge(int from, int to, Cap cap, Cost cost) {
		g.add_edge(from, to, cost, 1);
		es.emplace_back(from, to, cap, cost);
	}

	std::pair<Cap, Cost> flow(int s, int t) {
		std::vector<Cost> potential(g.size());
		std::vector<int> t_sort = g.topological_sort();
		potential[s] = 0;
		for(const auto &idx : t_sort)
			for(const auto &[to, cost] : g[idx])
				potential[to] = std::min(potential[to], potential[idx] + cost);

		for(const auto &[from, to, cap, cost] : es)
			mcf.add_edge(from, to, cap, potential[from] - potential[to] + cost);

		auto [rescap, rescost] = mcf.flow(s, t);
		return {rescap, potential[t] * rescap - rescost};
	}

	std::pair<Cap, Cost> flow(int s, int t, int k) {
		std::vector<Cost> potential(g.size());
		std::vector<int> t_sort = g.topological_sort();
		potential[s] = 0;
		for(const auto &idx : t_sort)
			for(const auto &[to, cost] : g[idx])
				potential[to] = std::min(potential[to], potential[idx] + cost);

		for(const auto &[from, to, cap, cost] : es)
			mcf.add_edge(from, to, cap, potential[from] - potential[to] + cost);

		auto [rescap, rescost] = mcf.flow(s, t, k);
		return {rescap, potential[t] * rescap + rescost};
	}

private:
	graph g;
	atcoder::mcf_graph<Cap, Cost> mcf;
	struct edge {
		int from, to;
		Cap cap;
		Cost cost;
		edge(int from, int to, Cap cap, Cost cost) : from(from), to(to), cap(cap), cost(cost) {}
	};
	std::vector<edge> es;
};
