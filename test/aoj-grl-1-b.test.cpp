#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B"

#include "graph/graph.hpp"
#include "template.hpp"

void main_() {
	INT(v, e, r);
	graph g(v, e, 1, 1, 0);
	auto d = g.bellman_ford(r);
	if(count(all(d), -g.INF)) {
		print("NEGATIVE CYCLE");
		return;
	}
	foa(v, d) {
		if(v == g.INF)
			print("INF");
		else
			print(v);
	}
}