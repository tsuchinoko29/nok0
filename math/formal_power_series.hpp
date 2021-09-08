#pragma once
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "atcoder/convolution"
#include "math/factorial.hpp"

enum Mode {
	FAST = 1,
	NAIVE = -1,
};
template <class T, Mode mode = FAST>
struct formal_power_series : std::vector<T> {
	factorial<T> fact;
	using std::vector<T>::vector;
	using std::vector<T>::size;
	using std::vector<T>::resize;
	using std::vector<T>::begin;
	using std::vector<T>::insert;
	using std::vector<T>::erase;
	using F = formal_power_series;
	using S = std::vector<std::pair<int, T>>;

	F &operator+=(const F &g) {
		for(int i = 0; i < int(std::min((*this).size(), g.size())); i++) (*this)[i] += g[i];
		return *this;
	}

	F &operator+=(const T &t) {
		assert(int((*this).size()));
		(*this)[0] += t;
		return *this;
	}

	F &operator-=(const F &g) {
		for(int i = 0; i < int(std::min((*this).size(), g.size())); i++) (*this)[i] -= g[i];
		return *this;
	}

	F &operator-=(const T &t) {
		assert(int((*this).size()));
		(*this)[0] -= t;
		return *this;
	}

	F &operator*=(const T &t) {
		for(int i = 0; i < int((*this).size()); ++i) (*this)[i] *= t;
		return *this;
	}

	F &operator/=(const T &t) {
		T div = t.inv();
		for(int i = 0; i < int((*this).size()); ++i) (*this)[i] *= div;
		return *this;
	}

	F &operator>>=(const int sz) {
		assert(sz >= 0);
		int n = (*this).size();
		(*this).erase((*this).begin(), (*this).begin() + std::min(sz, n));
		(*this).resize(n);
		return *this;
	}

	F &operator<<=(const int sz) {
		assert(sz >= 0);
		int n = (*this).size();
		(*this).insert((*this).begin(), sz, T(0));
		(*this).resize(n);
		return *this;
	}

	F poly_div(const F &g) {
		if(this->size() < g.size()) {
			F ret(this->size());
			return ret;
		}
		if(mode == FAST) {
			auto ret = *this;
			int old = this->size();
			int n = old - g.size() + 1;
			ret = ((*this).rev().pre(n) * g.rev().inv(n));
			ret.rev_inplace();
			ret.resize(old);
			return ret;
		} else {
			assert(g.back() != T(0));
			T igb = g.back().inv();
			int n = (*this).size(), m = g.size();
			F this_copy(*this);
			F ret(n);
			for(int i = n - 1; i >= m - 1; --i) {
				T mul = this_copy[i] * igb;
				ret[i - m + 1] = mul;
				for(int j = i; j > i - m; j--)
					this_copy[j] -= g[j - i + m - 1] * mul;
			}
			return ret;
		}
	}

	//これのみ多項式の除算として扱う
	F &operator%=(const F &g) {
		return *this -= this->poly_div(g) * g;
	}

	F &operator=(const std::vector<T> &v) {
		int n = (*this).size();
		for(int i = 0; i < n; ++i) (*this)[i] = v[i];
		return *this;
	}

	F operator-() const {
		F ret = *this;
		return ret * -1;
	}

	F &operator*=(const F &g) {
		if(mode == FAST) {
			int n = (*this).size();
			auto tmp = atcoder::convolution(*this, g);
			for(int i = 0; i < n; ++i) (*this)[i] = tmp[i];
			return *this;
		} else {
			int n = (*this).size(), m = g.size();
			for(int i = n - 1; i >= 0; --i) {
				(*this)[i] *= g[0];
				for(int j = 1; j < std::min(i + 1, m); j++)
					(*this)[i] += (*this)[i - j] * g[j];
			}
			return *this;
		}
	}

	F &operator/=(const F &g) {
		if((*this).size() < g.size()) {
			(*this).assign((*this).size(), T(0));
			return *this;
		}
		if(mode == FAST) {
			*this *= g.inv();
			return *this;
		} else {
			assert(g[0] != T(0));
			T ig0 = g[0].inv();
			int n = (*this).size(), m = g.size();
			for(int i = 0; i < n; ++i) {
				for(int j = 1; j < std::min(i + 1, m); ++j)
					(*this)[i] -= (*this)[i - j] * g[j];
				(*this)[i] *= ig0;
			}
			return *this;
		}
	}

