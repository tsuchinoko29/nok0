#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "math/factorize.hpp"
#include "multi.hpp"

void main_() {
	LL(a);
	auto vec = factorize(a);
	SORT(vec);
	print(SZ(vec), vec);
}