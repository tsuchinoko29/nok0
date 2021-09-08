#include <iostream>

#include "atcoder/modint"
template <int m>
std::istream &std::operator>>(std::istream &is, atcoder::static_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::istream &std::operator>>(std::istream &is, atcoder::dynamic_modint<m> &a) {
	long long v;
	is >> v;
	a = v;
	return is;
}
template <int m>
std::ostream &std::operator<<(std::ostream &os, const atcoder::static_modint<m> &a) { return os << a.val(); }
template <int m>
std::ostream &std::operator<<(std::ostream &os, const atcoder::dynamic_modint<m> &a) { return os << a.val(); }