	F &operator*=(S g) {
		int n = (*this).size();
		auto [d, c] = g.front();
		if(!d)
			g.erase(g.begin());
		else
			c = 0;
		for(int i = n - 1; i >= 0; --i) {
			(*this)[i] *= c;
			for(auto &[j, b] : g) {
				if(j > i) break;
				(*this)[i] += (*this)[i - j] * b;
			}
		}
		return *this;
	}

	F &operator/=(S g) {
		int n = (*this).size();
		auto [d, c] = g.front();
		assert(!d and c != 0);
		T ic = c.inv();
		g.erase(g.begin());
		for(int i = 0; i < n; ++i) {
			for(auto &[j, b] : g) {
				if(j > i) break;
				(*this)[i] -= (*this)[i - j] * b;
			}
			(*this)[i] *= ic;
		}
		return *this;
	}

	F operator+(const F &g) const { return F(*this) += g; }

	F operator+(const T &t) const { return F(*this) += t; }

	F operator-(const F &g) const { return F(*this) -= g; }

	F operator-(const T &t) const { return F(*this) -= t; }

	F operator*(const F &g) const { return F(*this) *= g; }

	F operator*(const T &t) const { return F(*this) *= t; }

	F operator/(const F &g) const { return F(*this) /= g; }

	F operator/(const T &t) const { return F(*this) /= t; }

	F operator%(const F &g) const { return F(*this) %= g; }

	F operator*=(const S &g) const { return F(*this) *= g; }

	F operator/=(const S &g) const { return F(*this) /= g; }

	F pre(int d) const { return F((*this).begin(), (*this).begin() + std::min((int)(*this).size(), d)); }

	F &shrink() {
		while((int)(*this).size() > 1 and (*this).back() == T(0)) (*this).pop_back();
		return *this;
	}

	F &rev_inplace() {
		reverse((*this).begin(), (*this).end());
		return *this;
	}
	F rev() const { return F(*this).rev_inplace(); }

	// *=(1 + cz^d)
	F &multiply(const int d, const T c) {
		int n = (*this).size();
		if(c == T(1))
			for(int i = n - d - 1; i >= 0; --i)
				(*this)[i + d] += (*this)[i];
		else if(c == T(-1))
			for(int i = n - d - 1; i >= 0; --i)
				(*this)[i + d] -= (*this)[i];
		else
			for(int i = n - d - 1; i >= 0; --i)
				(*this)[i + d] += (*this)[i] * c;
		return *this;
	}
	// /=(1 + cz^d)
	F &divide(const int d, const T c) {
		int n = (*this).size();
		if(c == T(1))
			for(int i = 0; i < n - d; ++i) (*this)[i + d] -= (*this)[i];
		else if(c == T(-1))
			for(int i = 0; i < n - d; ++i) (*this)[i + d] += (*this)[i];
		else
			for(int i = 0; i < n - d; ++i) (*this)[i + d] -= (*this)[i] * c;
		return *this;
	}

	//Ο(N)
	T eval(const T &t) const {
		int n = (*this).size();
		T res = 0, tmp = 1;
		for(int i = 0; i < n; ++i) res += (*this)[i] * tmp, tmp *= t;
		return res;
	}

	F inv(int deg = -1) const {
		int n = (*this).size();
		assert(mode == FAST and n and (*this)[0] != 0);
		if(deg == -1) deg = n;
		assert(deg > 0);
		F res{(*this)[0].inv()};
		while(int(res.size()) < deg) {
			int m = res.size();
			F f((*this).begin(), (*this).begin() + std::min(n, m * 2)), r(res);
			f.resize(m * 2), atcoder::internal::butterfly(f);
			r.resize(m * 2), atcoder::internal::butterfly(r);
			for(int i = 0; i < m * 2; ++i) f[i] *= r[i];
			atcoder::internal::butterfly_inv(f);
			f.erase(f.begin(), f.begin() + m);
			f.resize(m * 2), atcoder::internal::butterfly(f);
			for(int i = 0; i < m * 2; ++i) f[i] *= r[i];
			atcoder::internal::butterfly_inv(f);
			T iz = T(m * 2).inv();
			iz *= -iz;
			for(int i = 0; i < m; ++i) f[i] *= iz;
			res.insert(res.end(), f.begin(), f.begin() + m);
		}
		res.resize(deg);
		return res;
	}

