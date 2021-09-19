#include <cassert>
#include <vector>

#include "atcoder/internal_bit"

template <class S, S (*op)(S, S)>
struct sparse_table {
public:
	sparse_table() : sparse_table(0) {}
	explicit sparse_table(const std::vector<S>& v) : _n(int(v.size())), lt(int(v.size()) + 1) {
		log = atcoder::internal::ceil_pow2(_n);
		d.assign(log + 1, std::vector<S>(_n));
		for(int i = 0; i <= log; i++) {
			for(int j = 0; j <= _n - (1 << i); j++) {
				if(i)
					d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << i - 1)]);
				else
					d[i][j] = v[j];
			}
		}
		for(int i = 2; i <= _n; i++)
			lt[i] = lt[i >> 1] + 1;
	}

	S prod(int l, int r) const {
		assert(0 <= l && l <= r && r <= _n);
		int len = r - l;
		return op(d[lt[len]][l], d[lt[len]][r - (1 << lt[len])]);
	}

	S all_prod() const { return prod(0, _n); }

private:
	int _n, size, log;
	std::vector<std::vector<S>> d;
	std::vector<int> lt;
};
