#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "graph/graph.hpp"
#include "template.hpp"

void main_() {
	INT(n);
	graph G(n, -1, 1, 0, 0);
	ll x = G.diameter().second;
	auto vec = G.diameter_path();
	print(x, SZ(vec));
	print(vec);
}