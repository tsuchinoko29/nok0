#pragma once
#include <cassert>
#include <iostream>
#include <vector>

template <class T>
struct matrix {
private:
	std::vector<std::vector<T>> A;

	static matrix I(size_t n) {
		matrix mat(n);
		for(int i = 0; i < n; i++) mat[i][i] = 1;
		return mat;
	}

public:
	matrix() = default;

	matrix(std::vector<std::vector<T>> &vvec) { A = vvec; }

	matrix(size_t n, size_t m) : A(n, std::vector<T>(m, 0)) {}

	matrix(size_t n, size_t m, T init) : A(n, std::vector<T>(m, init)) {}

	matrix(size_t n, std::vector<T> &vec) : A(n, vec) {}

	matrix(size_t n) : A(n, std::vector<T>(n, 0)) {}

	size_t height() const { return A.size(); }

	size_t width() const { return A[0].size(); }

	inline const std::vector<T> &operator[](int k) const {
		return A[k];
	}

	inline std::vector<T> &operator[](int k) {
		return A[k];
	}

	matrix &operator+=(const matrix &B) {
		size_t n = height(), m = width();
		assert(n == B.height() and m == B.width());
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] += B[i][j];
		return *this;
	}

	matrix &operator-=(const matrix &B) {
		size_t n = height(), m = width();
		assert(n == B.height() and m == B.width());
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] -= B[i][j];
		return *this;
	}

	matrix &operator*=(const matrix &B) {
		size_t n = height(), m = B.width(), p = width();
		assert(p == B.height());
		std::vector<std::vector<T>> C(n, std::vector<T>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				for(int k = 0; k < p; k++)
					C[i][j] += (*this)[i][k] * B[k][j];
		A.swap(C);
		return *this;
	}

	matrix &operator^=(long long k) {
		matrix B = matrix::I(height());
		while(k > 0) {
			if(k & 1) B *= (*this);
			*this *= *this;
			k >>= 1ll;
		}
		A.swap(B.A);
		return *this;
	}

	bool operator==(const matrix &B) {
		size_t n = height(), m = width();
		if(n != B.height() or m != B.width()) return false;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if((*this)[i][j] != B[i][j]) return false;
		return true;
	}

	matrix operator+(const matrix &B) const {
		return (matrix(*this) += B);
	}

	matrix operator-(const matrix &B) const {
		return (matrix(*this) -= B);
	}

	matrix operator*(const matrix &B) const {
		return (matrix(*this) *= B);
	}

	matrix operator^(const long long &k) const {
		return (matrix(*this) ^= k);
	}

	matrix &operator+=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] += t;
		return *this;
	}

	matrix &operator-=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] -= t;
		return *this;
	}

	matrix &operator*=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] *= t;
		return *this;
	}

	matrix &operator/=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] /= t;
		return *this;
	}

	matrix operator+(const T &t) const {
		return (matrix(*this) += t);
	}

	matrix operator-(const T &t) const {
		return (matrix(*this) -= t);
	}

	matrix operator*(const T &t) const {
		return (matrix(*this) *= t);
	}

	matrix operator/(const T &t) const {
		return (matrix(*this) /= t);
	}

	friend std::ostream &operator<<(std::ostream &os, matrix &p) {
		size_t n = p.height(), m = p.width();
		for(int i = 0; i < n; i++) {
			os << '[';
			for(int j = 0; j < m; j++)
				os << p[i][j] << (j == m - 1 ? "]\n" : ",");
		}
		return (os);
	}

	T determinant() {
		matrix B(*this);
		size_t n = height(), m = width();
		assert(n == m);
		T ret = 1;
		for(int i = 0; i < n; i++) {
			int idx = -1;
			for(int j = i; j < n; j++)
				if(B[j][i] != 0) idx = j;
			if(idx == -1) return 0;
			if(i != idx) {
				ret *= -1;
				swap(B[i], B[idx]);
			}
			ret *= B[i][i];
			T vv = B[i][i];
			for(int j = 0; j < n; j++) B[i][j] /= vv;
			for(int j = i + 1; j < n; j++) {
				T a = B[j][i];
				for(int k = 0; k < n; k++) {
					B[j][k] -= B[i][k] * a;
				}
			}
		}
		return ret;
	}
};
