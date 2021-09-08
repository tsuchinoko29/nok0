#include <algorithm>
#include <limits>
#include <vector>

template <class T>
struct li_chao_tree {
public:
	const T INF = std::numeric_limits<T>::max();

	li_chao_tree(const std::vector<T>& xs_) : xs(xs_) {
		sort(xs.begin(), xs.end());
		xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
		n = xs.size();
		fs.assign(n << 1, line(T(0), INF));
	}

	//add f(x) = ax + b
	void add_line(T a, T b) { update(a, b, 0, n); }

	//add f(x) = ax + b　(x ∈ [xl, xr) (if closed, [xl, xr]))
	void add_segment(T a, T b, T xl, T xr, bool closed = false) {
		int l = index(xl), r = index(xr);
		if(closed) r++;
		update(a, b, l, r);
	}

	T get_min(T x) const {
		int i = index(x);
		T ret = INF;
		for(i += n; i; i >>= 1) ret = std::min(ret, fs[i](x));
		return ret;
	}

private:
	struct line {
		T a, b;
		line(T a, T b) : a(a), b(b) {}
		T operator()(T x) const { return a * x + b; }
	};
	int n;
	std::vector<line> fs;
	std::vector<T> xs;

	int index(T x) const { return std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), x)); }

	void update(T a, T b, int l, int r) {
		line g(a, b);
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) descend(g, l++);
			if(r & 1) descend(g, --r);
		}
	}

	void descend(line g, int i) {
		int l = i, r = i + 1;
		while(l < n) l <<= 1, r <<= 1;
		while(l < r) {
			int c = (l + r) >> 1;
			T xl = xs[l - n], xr = xs[r - 1 - n], xc = xs[c - n];
			line& f = fs[i];
			if(f(xl) <= g(xl) and f(xr) <= g(xr)) return;
			if(f(xl) >= g(xl) and f(xr) >= g(xr)) {
				f = g;
				return;
			}
			if(f(xc) > g(xc)) std::swap(f, g);
			if(f(xl) > g(xl))
				i = i << 1 | 0, r = c;
			else
				i = i << 1 | 1, l = c;
		}
	}
};
