#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"

#include "graph/graph.hpp"
#include "template.hpp"

void main_() {
	INT(v, e);
	graph g(v, e, 1, 0, 0);
	auto prim = g.prim();
	auto kruskal = g.kruskal();
	assert(prim == kruskal);
	print(prim);
}