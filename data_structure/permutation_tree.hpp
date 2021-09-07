#include <atcoder/lazysegtree>
#include <iostream>
#include <stack>
#include <vector>

namespace monoid {
using S = int;
S op(S x, S y) { return std::min(x, y); }
S e() { return 1 << 30; }
using F = int;
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
}  // namespace monoid

struct permutation_tree {
public:
	int sz;
	std::vector<int> parent, typ;
	std::vector<std::vector<int>> children;
	std::vector<std::pair<int, int>> range, span;
	permutation_tree(const std::vector<int> &vec) : vec(vec) { build(); }

private:
	std::vector<int> vec;
	std::stack<int> max_stack, min_stack, nodes;

	using segtree = atcoder::lazy_segtree<monoid::S,
	                                      monoid::op,
	                                      monoid::e,
	                                      monoid::F,
	                                      monoid::mapping,
	                                      monoid::composition,
	                                      monoid::id>;

	segtree seg;

	std::pair<int, int> get_range(std::pair<int, int> x, std::pair<int, int> y) const {
		return std::pair(std::min(x.first, y.first), std::max(x.second, y.second));
	}

	bool adj(int i, int j) const { return range[i].second == range[j].first; }

	int length(int i) const { return range[i].second - range[i].first; }

	void add_edge(int p, int c) {
		parent[c] = p;
		children[p].emplace_back(c);
	}

	void build() {
		max_stack = min_stack = nodes = {};
		max_stack.push(-1);
		min_stack.push(-1);
		int n = vec.size();
		sz = n;
		parent.assign(n * 2, -1);
		children.assign(n * 2, {});
		range.resize(n * 2);
		span.resize(n * 2);
		typ.assign(n * 2, 0);
		seg = segtree(std::vector(n * 2, 0));

		for(int i = 0; i < n; i++) {
			while(max_stack.top() != -1 and vec[max_stack.top()] < vec[i]) {
				const int tmp = max_stack.top();
				max_stack.pop();
				seg.apply(max_stack.top() + 1, tmp + 1, vec[i] - vec[tmp]);
			}
			max_stack.push(i);

			while(min_stack.top() != -1 and vec[min_stack.top()] > vec[i]) {
				const int tmp = min_stack.top();
				min_stack.pop();
				seg.apply(min_stack.top() + 1, tmp + 1, vec[tmp] - vec[i]);
			}
			min_stack.push(i);

			range[i] = std::pair(vec[i], vec[i] + 1);
			span[i] = std::pair(i, i + 1);

			int cur = i;

			while(true) {
				if(!nodes.empty() and (adj(nodes.top(), cur) or adj(cur, nodes.top()))) {
					if(adj(nodes.top(), cur) and typ[nodes.top()] == 2 or adj(cur, nodes.top()) and typ[nodes.top()] == 1) {
						add_edge(nodes.top(), cur);
						range[nodes.top()] = get_range(range[nodes.top()], range[cur]);
						span[nodes.top()] = get_range(span[nodes.top()], span[cur]);
						cur = nodes.top();
						nodes.pop();
					} else {
						add_edge(sz, nodes.top());
						add_edge(sz, cur);
						typ[sz] = adj(nodes.top(), cur) ? 2 : 1;
						range[sz] = get_range(range[nodes.top()], range[cur]);
						span[sz] = get_range(span[nodes.top()], span[cur]);
						cur = sz++;
						nodes.pop();
					}
				} else if(i + 1 - length(cur) and seg.prod(0, i + 1 - length(cur)) == 0) {
					int len = length(cur);
					std::pair<int, int> rng = range[cur];
					std::pair<int, int> sp = span[cur];
					add_edge(sz, cur);
					do {
						len += length(nodes.top());
						rng = get_range(rng, range[nodes.top()]);
						sp = get_range(sp, span[nodes.top()]);
						add_edge(sz, nodes.top());
						nodes.pop();
					} while(rng.second - rng.first != len);
					std::reverse(children[sz].begin(), children[sz].end());
					range[sz] = rng;
					span[sz] = sp;
					cur = sz++;
				} else
					break;
			}
			nodes.push(cur);
			seg.apply(0, i + 1, -1);
		}
		shrink();
	}

	void shrink() {
		parent.resize(sz);
		children.resize(sz);
		range.resize(sz);
		span.resize(sz);
		typ.resize(sz);
	}
};
