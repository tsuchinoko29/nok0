#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "atcoder/modint"
#include "math/formal_power_series.hpp"
#include "template.hpp"

using mint = atcoder::modint998244353;
using fps = formal_power_series<mint, FAST>;
void main_() {
	INT(n);
	fps f(n);
	cin >> f;
	print(f.inv());
}