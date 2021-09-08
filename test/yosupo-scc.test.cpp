#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "graph/graph.hpp"
#include "graph/scc.hpp"
#include "template.hpp"

void main_() {
	INT(n, m);
	Graph g(n, m, 0, 1, 0);
	strongly_connected_components scc(g);
	print(SZ(scc.groups));
	foa(group, scc.groups)
	    print(SZ(group), group);
}