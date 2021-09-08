#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "data_structure/binary_trie.hpp"
#include "template.hpp"

void main_() {
	binary_trie<int, 30, false> trie;
	INT(q);
	while(q--) {
		INT(t, x);
		switch(t) {
			case 0:
				trie.insert(x);
				break;

			case 1:
				trie.erase(x);
				break;

			case 2:
				print(trie.xor_min(x));
				break;

			default:
				break;
		}
	}
}