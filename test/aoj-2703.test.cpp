#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2703"

#include "data_structure/dice.hpp"
#include "template.hpp"

//Grid Template
int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
bool inside(const int x, const int y, const int h, const int w) { return x >= 0 and x < h and y >= 0 and y < w; }

void main_() {
	while(true) {
		INT(n);
		if(!n) break;

		V<map<pii, int>> dice_data(n);
		REP(i, n) {
			INT(x, y, l, r, f, b, d, u);
			dice dice(r, l, u, d, b, f);
			dice_data[i][{x, y}] = dice.d;
			STR(s);
			foa(c, s) {
				int dir = c == 'R' ? 0 : c == 'B' ? 1 : c == 'L' ? 2 : 3;
				x += dx[dir], y += dy[dir];
				dice.rotate(dir);
				dice_data[i][{x, y}] = dice.d;
			}
		}

		map<pii, V<>> cnt;
		REP(i, n) {
			for(const auto &[p, val] : dice_data[i]) cnt[p].pb(i);
		}

		VV<pair<int, pii>> masks(n);
		for(const auto &[p, vec] : cnt) {
			int bit = 0;
			foa(v, vec) bit |= 1 << v;
			foa(v, vec) masks[v].pb({bit, p});
		}

		vector<int> dp(1 << n);
		REP(b, 1 << n) {
			REP(i, n) {
				if(b >> i & 1) continue;
				int nx = b | 1 << i;
				int sum = dp[b];
				for(const auto &[mask, p] : masks[i])
					if((nx & mask) == mask)
						sum += dice_data[i][p];
				chmax(dp[nx], sum);
			}
		}
		print(dp.back());
	}
}