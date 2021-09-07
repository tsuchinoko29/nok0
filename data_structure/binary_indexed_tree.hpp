#include <vector>

template <typename T>
struct binary_indexed_tree {
private:
	int n, p;
	std::vector<T> d;

public:
	binary_indexed_tree() = default;

	binary_indexed_tree(int n) : n(n), d(n + 1) {
		p = 1;
		while(p < n) p *= 2;
	}

	void add(int i, T x = 1) {
		for(i++; i <= n; i += i & -i) d[i] += x;
	}

	//return sum[0,i)
	T sum(int i) {
		T res = 0;
		for(; i; i -= i & -i) res += d[i];
		return res;
	}

	//return sum[l,r)
	T sum(int l, int r) { return sum(r) - sum(l); }

	//return min(x) which satisfies (v0 + v1 + ... + vx >= w)
	int lower_bound(T w) {
		if(w <= 0) return 0;
		T x = 0;
		for(int i = p; i; i /= 2) {
			if(i + x <= n && d[i + x] < w) {
				w -= d[i + x];
				x += i;
			}
		}
		return x;
	}
};
