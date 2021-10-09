#pragma once
#include "math/formal_power_series.hpp"

template <class F>
F Berlekamp_Massey(const F &a) {
	using T = typename F::value_type;
	int n = a.size();
	F c{-1}, c2{0};
	T r2 = 1;
	int i2 = -1;
	for(int i = 0; i < n; i++) {
		T r = 0;
		int d = c.size();
		for(int j = 0; j < d; j++) r += c[j] * a[i - j];
		if(r == 0) continue;
		T coef = -r / r2;
		int d2 = c2.size();
		if(d - i >= d2 - i2) {
			for(int j = 0; j < d2; j++)
				c[j + i - i2] += c2[j] * coef;
		} else {
			F tmp(c);
			c.resize(d2 + i - i2);
			for(int j = 0; j < d2; j++) c[j + i - i2] += c2[j] * coef;
			c2 = std::move(tmp);
			i2 = i, r2 = r;
		}
	}
	return {c.begin() + 1, c.end()};
}

//return generating function of a, s.t. F(x) = P(x) / Q(x)
template <class F>
std::pair<F, F> find_generating_function(F a) {
	auto q = Berlekamp_Massey(a);
	int d = q.size();
	a.resize(d);
	q.insert(q.begin(), 1);
	for(int i = 1; i < (int)q.size(); i++) q[i] *= -1;
	a *= q;
	return {a, q};
}

//return [x^k] p(x) / q(x)
template <class T, Mode mode>
T compute_Kthterm(formal_power_series<T, mode> p, formal_power_series<T, mode> q, long long k) {
	int d = q.size();
	assert(q[0] == 1 and p.size() + 1 <= d);
	while(k) {
		auto q_minus = q;
		for(int i = 1; i < d; i += 2)
			q_minus[i] *= -1;
		p.resize(2 * d);
		q.resize(2 * d);
		p *= q_minus;
		q *= q_minus;
		for(int i = 0; i < d - 1; i++)
			p[i] = p[(i << 1) | (k & 1)];
		for(int i = 0; i < d; i++)
			q[i] = q[i << 1];
		p.resize(d - 1);
		q.resize(d);
		k >>= 1;
	}
	return p[0];
}

template <class T, Mode mode>
T compute_Kthterm(std::pair<formal_power_series<T, mode>, formal_power_series<T, mode>> f, long long k) { return compute_Kthterm(f.first, f.second, k); }
