#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C"

#include "graph/graph.hpp"
#include "template.hpp"

void main_() {
	INT(v, e);
	graph g(v, e, 1, 1, 0);
	auto d = g.warshall_floyd();
	REP(i, v) {
		if(d[i][i] < 0) {
			print("NEGATIVE CYCLE");
			return;
		}
	}
	REP(i, v) {
		REP(j, v) {
			if(d[i][j] == g.INF)
				cout << "INF";
			else
				cout << d[i][j];
			cout << " \n"[j == v - 1];
		}
	}
}