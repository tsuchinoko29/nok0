#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_E"

#include "data_structure/rangeadd_rangesum_bit.hpp"
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
	rangeadd_rangesum_bit<ll> bt(n);

	ll w;
	auto upd = [&](int l, int r) { bt.add(l, r, w); };
	auto f = [](ll a, ll b) { return a + b; };
	auto q = [&](int l, int r) { return bt.sum(l, r); };

	INT(Q);
	while(Q--) {
		INT(type, u);
		if(type == 0) {
			cin >> w;
			hld.add(0, u, upd, 1);
		} else {
			print(hld.query(0, u, 0ll, q, f, true));
		}
	}
}