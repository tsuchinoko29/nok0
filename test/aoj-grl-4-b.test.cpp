#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B"

#include "graph/graph.hpp"
#include "template.hpp"

void main_() {
	INT(v, e);
	graph g(v, e, 0, 1, 0);
	printel(g.topological_sort());
}