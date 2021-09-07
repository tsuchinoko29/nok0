#include <algorithm>
#include <cassert>
#include <cstdint>
#include <numeric>
#include <queue>
#include <vector>

enum Objective {
	MINIMIZE = 1,
	MAXIMIZE = -1,
};
enum class Status {
	OPTIMAL,
	INFEASIBLE,
};

template <class Flow, class Cost, Objective objective = Objective::MINIMIZE, Flow SCALING_FACTOR = 2>
struct MinCostFlow {
private:
	using V_id = uint32_t;
	using E_id = uint32_t;

	struct Edge {
		friend struct MinCostFlow;

	private:
		V_id src, dst;
		Flow flow, cap;
		Cost cost;
		E_id rev;

	public:
		Edge() = default;

		Edge(const V_id src, const V_id dst, const Flow cap, const Cost cost,
		     const E_id rev)
		  : src(src), dst(dst), flow(0), cap(cap), cost(cost), rev(rev) {}

		[[nodiscard]] Flow residual_cap() const { return cap - flow; }
	};

public:
	struct EdgePtr {
		friend struct MinCostFlow;

	private:
		const MinCostFlow *instance;
		const V_id v;
		const E_id e;

		EdgePtr(const MinCostFlow *instance, const V_id v, const E_id e)
		  : instance(instance), v(v), e(e) {}

		[[nodiscard]] const Edge &edge() const { return instance->g[v][e]; }

		[[nodiscard]] const Edge &rev() const {
			const Edge &e = edge();
			return instance->g[e.dst][e.rev];
		}

	public:
		[[nodiscard]] V_id src() const { return rev().dst; }

		[[nodiscard]] V_id dst() const { return edge().dst; }

		[[nodiscard]] Flow flow() const { return edge().flow; }

		[[nodiscard]] Flow lower() const { return -rev().cap; }

		[[nodiscard]] Flow upper() const { return edge().cap; }

		[[nodiscard]] Cost cost() const { return edge().cost; }

		[[nodiscard]] Cost gain() const { return -edge().cost; }
	};

private:
	V_id n;
	std::vector<std::vector<Edge>> g;
	std::vector<Flow> b;

public:
	MinCostFlow() : n(0) {}

	V_id add_vertex() {
		++n;
		g.resize(n);
		b.resize(n);
		return n - 1;
	}

	std::vector<V_id> add_vertices(const size_t size) {
		std::vector<V_id> ret;
		for(V_id i = 0; i < size; ++i) ret.emplace_back(n + i);
		n += size;
		g.resize(n);
		b.resize(n);
		return ret;
	}

	EdgePtr add_edge(const V_id src, const V_id dst, const Flow lower, const Flow upper, const Cost cost) {
		const E_id e = g[src].size(), re = src == dst ? e + 1 : g[dst].size();
		assert(lower <= upper);
		g[src].emplace_back(Edge{src, dst, upper, cost * objective, re});
		g[dst].emplace_back(Edge{dst, src, -lower, -cost * objective, e});
		return EdgePtr{this, src, e};
	}

	void add_supply(const V_id v, const Flow amount) { b[v] += amount; }

	void add_demand(const V_id v, const Flow amount) { b[v] -= amount; }

private:
	static Cost constexpr unreachable = std::numeric_limits<Cost>::max();
	Cost farthest;
	std::vector<Cost> potential;
	std::vector<Cost> dist;
	std::vector<Edge *> parent;
	std::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost, int>>, std::greater<>> pq;
	std::vector<V_id> excess_vs, deficit_vs;

	Edge &rev(const Edge &e) { return g[e.dst][e.rev]; }

	void push(Edge &e, const Flow amount) {
		e.flow += amount;
		g[e.dst][e.rev].flow -= amount;
	}

	Cost residual_cost(const V_id src, const V_id dst, const Edge &e) {
		return e.cost + potential[src] - potential[dst];
	}

	bool dual(const Flow delta) {
		dist.assign(n, unreachable);
		parent.assign(n, nullptr);
		excess_vs.erase(std::remove_if(std::begin(excess_vs), std::end(excess_vs), [&](const V_id v) { return b[v] < delta; }), std::end(excess_vs));
		deficit_vs.erase(std::remove_if(std::begin(deficit_vs), std::end(deficit_vs), [&](const V_id v) { return b[v] > -delta; }), std::end(deficit_vs));
		for(const auto v : excess_vs) pq.emplace(dist[v] = 0, v);
		farthest = 0;
		std::size_t deficit_count = 0;
		while(!pq.empty()) {
			const auto [d, u] = pq.top();
			pq.pop();
			if(dist[u] < d) continue;
			farthest = d;
			if(b[u] <= -delta) ++deficit_count;
			if(deficit_count >= deficit_vs.size()) break;
			for(auto &e : g[u]) {
				if(e.residual_cap() < delta) continue;
				const auto v = e.dst;
				const auto new_dist = d + residual_cost(u, v, e);
				if(new_dist >= dist[v]) continue;
				pq.emplace(dist[v] = new_dist, v);
				parent[v] = &e;
			}
		}
		pq = decltype(pq)();
		for(V_id v = 0; v < n; ++v) {
			potential[v] += std::min(dist[v], farthest);
		}
		return deficit_count > 0;
	}

	void primal(const Flow delta) {
		for(const auto t : deficit_vs) {
			if(dist[t] > farthest) continue;
			Flow f = -b[t];
			V_id v;
			for(v = t; parent[v] != nullptr && f >= delta; v = parent[v]->src) {
				f = std::min(f, parent[v]->residual_cap());
			}
			f = std::min(f, b[v]);
			if(f < delta) continue;
			for(v = t; parent[v] != nullptr;) {
				auto &e = *parent[v];
				push(e, f);
				const size_t u = parent[v]->src;
				parent[v] = nullptr;
				v = u;
			}
			b[t] += f;
			b[v] -= f;
		}
	}

	void saturate_negative(const Flow delta) {
		excess_vs.clear();
		deficit_vs.clear();
		for(auto &es : g)
			for(auto &e : es) {
				const Flow rcap = e.residual_cap();
				const Cost rcost = residual_cost(e.src, e.dst, e);
				if(rcost < 0 && rcap >= delta) {
					push(e, rcap);
					b[e.src] -= rcap;
					b[e.dst] += rcap;
				}
			}
		for(V_id v = 0; v < n; ++v)
			if(b[v] != 0) {
				(b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v);
			}
	}

public:
	std::pair<Status, Cost> solve() {
		potential.resize(n);
		for(auto &es : g)
			for(auto &e : es) {
				const Flow rcap = e.residual_cap();
				if(rcap < 0) {
					push(e, rcap);
					b[e.src] -= rcap;
					b[e.dst] += rcap;
				}
			}

		Flow inf_flow = 1;
		for(const auto &es : g)
			for(const auto &e : es) inf_flow = std::max(inf_flow, e.residual_cap());
		Flow delta = 1;
		while(delta <= inf_flow) delta *= SCALING_FACTOR;

		for(delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR) {
			saturate_negative(delta);
			while(dual(delta)) primal(delta);
		}

		Cost value = 0;
		for(const auto &es : g)
			for(const auto &e : es) {
				value += e.flow * e.cost;
			}
		value /= 2;

		if(excess_vs.empty() && deficit_vs.empty()) {
			return {Status::OPTIMAL, value / objective};
		} else {
			return {Status::INFEASIBLE, value / objective};
		}
	}
};

template <class Flow, class Cost>
using MaxGainFlow = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;
