#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "data_structure/binary_trie.hpp"
#include "template.hpp"

void main_() {
	INT(n, q);
	STR(s);
	binary_trie<int, 24, false> trie;
	REP(i, n) {
		if(s[i] == '1') trie.insert(i);
	}
	while(q--) {
		INT(t, x);
		int d;
		switch(t) {
			case 0:
				trie.insert(x);
				break;
			case 1:
				trie.erase(x);
				break;
			case 2:
				print(trie.count(x));
				break;
			case 3:
				d = trie.lower_bound(x);
				print(d >= 0 and d < trie.size() ? trie[d] : -1);
				break;
			case 4:
				d = trie.upper_bound(x) - 1;
				print(d >= 0 and d < trie.size() ? trie[d] : -1);
				break;
			default:
				break;
		}
	}
}