	//Ο(N)
	F &diff_inplace() {
		int n = (*this).size();
		for(int i = 1; i < n; ++i) (*this)[i - 1] = (*this)[i] * i;
		(*this)[n - 1] = 0;
		return *this;
	}
	F diff() const { F(*this).diff_inplace(); }

	//Ο(N)
	F &integral_inplace() {
		int n = (*this).size(), mod = T::mod();
		std::vector<T> inv(n);
		{
			inv[1] = 1;
			for(int i = 2; i < n; ++i)
				inv[i] = T(mod) - inv[mod % i] * (mod / i);
		}
		for(int i = n - 2; i >= 0; --i) (*this)[i + 1] = (*this)[i] * inv[i + 1];
		(*this)[0] = 0;
		return *this;
	}
	F integral() const { return F(*this).integral_inplace(); }

	//Ο(NlogN)
	F &log_inplace() {
		int n = (*this).size();
		assert(n and (*this)[0] == 1);
		F f_inv = (*this).inv();
		(*this).diff_inplace();
		(*this) *= f_inv;
		(*this).integral_inplace();
		return *this;
	}
	F log() const { return F(*this).log_inplace(); }

	//Ο(NlogN)
	F &deriv_inplace() {
		int n = (*this).size();
		assert(n);
		for(int i = 2; i < n; ++i) (*this)[i] *= i;
		(*this).erase((*this).begin());
		(*this).push_back(0);
		return *this;
	}
	F deriv() const { return F(*this).deriv_inplace(); }

	//Ο(NlogN)
	F &exp_inplace() {
		int n = (*this).size();
		assert(n and (*this)[0] == 0);
		F g{1};
		(*this)[0] = 1;
		F h_drv((*this).deriv());
		for(int m = 1; m < n; m *= 2) {
			F f((*this).begin(), (*this).begin() + m);
			f.resize(2 * m), atcoder::internal::butterfly(f);
			auto mult_f = [&](F &p) {
				p.resize(2 * m);
				atcoder::internal::butterfly(p);
				for(int i = 0; i < 2 * m; ++i) p[i] *= f[i];
				atcoder::internal::butterfly_inv(p);
				p /= 2 * m;
			};
			if(m > 1) {
				F g_(g);
				g_.resize(2 * m), atcoder::internal::butterfly(g_);
				for(int i = 0; i < 2 * m; ++i) g_[i] *= g_[i] * f[i];
				atcoder::internal::butterfly_inv(g_);
				T iz = T(-2 * m).inv();
				g_ *= iz;
				g.insert(g.end(), g_.begin() + m / 2, g_.begin() + m);
			}
			F t((*this).begin(), (*this).begin() + m);
			t.deriv_inplace();
			{
				F r{h_drv.begin(), h_drv.begin() + m - 1};
				mult_f(r);
				for(int i = 0; i < m; ++i) t[i] -= r[i] + r[m + i];
			}
			t.insert(t.begin(), t.back());
			t.pop_back();
			t *= g;
			F v((*this).begin() + m, (*this).begin() + std::min(n, 2 * m));
			v.resize(m);
			t.insert(t.begin(), m - 1, 0);
			t.push_back(0);
			t.integral_inplace();
			for(int i = 0; i < m; ++i) v[i] -= t[m + i];
			mult_f(v);
			for(int i = 0; i < std::min(n - m, m); ++i)
				(*this)[m + i] = v[i];
		}
		return *this;
	}
	F exp() const { return F(*this).exp_inplace(); }

	//Ο(NlogN)
	F &pow_inplace(long long k) {
		int n = (*this).size(), l = 0;
		assert(k >= 0);
		if(!k) {
			for(int i = 0; i < n; ++i) (*this)[i] = !i;
			return *this;
		}
		while(l < n and (*this)[l] == 0) ++l;
		if(l > (n - 1) / k or l == n) return *this = F(n);
		T c = (*this)[l];
		(*this).erase((*this).begin(), (*this).begin() + l);
		(*this) /= c;
		(*this).log_inplace();
		(*this).resize(n - l * k);
		(*this) *= k;
		(*this).exp_inplace();
		(*this) *= c.pow(k);
		(*this).insert((*this).begin(), l * k, 0);
		return *this;
	}
	F pow(const long long k) const { return F(*this).pow_inplace(k); }

