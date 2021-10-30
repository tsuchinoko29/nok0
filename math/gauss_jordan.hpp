#pragma once
#include "math/matrix.hpp"

template <class T>
int gauss_elimination_mint(matrix<T> &mat, bool is_extended = false) {
	const int h = mat.height(), w = mat.width();
	int rank = 0;
	for(int j = 0; j < w; j++) {
		if(is_extended and j == w - 1) break;
		int pivot = -1;
		for(int i = rank; i < h; i++) {
			if(mat[i][j] != T(0)) {
				pivot = i;
				break;
			}
		}
		if(pivot == -1) continue;
		swap(mat[rank], mat[pivot]);

		const auto cur = T(1) / mat[rank][j];

		for(int j2 = 0; j2 < w; j2++) mat[rank][j2] *= cur;

		for(int i = 0; i < h; i++) {
			if(i != rank and mat[i][j] != T(0)) {
				auto fac = mat[i][j];
				for(int j2 = 0; j2 < w; j2++)
					mat[i][j2] -= mat[rank][j2] * fac;
			}
		}
		rank++;
	}
	return rank;
}

//return {x, rank} s.t. ax = b
//if no solution, return empty x
template <class T>
std::pair<std::vector<T>, int> linear_equation_mint(const matrix<T> &a, const std::vector<T> &b) {
	int h = a.height(), w = a.width();
	matrix<T> eq(h, w + 1);
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) eq[i][j] = a[i][j];
		eq[i][w] = b[i];
	}
	int rank = gauss_elimination_mint(eq, true);

	for(int i = rank; i < h; i++)
		if(eq[i].back() != T(0)) return std::pair(vector<T>{}, -1);

	std::vector<T> res(h);
	for(int i = 0; i < h; i++) res[i] = eq[i].back();

	return std::pair(res, rank);
}