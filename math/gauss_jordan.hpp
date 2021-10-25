#pragma once
#include "math/matrix.hpp"

template <class T>
void gauss_elimination(matrix<T> &mat) {
	constexpr T eps = 1e-8;
	const int h = mat.height(), w = mat.width();
	int rank = 0;
	for(int j = 0; j < w; j++) {
		int pivot = -1;
		T mx = eps;
		for(int i = rank; i < h; i++) {
			if(mx < abs(mat[i][j])) {
				mx = abs(mat[i][j]);
				pivot = i;
			}
		}
		if(pivot == -1) continue;
		swap(mat[rank], mat[pivot]);

		const auto cur = T(1) / mat[rank][j];

		for(int i = rank + 1; i < n; i++) {
			if(abs(mat[i][j]) > eps) {
				auto tmp = mat[i][j] * cur;
				for(int j2 = i + 1; j2 < n; j2++)
					mat[i][j2] -= tmp * mat[rank][j2];
			}
		}
	}
}