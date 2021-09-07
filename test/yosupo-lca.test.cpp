#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "graph/graph.hpp"
#include "graph/tree_doubling.hpp"
#include "template.hpp"

void main_() {
	INT(n, q);
	Graph g(n);
	REP(i, n - 1) {
		INT(p);
		g.add_edge(i + 1, p);
	}
	tree_doubling td(g, 0);
	while(q--) {
		INT(u, v);
		print(td.lowest_common_ancestor(u, v));
	}
}