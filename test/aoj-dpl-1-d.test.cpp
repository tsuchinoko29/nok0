#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <iostream>
#include <math/lis.hpp>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector a(n, 0);
	for(auto &v : a) std::cin >> v;
	std::cout << longest_increasing_subsequence(a) << '\n';
}