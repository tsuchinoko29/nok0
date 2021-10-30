#pragma once
#include <cassert>
#include <vector>

template <typename T>
struct rolling_hash {
private:
	int n;
	const long long mod = (1ll << 61) - 1;
	const int base = 1007;
	std::vector<__int128_t> hash, power;

public:
	rolling_hash() = default;

	rolling_hash(const T &s) : n(s.size()) {
		hash.assign(n + 1, 0);
		power.assign(n + 1, 1);
		for(int i = 0; i < n; i++) {
			hash[i + 1] = (hash[i] * base + s[i]) % mod;
			power[i + 1] = (power[i] * base) % mod;
		}
	}
	//[l, r)のhash値を取得
	long long get(const int l, const int r) const {
		assert(l < r and l >= 0 and r <= n);
		long long res = hash[r] - hash[l] * power[r - l] % mod;
		if(res < 0) res += mod;
		return res;
	}

	//全体のhashを取得
	long long s_hash() const { return get(0, n); }

	//[a, n) と[b, n)の最長共通接頭辞の長さを取得
	int getLCP(const int a, const int b) const {
		assert(a >= 0 and a < n and b >= 0 and b < n);
		int len = std::min(n - a, n - b), ok = 0, ng = len;
		while(ng - ok > 1) {
			int mid = (ok + ng) / 2;
			if(get(a, a + mid) != get(b, b + mid))
				ng = mid;
			else
				ok = mid;
		}
		return ok;
	}
};
