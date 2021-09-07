#include "data_structure/offline_dynamic_connectivity.hpp"
#include "template.hpp"

void main_() {
	INT(n, q);
	offline_dynamic_connectivity odc(n, q);

	vector<pii> uv(q, {-1, -1});

	int t3 = 0;
	vector<int> id(q, -1);

	REP(i, q) {
		int type, u, v;
		cin >> type >> u >> v;
		switch(type) {
			case 1:
				odc.link(i, u, v);
				break;

			case 2:
				odc.cut(i, u, v);
				break;

			case 3:
				id[i] = t3++;
				uv[i] = {u, v};
				break;

			default:
				break;
		}
	}

	vector<int> res(t3);

	auto f = [&](int t) {
		if(id[t] != -1) {
			const auto &[u, v] = uv[t];
			res[id[t]] = odc.uf.same(u, v);
		}
	};

	odc.build();
	odc.run(f);

	for(const auto &v : res) cout << (v ? "YES\n" : "NO\n");
}