#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../data_structure/binary_indexed_tree.hpp"
#include "../template.hpp"

void main_() {
	int n, q;
	cin >> n >> q;
	binary_indexed_tree<int> bt(n);
	while(q--) {
		int t, x, y;
		cin >> t >> x >> y, --x;
		if(t == 0)
			bt.add(x, y);
		else
			cout << bt.sum(x, y) << '\n';
	}
}