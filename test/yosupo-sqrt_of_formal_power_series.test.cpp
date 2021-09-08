#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include "atcoder/modint"
#include "math/formal_power_series.hpp"
#include "template.hpp"

using mint = atcoder::modint998244353;
using fps = formal_power_series<mint, FAST>;
void main_() {
	INT(n);
	fps f(n);
	cin >> f;
	auto ret = f.sqrt();
	if(ret.empty())
		print(-1);
	else
		print(ret);
}