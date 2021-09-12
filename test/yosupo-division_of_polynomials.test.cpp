#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "cftemp.hpp"
#include "math/fps"

using mint = atcoder::modint998244353;
using fps = formal_power_series<mint, FAST>;
void main_() {
	INT(n, m);
	fps f(n), g(m);
	cin >> f >> g;
	auto q = f.poly_div(g);
	auto r = f % g;
	while(q.size() and q.back() == 0) q.pop_back();
	while(r.size() and r.back() == 0) r.pop_back();
	print(SZ(q), SZ(r));
	print(q);
	print(r);
}