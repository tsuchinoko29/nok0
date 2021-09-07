#include <bits/stdc++.h>

namespace inner {
using u32 = uint32_t;
using u64 = uint64_t;
using i64 = int64_t;
using u128 = __uint128_t;

u64 gcd_impl(u64 n, u64 m) {
	constexpr u64 K = 5;
	for(u32 i = 0; i < 80; ++i) {
		u64 t = n - m;
		u64 s = n - m * K;
		bool q = t < m;
		bool p = t < m * K;
		n = q ? m : t;
		m = q ? t : m;
		if(m == 0) return n;
		n = p ? n : s;
	}
	return gcd_impl(m, n % m);
}

u64 gcd_pre(u64 n, u64 m) {
	for(u32 i = 0; i < 4; ++i) {
		u64 t = n - m;
		bool q = t < m;
		n = q ? m : t;
		m = q ? t : m;
		if(m == 0) return n;
	}
	return gcd_impl(n, m);
}

u64 gcd_fast(u64 n, u64 m) { return n > m ? gcd_pre(n, m) : gcd_pre(m, n); }

struct modint64 {
	using u64 = uint64_t;

public:
	static u64 mod;
	static u64 r, n2;
	static void set_mod(u64 m) {
		mod = m;
		n2 = -u128(m) % m;
		r = get_r();
		assert(r * mod == 1);
	}
	modint64() : a(0) {}
	modint64(const i64 &b) : a(reduce((u128(b) + mod) * n2)) {}

	modint64 &operator+=(const modint64 &b) {
		if(i64(a += b.a - 2 * mod) < 0) a += 2 * mod;
		return *this;
	}

	modint64 &operator-=(const modint64 &b) {
		if(i64(a -= b.a) < 0) a += 2 * mod;
		return *this;
	}

	modint64 &operator*=(const modint64 &b) {
		a = reduce(u128(a) * b.a);
		return *this;
	}

	modint64 operator+(const modint64 &b) const { return modint64(*this) += b; }
	modint64 operator-(const modint64 &b) const { return modint64(*this) -= b; }
	modint64 operator*(const modint64 &b) const { return modint64(*this) *= b; }

	modint64 pow(u128 n) const {
		modint64 ret(1), mul(*this);
		while(n > 0) {
			if(n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	u64 val() const {
		u64 ret = reduce(a);
		return ret >= mod ? ret - mod : ret;
	}

	static u64 get_mod() { return mod; }

private:
	u64 a;

	static u64 get_r() {
		u64 ret = mod;
		for(u32 i = 0; i < 5; i++) ret *= 2 - mod * ret;
		return ret;
	}

	static u64 reduce(const u128 &b) {
		return (b + u128(u64(b) * u64(-r)) * mod) >> 64;
	}
};
typename modint64::u64 modint64::mod, modint64::r, modint64::n2;

u64 rnd() {
	static u64 x = 10150724397891781847ull;
	x ^= x << 7;
	return x ^= x >> 9;
}

constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if(x < 0) x += m;
	return x;
}

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
	if(m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	unsigned long long y = safe_mod(x, m);
	while(n) {
		if(n & 1) r = (r * y) % _m;
		y = (y * y) % _m;
		n >>= 1;
	}
	return r;
}

bool is_prime(const u64 n) {
	if(~n & 1) return n == 2;
	if(n < (1ll << 30)) {
		if(n <= 1) return false;
		if(n == 2 || n == 7 || n == 61) return true;
		if(n % 2 == 0) return false;
		long long d = n - 1;
		while(d % 2 == 0) d /= 2;
		constexpr long long bases[3] = {2, 7, 61};
		for(long long a : bases) {
			long long t = d;
			long long y = pow_mod_constexpr(a, t, n);
			while(t != n - 1 && y != 1 && y != n - 1) {
				y = y * y % n;
				t <<= 1;
			}
			if(y != n - 1 && t % 2 == 0) {
				return false;
			}
		}
		return true;
	}
	u64 d = n - 1;
	while(~d & 1) d >>= 1;
	if(modint64::get_mod() != n) modint64::set_mod(n);
	for(const u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		if(n <= a) break;
		modint64 t = d, y = modint64(a).pow(d);
		while(t.val() != n - 1 and y.val() != 1 and y.val() != n - 1) {
			y *= y;
			t *= 2;
		}
		if(y.val() != n - 1 and ~t.val() & 1) return false;
	}
	return true;
}

u64 pollard_rho(const u64 n) {
	if(~n & 1) return 2;
	if(is_prime(n)) return n;
	if(modint64::get_mod() != n) modint64::set_mod(n);
	modint64 R, one = 1;
	auto f = [&](modint64 x) { return x * x + R; };
	auto rng = [&]() { return rnd() % (n - 2) + 2; };
	for(;;) {
		modint64 x, y(rng()), ys, q = one;
		R = rng();
		u64 g = 1;
		constexpr u32 m = 128;
		for(u32 r = 1; g == 1; r <<= 1) {
			x = y;
			for(u32 i = 0; i < r; i++) y = f(y);
			for(u32 k = 0; g == 1 and k < r; k += m) {
				ys = y;
				for(u32 i = 0; i < m and i < r - k; i++) q *= x - (y = f(y));
				g = gcd_fast(q.val(), n);
			}
		}
		if(g == n) do
				g = gcd_fast((x - (ys = f(ys))).val(), n);
			while(g == 1);
		if(g != n) return g;
	}
	exit(1);
}

std::vector<u64> factorize(const u64 n) {
	if(n == 1) return {};
	if(is_prime(n)) return {n};
	auto d = pollard_rho(n);
	auto res = factorize(d);
	auto sub = factorize(n / d);
	std::copy(sub.begin(), sub.end(), std::back_inserter(res));
	return res;
}

};  // namespace inner
using inner::is_prime;

template <typename T>
std::vector<T> factorize(const T n) {
	auto tmp = inner::factorize(n);
	std::vector<T> res{tmp.begin(), tmp.end()};
	std::sort(res.begin(), res.end());
	return res;
}

template <typename T>
std::vector<std::pair<T, int>> pair_factorize(const T n) {
	std::vector<std::pair<T, int>> res;
	auto tmp = factorize(n);
	if(tmp.empty()) return {};
	T now = tmp.front();
	int cnt = 0;
	for(auto &v : tmp) {
		if(now == v)
			cnt++;
		else {
			res.emplace_back(now, cnt);
			now = v;
			cnt = 1;
		}
	}
	res.emplace_back(now, cnt);
	return res;
}
