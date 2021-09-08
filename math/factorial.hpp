#include <atcoder/modint>
#include <cassert>
#include <vector>

template <class T>
struct factorial {
public:
	static int MAX;
	static std::vector<T> fac, finv, inv;

	factorial() {}

	T binom(int n, int r) {
		if(n < r or n < 0 or r < 0) return T(0);
		assert(n < MAX);
		return fac[n] * finv[r] * finv[n - r];
	}

	T large_binom(int n, int r) {
		if(n < r or n < 0 or r < 0) return T(0);
		assert(r < MAX);
		T ret = finv[r];
		for(int i = 1; i <= r; ++i)
			ret *= (n + 1 - i);
		return ret;
	}

	static void set_size(int n) {
		MAX = (n > 1 ? n : 1) + 1;
		fac.resize(MAX);
		finv.resize(MAX);
		inv.resize(MAX);
		const int MOD = T::mod();
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for(int i = 2; i < MAX; i++) {
			fac[i] = fac[i - 1] * i;
			inv[i] = (T)MOD - inv[MOD % i] * (MOD / i);
			finv[i] = finv[i - 1] * inv[i];
		}
	}
};
template <class T>
int factorial<T>::MAX = 0;
template <class T>
std::vector<T> factorial<T>::fac;
template <class T>
std::vector<T> factorial<T>::finv;
template <class T>
std::vector<T> factorial<T>::inv;
