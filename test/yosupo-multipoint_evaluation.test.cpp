#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "cftemp.hpp"
#include "math/fps"

using mint = atcoder::modint998244353;
using fps = formal_power_series<mint, FAST>;
void main_() {
	INT(n, m);
	fps f(n);
	cin >> f;
	VEC(mint, p, m);
	auto res = f.multipoint_evaluation(p);
	print(res);
}