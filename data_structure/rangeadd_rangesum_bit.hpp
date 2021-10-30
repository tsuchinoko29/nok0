#include <vector>

template <class T>
struct rangeadd_rangesum_bit {
private:
	std::vector<T> vec1, vec2;
	size_t n;

public:
	rangeadd_rangesum_bit() = default;
	rangeadd_rangesum_bit(size_t n_) : n(n_ + 1), vec1(n_ + 2, 0), vec2(n_ + 2, 0) {}

	//add x for [l, r)
	void add(int l, int r, T x = T(1)) {
		l++;
		r++;
		for(int i = l; i <= n; i += i & -i) vec1[i] -= x * l;
		for(int i = l; i <= n; i += i & -i) vec2[i] += x;
		for(int i = r; i <= n; i += i & -i) vec1[i] += x * r;
		for(int i = r; i <= n; i += i & -i) vec2[i] -= x;
	}

	//return sum[0, r)
	T sum(int r) {
		r += 1;
		T ret = 0;
		for(int x = r; x > 0; x -= x & -x) ret += vec1[x];
		for(int x = r; x > 0; x -= x & -x) ret += vec2[x] * r;
		return ret;
	}

	//return sum[l, r)
	T sum(int l, int r) { return sum(r) - sum(l); }

	T operator[](int x) { return sum(x, x + 1); }
};
