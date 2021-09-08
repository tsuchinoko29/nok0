#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "data_structure/binary_indexed_tree.hpp"
#include "graph/graph.hpp"
#include "graph/hld.hpp"
#include "template.hpp"

void main_() {
	INT(n, q);
	VEC(int, a, n);
	Graph g(n);
	REP(i, 1, n) {
		INT(p);
		g.add_edge(i, p);
	}

	heavy_light_decomposition hld(g);

	binary_indexed_tree<ll> bt(n);
	REP(i, n) { bt.add(hld.in[i], a[i]); }

	auto f = [](ll a, ll b) { return a + b; };
	auto query = [&](int l, int r) { return bt.sum(l, r); };

	while(q--) {
		INT(type, u);
		if(type == 0) {
			INT(v);
			bt.add(hld.in[u], v);
		}
		if(type == 1) {
			auto [l, r] = hld.subtree(u);
			print(bt.sum(l, r));
		}
	}
}