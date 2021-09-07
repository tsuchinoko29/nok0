#pragma once
#include <stack>
#include <vector>

struct rollback_unionfind {
private:
	std::vector<int> par;
	std::stack<std::pair<int, int>> history;

public:
	rollback_unionfind() = default;

	rollback_unionfind(size_t n) : par(n, -1) {}

	int root(int x) {
		if(par[x] < 0) return x;
		return root(par[x]);
	}

	bool same(int x, int y) { return root(x) == root(y); }

	bool unite(int x, int y) {
		x = root(x), y = root(y);
		history.emplace(x, par[x]);
		history.emplace(y, par[y]);
		if(x == y) return false;
		if(par[x] > par[y]) std::swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	void snapshot() {
		while(!history.empty()) history.pop();
	}

	void undo() {
		for(int i = 0; i < 2; i++) {
			par[history.top().first] = history.top().second;
			history.pop();
		}
	}

	void rollback() {
		while(!history.empty()) undo();
	}

	size_t size(int x) { return -par[root(x)]; }
};
