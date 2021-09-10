#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "atcoder/modint"
#include "cftemp.hpp"
#include "math/formal_power_series.hpp"
#include "math/modint_iostream.hpp"

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