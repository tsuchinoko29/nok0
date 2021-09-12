#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "cftemp.hpp"
#include "math/fps"

using mint = atcoder::modint998244353;
using fps = formal_power_series<mint, FAST>;
void main_() {
	factorial<mint>::set_size();
	INT(n, c);
	fps f(n);
	cin >> f;
	fps g = f.taylor_shift(c);
	print(g);
}