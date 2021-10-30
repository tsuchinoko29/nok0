#pragma once
#include <vector>

template <class T>
T maximum_independent_set(std::vector<std::vector<int>> graph, std::vector<T> weight) {
	const int n = graph.size();
	assert(n == (int)weight.size());
	const int l = n / 2, r = n - l;
	const int right_rev_mask = (1 << r) - 1;
	std::vector lef_mask(l, 0), rig_mask(r, 0), lef_rig_mask(l, 0);
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < l; j++) lef_mask[i] |= graph[i][j] << j;
		for(int j = 0; j < r; j++) lef_rig_mask[i] |= graph[i][l + j] << j;
	}
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < r; j++) rig_mask[i] |= graph[l + i][l + j] << j;
	}

	std::vector<T> right_solve(1 << r);
	for(int bit = 0; bit < 1 << r; bit++) {
		int rmask = 0;
		T sum = 0;
		for(int i = 0; i < r; i++) {
			if(bit >> i & 1) rmask |= rig_mask[i], sum += weight[l + i];
		}
		if(rmask & bit) continue;
		right_solve[bit] = sum;
	}
	for(int i = 0; i < r; i++) {
		for(int bit = 0; bit < 1 << r; bit++) {
			if(bit & (1 << i)) right_solve[bit] = max(right_solve[bit], right_solve[bit ^ (1 << i)]);
		}
	}

	T res = 0;

	for(int bit = 0; bit < 1 << l; bit++) {
		T sum = 0;
		int lmask = 0, rmask = 0;
		for(int i = 0; i < l; i++) {
			if(bit >> i & 1) {
				lmask |= lef_mask[i];
				rmask |= lef_rig_mask[i];
				sum += weight[i];
			}
		}
		if(lmask & bit) continue;
		res = max(res, sum + right_solve[rmask ^ right_rev_mask]);
	}
	return res;
}

int maximum_independent_set(std::vector<std::vector<int>> graph) {
	const int n = (int)graph.size();
	return maximum_independent_set(graph, std::vector(n, 1));
}
