#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "cftemp.hpp"
#include "data_structure/sparse_table.hpp"

using S = int;
S op(S x, S y) { return min(x, y); }

void main_() {
	INT(n, q);
	VEC(int, a, n);
	sparse_table<S, op> sp(a);
	while(q--) {
		INT(l, r);
		print(sp.prod(l, r));
	}
}