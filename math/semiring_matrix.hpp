#include <bits/stdc++.h>

template <class S, S (*add)(S, S), S (*add_ide)(), S (*mul)(S, S), S (*mul_ide)()>
struct semiring {
	S val;
	semiring() : val(add_ide()) {}
	semiring(S val_) : val(val_) {}
	semiring &operator+=(const semiring &oth) {
		val = add(val, oth.val);
		return *this;
	}
	semiring operator+(const semiring &oth) { return semiring(*this) += oth; }
	semiring &operator*=(const semiring &oth) {
		val = mul(val, oth.val);
		return *this;
	}
	semiring operator*(const semiring &oth) { return semiring(*this) *= oth; }

	static semiring add_identity() { return semiring(add_ide()); }
	static semiring mul_identity() { return semiring(mul_ide()); }
};

template <class S>
struct semiring_mat {
private:
	std::vector<std::vector<S>> A;

	const S add_ide = S::add_identity();
	const S mul_ide = S::mul_identity();

public:
	semiring_mat() = default;
	semiring_mat(size_t n) : A(n, std::vector<S>(n)) {
		for(size_t i = 0; i < n; i++)
			for(size_t j = 0; j < n; j++) A[i][j] = add_ide;
	}
	semiring_mat(size_t n, size_t m) : A(n, std::vector<S>(m)) {
		for(size_t i = 0; i < n; i++)
			for(size_t j = 0; j < m; j++) A[i][j] = add_ide;
	}
	semiring_mat(size_t n, size_t m, S init) : A(n, std::vector<S>(m)) {
		for(size_t i = 0; i < n; i++)
			for(size_t j = 0; j < m; j++) A[i][j] = init;
	}

	inline const std::vector<S> &operator[](size_t k) const {
		return A[k];
	}
	inline std::vector<S> &operator[](size_t k) {
		return A[k];
	}

	size_t height() const { return A.size(); }
	size_t width() const { return A[0].size(); }

	semiring_mat &operator+=(const semiring_mat &B) {
		size_t n = height(), m = width();
		assert(n == B.height() and m == B.width());
		for(size_t i = 0; i < n; i++)
			for(size_t j = 0; j < m; j++)
				(*this)[i][j] += B[i][j];
		return *this;
	}
	semiring_mat operator+(const semiring_mat &B) const {
		return (mat(*this) += B);
	}

	semiring_mat &operator*=(const semiring_mat &B) {
		size_t n = height(), m = B.width(), p = width();
		assert(p == B.height());
		std::vector<std::vector<S>> C(n, std::vector<S>(m, add_ide));
		for(size_t i = 0; i < n; i++)
			for(size_t j = 0; j < m; j++)
				for(size_t k = 0; k < p; k++)
					C[i][j] += (*this)[i][k] * B[k][j];

		A.swap(C);
		return *this;
	}
	semiring_mat operator*(const semiring_mat &B) const {
		return (mat(*this) *= B);
	}

	semiring_mat &operator^=(long long k) {
		semiring_mat B = semiring_mat::E(height());
		while(k > 0) {
			if(k & 1) B *= (*this);
			*this *= *this;
			k >>= 1ll;
		}
		A.swap(B.A);
		return *this;
	}
	semiring_mat operator^(const long long k) const {
		return (mat(*this) ^= k);
	}

	static semiring_mat E(size_t n) {
		semiring_mat mat(n, n);
		for(size_t i = 0; i < n; i++) mat[i][i] = S::mul_identity();
		return mat;
	}
};
