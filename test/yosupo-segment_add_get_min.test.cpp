#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "data_structure/li_chao_tree.hpp"
#include "template.hpp"

void main_() {
	INT(n, q);
	V<ll> l(n), r(n), a(n), b(n), ql(q), qr(q), type(q), qa(q), qb(q);
	REP(i, n) { cin >> l[i] >> r[i] >> a[i] >> b[i]; }
	REP(i, q) {
		cin >> type[i];
		if(type[i])
			cin >> ql[i];
		else
			cin >> ql[i] >> qr[i] >> qa[i] >> qb[i];
	}
	V<ll> xs;
	REP(i, n) {
		xs.pb(l[i]);
		xs.pb(r[i]);
	}
	REP(i, q) {
		xs.pb(ql[i]);
		if(!type[i]) xs.pb(qr[i]);
	}
	li_chao_tree<ll> lct(xs);
	REP(i, n)
	lct.add_segment(a[i], b[i], l[i], r[i]);
	REP(i, q) {
		if(type[i]) {
			ll res = lct.get_min(ql[i]);
			if(res == lct.INF)
				print("INFINITY");
			else
				print(res);
		} else
			lct.add_segment(qa[i], qb[i], ql[i], qr[i]);
	}
}