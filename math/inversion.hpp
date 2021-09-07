#include <vector>

//配列の転倒数(i < j and a[i] > a[j]を満たす組の個数)を返す
//配列が非負かつMaxが1e5まで程度に対応
template <class T>
long long inversion(std::vector<T> vec) {
	long long res = 0;
	int n = *max_element(vec.begin(), vec.end()) + 1;
	std::vector<T> d(n + 1, 0);
	for(int i = 0; i < vec.size(); i++) {
		res += i;
		for(int j = vec[i] + 1; j; j -= j & -j) res -= d[j];
		for(int j = vec[i] + 1; j <= n; j += j & -j) d[j] += 1;
	}
	return res;
}
