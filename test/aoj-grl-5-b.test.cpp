#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_B"

#include "graph/graph.hpp"
#include "template.hpp"

void main_() {
	INT(v);
	graph g(v, -1, 1, 0, 0);
	printel(g.height());
}