#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_C"

#include "graph/graph.hpp"
#include "graph/scc.hpp"
#include "template.hpp"

void main_() {
	INT(v, e);
	graph g(v, e, 0, 1, 0);
	strongly_connected_components scc(g);
	INT(q);
	while(q--) {
		INT(u, v);
		print(scc[u] == scc[v]);
	}
}