#pragma once
#include <vector>

#include "atcoder/segtree"

namespace longest_increasing_subsequence_impl {
using S = int;
S op(S x, S y) {
	return std::max(x, y);
}
S e() {
	return 0;
}
template <class T>
int longest_increasing_subsequence(const std::vector<T> &vec, bool strictly = true) {
	auto tmp = vec;
	std::sort(tmp.begin(), tmp.end());
	tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
	int m = tmp.size();
	atcoder::segtree<S, op, e> seg(m);
	for(const auto &v : vec) {
		int id = std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), v));
		seg.set(id, std::max(seg.get(id), seg.prod(0, id + !strictly) + 1));
	}
	return seg.all_prod();
}
}  // namespace longest_increasing_subsequence_impl
using longest_increasing_subsequence_impl::longest_increasing_subsequence;
