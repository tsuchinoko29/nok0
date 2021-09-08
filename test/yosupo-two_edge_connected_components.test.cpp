#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "graph/graph.hpp"
#include "graph/two_edge_cc.hpp"
#include "template.hpp"

void main_() {
	INT(n, m);
	Graph g(n, m, 0, 0, 0);

	two_edge_connected_components tecc(g);
	print(SZ(tecc.groups));
	foa(group, tecc.groups) {
		print(SZ(group), group);
	}
}