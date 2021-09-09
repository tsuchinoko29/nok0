#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "atcoder/modint"
#include "cftemp.hpp"
#include "data_structure/swag.hpp"
#include "math/modint_iostream.hpp"

using mint = atcoder::modint998244353;
using S = pair<mint, mint>;
S op(S a, S b) {
	return S(a.first * b.first, b.first * a.second + b.second);
}
S e() {
	return S(1, 0);
}

void main_() {
	sliding_window_aggregation<S, op, e> swag;
	INT(q);
	while(q--) {
		INT(t);
		if(t == 0) {
			INT(a, b);
			swag.push(S(a, b));
		}
		if(t == 1) swag.pop();
		if(t == 2) {
			INT(x);
			auto [a, b] = swag.fold_all();
			print(a * x + b);
		}
	}
}