#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"

#include "graph/graph.hpp"
#include "graph/tree_doubling.hpp"
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

	tree_doubling td(g, 0);

	INT(q);
	while(q--) {
		INT(u, v);
		print(td.lowest_common_ancestor(u, v));
	}
}