#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_D"

#include "data_structure/binary_indexed_tree.hpp"
#include "graph/graph.hpp"
#include "graph/hld.hpp"
#include "template.hpp"

void main_() {
	INT(n);
	graph g(n);
	REP(i, n) {
		INT(k);
		while(k--) {
			INT(c);
			g.add_edge(i, c);
		}
	}
	heavy_light_decomposition hld(g, 0);
	binary_indexed_tree<ll> bt(n);

	auto f = [](ll a, ll b) { return a + b; };
	auto q = [&](int l, int r) { return bt.sum(l, r); };

	INT(Q);
	while(Q--) {
		INT(type, u);
		if(type == 0) {
			INT(w);
			bt.add(hld.in[u], w);
		} else {
			print(hld.query(0, u, 0ll, q, f, true));
		}
	}
}