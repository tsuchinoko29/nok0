#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "data_structure/w_ary_tree.hpp"
#include "template.hpp"

constexpr int sz = 10000000;
void main_() {
	w_ary_tree<sz> st;
	INT(n, q);
	STR(s);
	REP(i, n) {
		if(s[i] == '1') st.insert(i);
	}
	while(q--) {
		INT(t, x);
		int d;
		switch(t) {
			case 0:
				st.insert(x);
				break;
			case 1:
				st.erase(x);
				break;
			case 2:
				print(st.contains(x));
				break;
			case 3:
				if(st.contains(x)) {
					print(x);
					break;
				}
				d = st.next(x);
				print(d < sz ? d : -1);
				break;
			case 4:
				if(st.contains(x)) {
					print(x);
					break;
				}
				d = st.prev(x);
				print(d < sz ? d : -1);
				break;
			default:
				break;
		}
	}
}