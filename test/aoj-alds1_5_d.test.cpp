#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D"

#include "math/inversion.hpp"
#include "template.hpp"

void main_() {
	INT(n);
	VEC(int, a, n);
	press(a);
	print(inversion(a));
}