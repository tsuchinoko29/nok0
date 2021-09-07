#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2600&lang=jp"

#include "data_structure/range_set.hpp"
#include "template.hpp"

void main_() {
	INT(n, H, W);
	range_set<int> xs, ys;
	REP(i, n) {
		INT(x, y, w);
		xs.insert(max(x - w, 0), min(x + w, H));
		ys.insert(max(y - w, 0), min(y + w, W));
	}
	Yes(xs.sum_all() == H or ys.sum_all() == W);
}
