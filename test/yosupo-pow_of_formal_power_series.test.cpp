#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "cftemp.hpp"
#include "math/fps"

using mint = atcoder::modint998244353;
using fps = formal_power_series<mint, FAST>;
void main_() {
	INT(n, m);
	fps f(n);
	cin >> f;
	print(f.pow(m));
}