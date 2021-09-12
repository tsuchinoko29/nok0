#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397&lang=jp"

#include "cftemp.hpp"
#include "math/matrix.hpp"
#include "math/modint"

using mint = atcoder::static_modint<1000000009>;
mint res;
int c = 1;
void main_() {
	while(true) {
		INT(w);
		LL(h);
		INT(n);
		if(w == 0) return;
		matrix<mint> dp(1, w);
		dp[0][0] = 1;
		matrix<mint> mul(w, w);
		REP(i, w) {
			REP(j, max(i - 1, 0), min(i + 2, w)) {
				mul[i][j] = 1;
			}
		}
		map<ll, V<>> mp;
		REP(i, n) {
			LL(x, y);
			--x, --y;
			if(!y) continue;
			mp[y].pb(x);
		}
		mp[h - 1].pb(w);
		ll bef = 0;
		for(auto [val, vec] : mp) {
			dp *= mul ^ (val - bef);
			foa(v, vec) {
				if(v < w)
					dp[0][v] = 0;
				else {
					cout << "Case " << c++ << ": ";
					print(dp[0].back().val());
				}
			}
			bef = val;
		}
	}
}
