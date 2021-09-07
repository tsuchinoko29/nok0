#include <atcoder/convolution>
#include <atcoder/modint>
#include <cassert>
#include <vector>

//Ο(N^2)
struct bostan_mori_ll {
public:
	bostan_mori_ll(const std::vector<long long> &a) {
		auto pq1 = find_generating_function(std::vector<mint1>{a.begin(), a.end()});
		p1 = std::move(pq1.first);
		q1 = std::move(pq1.second);
		auto pq2 = find_generating_function(std::vector<mint2>{a.begin(), a.end()});
		p2 = std::move(pq2.first);
		q2 = std::move(pq2.second);
		d = q1.size();
		assert(q1[0] == 1 and p1.size() + 1 <= q1.size());
	}

	long long kth_term(long long k) {
		long long r1, r2;
		{
			long long c = k;
			if(d == 1)
				return 0;
			auto p = p1, q = q1;
			while(c) {
				auto q_minus = q;
				for(int i = 1; i < d; i += 2)
					q_minus[i] *= -1;
				p = atcoder::convolution(p, q_minus);
				q = atcoder::convolution(q, q_minus);
				for(int i = 0; i < d - 1; i++)
					p[i] = p[(i << 1) | (c & 1)];
				for(int i = 0; i < d; i++)
					q[i] = q[i << 1];
				p.resize(d - 1);
				q.resize(d);
				c >>= 1;
			}
			r1 = p[0].val();
		}
		{
			long long c = k;
			if(d == 1)
				return 0;
			auto p = p2, q = q2;
			while(c) {
				auto q_minus = q;
				for(int i = 1; i < d; i += 2)
					q_minus[i] *= -1;
				p = atcoder::convolution(p, q_minus);
				q = atcoder::convolution(q, q_minus);
				for(int i = 0; i < d - 1; i++)
					p[i] = p[(i << 1) | (c & 1)];
				for(int i = 0; i < d; i++)
					q[i] = q[i << 1];
				p.resize(d - 1);
				q.resize(d);
				c >>= 1;
			}
			r2 = p[0].val();
		}
		return garner(r1, r2);
	}

private:
	static constexpr int m1 = 998244353;
	static constexpr int m2 = 1004535809;
	static constexpr int inv_m1_mod_m2 = 669690699;
	using mint1 = atcoder::static_modint<m1>;
	using mint2 = atcoder::static_modint<m2>;
	int d;
	std::vector<mint1> p1, q1;
	std::vector<mint2> p2, q2;

	long long garner(long long r1, long long r2) {
		long long t = atcoder::internal::safe_mod((r2 - r1) * inv_m1_mod_m2, m2);
		r1 += t * m1;
		return r1;
	}

	template <class T>
	std::vector<T> Berlekamp_Massey(const std::vector<T> &a) {
		int n = a.size();
		std::vector<T> c{-1}, c2{0};
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
				std::vector<T> tmp(c);
				c.resize(d2 + i - i2);
				for(int j = 0; j < d2; j++) c[j + i - i2] += c2[j] * coef;
				c2 = std::move(tmp);
				i2 = i, r2 = r;
			}
		}
		c[0] = 1;
		return c;
	}

	template <class T>
	std::pair<std::vector<T>, std::vector<T>> find_generating_function(std::vector<T> a) {
		auto q = Berlekamp_Massey(a);
		int d = q.size() - 1;
		a.resize(d);
		for(int i = 1; i < (int)q.size(); i++) q[i] *= -1;
		a = atcoder::convolution(a, q);
		a.resize(d);
		return {a, q};
	}
};