	//Ο(NlogN)
	F sqrt(int deg = -1) const {
		auto SQRT = [&](T t) {
			int mod = T::mod();
			if(t == 0 or t == 1) return t;
			int v = (mod - 1) / 2;
			if(t.pow(v) != 1) return T(-1);
			int q = mod - 1, m = 0;
			while(~q & 1) q >>= 1, m++;
			std::mt19937 mt;
			T z = mt();
			while(z.pow(v) != mod - 1) z = mt();
			T c = z.pow(q), u = t.pow(q), r = t.pow((q + 1) / 2);
			for(; m > 1; m--) {
				T tmp = u.pow(1 << (m - 2));
				if(tmp != 1) r = r * c, u = u * c * c;
				c = c * c;
			}
			return T(std::min(r.val(), mod - r.val()));
		};
		int n = (*this).size();
		if(deg == -1) deg = n;
		if((*this)[0] == 0) {
			for(int i = 1; i < n; i++) {
				if((*this)[i] != 0) {
					if(i & 1) return F(0);
					if(deg - i / 2 <= 0) break;
					auto ret = (*this);
					ret >>= i;
					ret.resize(n - i);
					ret = ret.sqrt(deg - i / 2);
					if(ret.empty()) return F(0);
					ret <<= (i / 2);
					ret.resize(deg);
					return ret;
				}
			}
			return F(deg);
		}
		auto sqr = SQRT((*this)[0]);
		if(sqr * sqr != (*this)[0]) return F(0);
		F ret{sqr};
		T ti = T(1) / T(2);
		for(int i = 1; i < deg; i <<= 1) {
			auto u = (*this);
			u.resize(i << 1);
			ret = (ret.inv(i << 1) * u + ret) * ti;
		}
		ret.resize(deg);
		return ret;
	}

	void sparse_pow(const int n, const int d, const T c, const int k) {
		F ret(n);
		T tmp = 1;
		if(k >= 0) {
			for(int i = 0; i < n; i += d) {
				ret[i] = fact.binom(k, i / d) * tmp;
				tmp *= c;
			}
		} else {
			for(int i = 0; i < n; i += d) {
				ret[i] = fact.binom(i / d - k - 1, -k - 1) * tmp;
				tmp *= -c;
			}
		}
		(*this) = ret;
	}

	void sparse_pow_inv(const int n, const int d, const T c, const int k) { return sparse_pow(n, d, c, -k); }

	void stirling_first(int n) {
		if(!n) {
			*this = F{1};
			return;
		}
		int m = 1;
		F res(n + 1);
		res[1] = 1;
		for(int k = 30 - __builtin_clz(n); k >= 0; --k) {
			F as(m * 2 + 1), bs(m + 1);
			for(int i = 0; i <= m; i++)
				as[i] = fact.fac[i] * res[i];

			bs[m] = 1;
			for(int i = m - 1; i >= 0; i--)
				bs[i] -= bs[i + 1] * m;

			for(int i = 0; i <= m; i++)
				bs[m - i] *= fact.finv[i];

			F cs = as * bs, ds(m + 1);
			for(int i = 0; i <= m; i++)
				ds[i] = cs[m + i] * fact.finv[i];

			res *= ds;
			m <<= 1;
			if(n >> k & 1) {
				F g(n + 1);
				for(int i = 0; i <= m; i++) {
					g[i] -= res[i] * m;
					g[i + 1] += res[i];
				}
				res = g;
				m |= 1;
			}
		}
		*this = res;
	}

	void stirling_second(int n) {
		F f(n + 1), g(n + 1);
		for(int i = 0; i <= n; i++) {
			f[i] = T(i).pow(n) * fact.finv[i];
			g[i] = fact.finv[i] * (i % 2 ? -1 : 1);
		}
		f *= g;
		*this = f;
	}

	std::vector<T> multipoint_evaluation(const std::vector<T> &p);
};
