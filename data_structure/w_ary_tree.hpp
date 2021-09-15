#include <array>
#include <cstdint>
#include <vector>

namespace w_ary_tree_impl {
using u32 = uint32_t;
using u64 = uint64_t;
constexpr u32 ws = 64;
constexpr u32 calc_c(u32 n) {
	u32 ret = 1;
	while(n > 64) ret *= ws, n /= ws;
	return ret;
}
constexpr u32 ceil_div(u32 n, u32 k) {
	return (n + k - 1) / k;
}
u32 bsf(const u64 x) { return __builtin_ctzll(x); }
u32 bsr(const u64 x) { return 63 - __builtin_clzll(x); }
u64 to_bit(const u32 x) { return static_cast<u64>(1) << x; }

template <u32 N, class D = void>
struct w_ary_tree {
	static constexpr u32 C = calc_c(N);
	u64 map;
	std::array<w_ary_tree<C>, ceil_div(N, C)> child;

public:
	w_ary_tree() : map(0), child() {}

	bool insert(const u32 key) {
		const u32 pos = key / C;
		map |= to_bit(pos);
		return child[pos].insert(key % C);
	}

	bool erase(const u32 key) {
		const u32 pos = key / C;
		const bool ret = child[pos].erase(key % C);
		if(child[pos]._get_map() == 0) map ^= to_bit(pos);
		return ret;
	}

	bool contains(const u32 key) const {
		return child[key / C].contains(key % C);
	}

	u32 min() const {
		const u32 pos = bsf(map);
		return pos * C + child[pos].min();
	}

	u32 max() const {
		const u32 pos = bsr(map);
		return pos * C + child[pos].max();
	}

	u32 prev(const u32 key) const {
		const u32 pos = key / C;
		const u32 t = child[pos].prev(key % C);
		if(t != -1) return pos * C + t;
		const u64 masked = map & ~(~static_cast<u64>(0) << pos);
		if(masked) {
			const u32 pos2 = bsr(masked);
			return pos2 * C + child[pos2].max();
		} else
			return -1;
	}

	u32 next(const u32 key) const {
		const u32 pos = key / C;
		const u32 t = child[pos].next(key % C);
		if(t != -1) return pos * C + t;
		const u64 masked = map & ~(~static_cast<u64>(0) >> (63 - pos));
		if(masked) {
			const u32 pos2 = bsf(masked);
			return pos2 * C + child[pos2].min();
		} else
			return -1;
	}

	u64 _get_map() const { return map; }
};

template <u32 N>
struct w_ary_tree<N, typename std::enable_if<(N <= ws)>::type> {
	u64 map;

public:
	w_ary_tree() : map(0) {}

	bool insert(const u32 key) {
		const u64 bit = to_bit(key);
		if(map & bit)
			return false;
		else
			map |= bit;
		return true;
	}

	bool erase(const u32 key) {
		const u64 bit = to_bit(key);
		if(map & bit) {
			map ^= bit;
			return true;
		}
		return false;
	}

	bool contains(const u32 key) const {
		return map & to_bit(key);
	}

	u32 min() const { return bsf(map); }
	u32 max() const { return bsr(map); }

	u32 prev(const u32 key) const {
		const u64 masked = map & ~(~static_cast<u64>(0) << key);
		if(masked)
			return bsr(masked);
		else
			return -1;
	}

	u32 next(const u32 key) const {
		const u64 masked = map & (~static_cast<u64>(0) << key);
		if(masked)
			return bsf(masked);
		else
			return -1;
	}

	u64 _get_map() const { return map; }
};
}  // namespace w_ary_tree_impl

template <int N>
using w_ary_tree = w_ary_tree_impl::w_ary_tree<static_cast<uint32_t>(N)>;
