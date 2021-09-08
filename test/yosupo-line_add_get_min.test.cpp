#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "data_structure/li_chao_tree.hpp"
#include "template.hpp"

void main_() {
	INT(n, q);
	V<ll> a(n), b(n), t(q), c(q), d(q), x;
	REP(i, n) { cin >> a[i] >> b[i]; }
	REP(i, q) {
		cin >> t[i];
		if(!t[i])
			cin >> c[i] >> d[i];
		else {
			cin >> c[i];
			x.pb(c[i]);
		}
	}
	li_chao_tree<ll> lct(x);
	REP(i, n) { lct.add_line(a[i], b[i]); }
	REP(i, q) {
		if(!t[i])
			lct.add_line(c[i], d[i]);
		else
			print(lct.get_min(c[i]));
	}
}