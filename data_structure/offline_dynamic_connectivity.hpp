#pragma once
#include <algorithm>
#include <map>

#include "data_structure/undo_uf.hpp"
struct offline_dynamic_connectivity {
public:
	rollback_unionfind uf;

	offline_dynamic_connectivity(int n, int q) : uf(n), seg(q), q(q) {}

	void link(int t, int u, int v) {
		std::pair e = std::minmax(u, v);
		if(!cnt[e]++) appear[e] = t;
	}

	void cut(int t, int u, int v) {
		std::pair e = std::minmax(u, v);
		if(!(--cnt[e])) seg.set(appear[e], t, e);
	}

	void build() {
		for(const auto &[e, val] : cnt)
			if(val) seg.set(appear[e], q, e);
	}

	template <class F>
	void run(const F &f, int k = 1) {
		for(const auto &[u, v] : seg.node[k])
			uf.unite(u, v);
		if(k < q)
			run(f, k << 1), run(f, k << 1 | 1);
		else
			f(k - q);
		for(int i = 0; i < (int)seg.node[k].size(); i++)
			uf.undo();
	}

private:
	int q;
	using edge = std::pair<int, int>;
	std::map<edge, int> appear, cnt;
	std::vector<std::pair<std::pair<int, int>, edge>> pend;

	struct seg {
	public:
		int n;
		std::vector<std::vector<edge>> node;
		seg(int n_) : n(n_), node(n << 1) {}

		void set(int l, int r, edge e) {
			for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if(l & 1) node[l++].push_back(e);
				if(r & 1) node[--r].push_back(e);
			}
		}
	};

	seg seg;
};
