#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include "atcoder/modint"
#include "cftemp.hpp"
#include "math/formal_power_series.hpp"
#include "math/modint_iostream.hpp"

using mint = atcoder::modint998244353;
using fps = formal_power_series<mint, FAST>;

void main_() {
	INT(n);
	factorial<mint>::set_size(n);
	fps f;
	f.stirling_second(n);
	print(f);
}