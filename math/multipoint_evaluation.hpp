#pragma once
#include <atcoder/internal_bit>
#include <vector>

#include "math/formal_power_series.hpp"

template <class T, Mode mode>
std::vector<T> formal_power_series<T, mode>::multipoint_evaluation(const std::vector<T> &p) {
	using fps = formal_power_series<T, mode>;
	int m = p.size();
	int n = 1 << max(atcoder::internal::ceil_pow2(m), 1);
	std::vector<fps> subproducts(2 * n, F{1}), rem(2 * n);
	for(int i = n; i < n + m; i++) subproducts[i] = fps({-p[i - n], 1});
	for(int i = n - 1; i; i--) {
		int x = subproducts[i << 1].size(), y = subproducts[i << 1 | 1].size();
		subproducts[i] = subproducts[i << 1];
		subproducts[i].resize(x + y - 1);
		subproducts[i] *= subproducts[i << 1 | 1];
	}
	rem[1] = *this;
	for(int i = 1; i < n; i++) {
		rem[i << 1] = rem[i] % subproducts[i << 1];
		rem[i << 1].shrink();
		rem[i << 1 | 1] = rem[i] % subproducts[i << 1 | 1];
		rem[i << 1 | 1].shrink();
	}
	std::vector<T> res(m);
	for(int i = 0; i < m; i++) res[i] = (!rem[i + n].empty() ? rem[i + n][0] : 0);
	return res;
}
