#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B"

#include "graph/graph.hpp"
#include "graph/low_link.hpp"
#include "template.hpp"

void main_() {
	INT(v, e);
	graph g(v, e, 0, 0, 0);
	low_link lnk(g);
	auto res = lnk.bridge;
	SORT(res);
	foa(p, res) print(p);
}