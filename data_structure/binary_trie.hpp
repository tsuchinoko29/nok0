#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>

template <class T, unsigned char BIT_SIZE = 30, bool multi = true>
struct binary_trie {
	using u64 = unsigned long long int;

public:
	binary_trie() : root(new node(0)) {}

	u64 count(const T x) { return count(root, x); }

	void insert(const T x, const u64 k = 1) {
		if(multi == false and count(x)) return;
		insert(root, x, k);
	}

	void erase(const T x, const u64 k = 1) {
		if(!count(x)) return;
		erase(root, x, k);
	}

	u64 lower_bound(const T x) { return lower_bound(root, x); }

	u64 upper_bound(const T x) { return lower_bound(x + 1); }

	void xor_all(const T x) { root->lazy ^= x; }

	T xor_min(const T x) { return xor_min(root, x); }

	T xor_max(const T x) { return xor_min(x ^ MAX) ^ MAX; }

	T operator[](const u64 k) {
		assert(0 <= k and k < size());
		return operator_func(root, k);
	}

	T min_element() { return (*this)[0]; }

	T max_element() { return (*this)[size() - 1]; }

	u64 size() const noexcept { return cnt(root); }

	bool empty() const noexcept { return cnt(root) == 0; }

	void dump() {
		std::cerr << "[";
		if(!size()) std::cerr << ']';
		for(int i = 0; i < size(); i++)
			std::cerr << (*this)[i] << ",]"[i == size() - 1];
		std::cerr << '\n';
	}

private:
	struct node;
	using node_ptr = std::unique_ptr<node>;

	struct node {
		T cnt, lazy;
		node_ptr descend[2];
		node(T cnt) : cnt(cnt), lazy(0), descend{nullptr, nullptr} {}
	};

	node_ptr root;

	const T MAX = (1ull << BIT_SIZE) - 1;

	u64 cnt(const node_ptr &t) const { return t != nullptr ? t->cnt : 0; }

	u64 count(node_ptr &t, const T x, const unsigned char i = BIT_SIZE - 1) {
		eval(t, i);
		const T bit = x >> i & 1;
		if(t->descend[bit] != nullptr)
			return (i ? count(t->descend[bit], x, i - 1) : cnt(t->descend[bit]));
		else
			return 0;
	}

	void eval(node_ptr &t, const unsigned char i = BIT_SIZE - 1) {
		if(t->lazy >> i & 1) std::swap(t->descend[0], t->descend[1]);
		if(t->descend[0]) t->descend[0]->lazy ^= t->lazy;
		if(t->descend[1]) t->descend[1]->lazy ^= t->lazy;
		t->lazy = 0;
	}

	void insert(node_ptr &t, const T x, const u64 k, const unsigned char i = BIT_SIZE - 1) {
		t->cnt += k;
		eval(t, i);
		const T bit = x >> i & 1;
		if(!t->descend[bit]) t->descend[bit] = std::make_unique<node>(0);
		if(i)
			insert(t->descend[bit], x, k, i - 1);
		else
			t->descend[bit]->cnt += k;
	}

	void erase(node_ptr &t, const T x, const u64 k, const unsigned char i = BIT_SIZE - 1) {
		t->cnt -= k;
		eval(t, i);
		const T bit = x >> i & 1;
		if(i)
			erase(t->descend[bit], x, k, i - 1);
		else
			t->descend[bit]->cnt -= k;
	}

	u64 lower_bound(node_ptr &t, const T x, const unsigned char i = BIT_SIZE - 1) {
		u64 ret = 0;
		eval(t, i);
		if(cnt(t) == 0) return ret;
		const T bit = x >> i & 1;
		if(t->descend[bit]) {
			if(bit) ret += cnt(t->descend[0]);
			return ret += (i ? lower_bound(t->descend[bit], x, i - 1) : 0);
		} else
			return bit ? ret + cnt(t->descend[0]) : ret;
	}

	T xor_min(node_ptr &t, const T x, const unsigned char i = BIT_SIZE - 1) {
		eval(t, i);
		const T bit = x >> i & 1;
		if(i == 0)
			return !cnt(t->descend[bit]);
		if(cnt(t->descend[bit]))
			return xor_min(t->descend[bit], x, i - 1);
		else {
			if(t->descend[!bit] == nullptr) t->descend[bit] = std::make_unique<node>(0);
			return xor_min(t->descend[!bit], x, i - 1) + (1ull << i);
		}
	}

	T operator_func(node_ptr &t, u64 k, const unsigned char i = BIT_SIZE - 1) {
		eval(t, i);
		if(i == 0) return k >= cnt(t->descend[0]);
		if(k < cnt(t->descend[0]))
			return operator_func(t->descend[0], k, i - 1);
		else {
			k -= cnt(t->descend[0]);
			return operator_func(t->descend[1], k, i - 1) | (1ULL << i);
		}
	}
};
