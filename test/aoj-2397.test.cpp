#line 1 "aoj-2397.test.cpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397&lang=jp"

#include <atcoder/modint>

#line 1 "/Users/nok0/Documents/Programming/nok0/cftemp.hpp"
#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
// rep macro
#define foa(v, a) for(auto &v : a)
#define REPname(a, b, c, d, e, ...) e
#define REP(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define REP0(x) for(int i = 0; i < (x); ++i)
#define REP1(i, x) for(int i = 0; i < (x); ++i)
#define REP2(i, l, r) for(int i = (l); i < (r); ++i)
#define REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))
#define REPSname(a, b, c, ...) c
#define REPS(...) REPSname(__VA_ARGS__, REPS1, REPS0)(__VA_ARGS__)
#define REPS0(x) for(int i = 1; i <= (x); ++i)
#define REPS1(i, x) for(int i = 1; i <= (x); ++i)
#define RREPname(a, b, c, d, e, ...) e
#define RREP(...) RREPname(__VA_ARGS__, RREP3, RREP2, RREP1, RREP0)(__VA_ARGS__)
#define RREP0(x) for(int i = (x)-1; i >= 0; --i)
#define RREP1(i, x) for(int i = (x)-1; i >= 0; --i)
#define RREP2(i, r, l) for(int i = (r)-1; i >= (l); --i)
#define RREP3(i, r, l, c) for(int i = (r)-1; i >= (l); i -= (c))
#define RREPSname(a, b, c, ...) c
#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS__)
#define RREPS0(x) for(int i = (x); i >= 1; --i)
#define RREPS1(i, x) for(int i = (x); i >= 1; --i)

// name macro
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;

// input macro
template <class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
	for(T &i : v) is >> i;
	return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
	std::string s;
	is >> s;
	__int128_t ret = 0;
	for(int i = 0; i < s.length(); i++)
		if('0' <= s[i] and s[i] <= '9')
			ret = 10 * ret + s[i] - '0';
	a = ret * (s[0] == '-' ? -1 : 1);
	return is;
}
namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template <class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template <class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
}  // namespace scanner
#define VEC(type, name, size)     \
	std::vector<type> name(size); \
	scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
	std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
	scanner::INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
	std::string __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)

// output-macro
template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
	for(int i = 0; i < int(a.size()); ++i) {
		if(i) os << " ";
		os << a[i];
	}
	return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
	std::ostream::sentry s(dest);
	if(s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while(tmp != 0);
		if(value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if(dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}
template <class T>
void print(const T a) { std::cout << a << '\n'; }
template <class Head, class... Tail>
void print(Head H, Tail... T) {
	std::cout << H << ' ';
	print(T...);
}
template <class T>
void printel(const T a) { std::cout << a << '\n'; }
template <class T>
void printel(const std::vector<T> &a) {
	for(const auto &v : a)
		std::cout << v << '\n';
}
template <class Head, class... Tail>
void printel(Head H, Tail... T) {
	std::cout << H << '\n';
	printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
void err(const bool b = true) {
	if(b) {
		std::cout << "-1\n", exit(0);
	}
}

//debug macro
namespace debugger {
template <class T>
void view(const std::vector<T> &a) {
	std::cerr << "{ ";
	for(const auto &v : a) {
		std::cerr << v << ", ";
	}
	std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
	std::cerr << "{\n";
	for(const auto &v : a) {
		std::cerr << "\t";
		view(v);
		std::cerr << "\n";
	}
	std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
	std::cerr << "{\n";
	for(const auto &p : a) std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &p : m) std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::pair<T, U> &p) { std::cerr << "(" << p.first << ", " << p.second << ")"; }
template <class T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &v : s) {
		view(v);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <class T>
void view(const T &e) { std::cerr << e; }
}  // namespace debugger
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	debugger::view(H);
	std::cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                                \
	do {                                                          \
		std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(false)
#else
#define debug(...) (void(0))
#endif

// vector macro
template <class T>
int lb(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x))); }
template <class T>
int ub(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x))); }
template <class T>
void UNIQUE(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<T> press(std::vector<T> &a) {
	auto res = a;
	UNIQUE(res);
	for(auto &v : a)
		v = lb(res, v);
	return res;
}
#define SORTname(a, b, c, ...) c
#define SORT(...) SORTname(__VA_ARGS__, SORT1, SORT0, ...)(__VA_ARGS__)
#define SORT0(a) std::sort((a).begin(), (a).end())
#define SORT1(a, c) std::sort((a).begin(), (a).end(), [](const auto x, const auto y) { return x c y; })
template <class T>
void ADD(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v += x;
}
template <class T>
void SUB(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v -= x;
}
template <class T>
void MUL(std::vector<T> &a, const T x) {
	for(auto &v : a) v *= x;
}
template <class T>
void DIV(std::vector<T> &a, const T x) {
	for(auto &v : a) v /= x;
}
std::vector<std::pair<char, int>> rle(const string &s) {
	int n = s.size();
	std::vector<std::pair<char, int>> ret;
	for(int l = 0; l < n;) {
		int r = l + 1;
		for(; r < n and s[l] == s[r]; r++) {}
		ret.emplace_back(s[l], r - l);
		l = r;
	}
	return ret;
}
template <class T>
std::vector<std::pair<T, int>> rle(const std::vector<T> &v) {
	int n = v.size();
	std::vector<std::pair<T, int>> ret;
	for(int l = 0; l < n;) {
		int r = l + 1;
		for(; r < n and v[l] == v[r]; r++) {}
		ret.emplace_back(v[l], r - l);
		l = r;
	}
	return ret;
}

// math macro
template <class T, class U>
inline bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <class T, class U>
inline bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <class T>
T divup(T x, T y) { return (x + y - 1) / y; }
template <class T>
T POW(T a, long long n) {
	T ret = 1;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}
// modpow
long long POW(long long a, long long n, const int mod) {
	long long ret = 1;
	a = (a % mod + mod) % mod;
	while(n) {
		if(n & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ret;
}

// others
struct fast_io {
	fast_io() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} fast_io_;
const int inf = 1e9;
const ll INF = 1e18;
#pragma endregion

void main_();

int main() {
	main_();
	return 0;
}
#line 5 "/Users/nok0/Documents/Programming/nok0/math/matrix.hpp"

template <class T>
struct matrix {
private:
	std::vector<std::vector<T>> A;

	static matrix I(size_t n) {
		matrix mat(n);
		for(int i = 0; i < n; i++) mat[i][i] = 1;
		return mat;
	}

public:
	matrix() = default;

	matrix(std::vector<std::vector<T>> &vvec) { A = vvec; }

	matrix(size_t n, size_t m) : A(n, std::vector<T>(m, 0)) {}

	matrix(size_t n, size_t m, T init) : A(n, std::vector<T>(m, init)) {}

	matrix(size_t n, std::vector<T> &vec) : A(n, vec) {}

	matrix(size_t n) : A(n, std::vector<T>(n, 0)) {}

	size_t height() const { return A.size(); }

	size_t width() const { return A[0].size(); }

	inline const std::vector<T> &operator[](int k) const {
		return A[k];
	}

	inline std::vector<T> &operator[](int k) {
		return A[k];
	}

	matrix &operator+=(const matrix &B) {
		size_t n = height(), m = width();
		assert(n == B.height() and m == B.width());
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] += B[i][j];
		return *this;
	}

	matrix &operator-=(const matrix &B) {
		size_t n = height(), m = width();
		assert(n == B.height() and m == B.width());
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] -= B[i][j];
		return *this;
	}

	matrix &operator*=(const matrix &B) {
		size_t n = height(), m = B.width(), p = width();
		assert(p == B.height());
		std::vector<std::vector<T>> C(n, std::vector<T>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				for(int k = 0; k < p; k++)
					C[i][j] += (*this)[i][k] * B[k][j];
		A.swap(C);
		return *this;
	}

	matrix &operator^=(long long k) {
		matrix B = matrix::I(height());
		while(k > 0) {
			if(k & 1) B *= (*this);
			*this *= *this;
			k >>= 1ll;
		}
		A.swap(B.A);
		return *this;
	}

	bool operator==(const matrix &B) {
		size_t n = height(), m = width();
		if(n != B.height() or m != B.width()) return false;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if((*this)[i][j] != B[i][j]) return false;
		return true;
	}

	matrix operator+(const matrix &B) const {
		return (matrix(*this) += B);
	}

	matrix operator-(const matrix &B) const {
		return (matrix(*this) -= B);
	}

	matrix operator*(const matrix &B) const {
		return (matrix(*this) *= B);
	}

	matrix operator^(const long long &k) const {
		return (matrix(*this) ^= k);
	}

	matrix &operator+=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] += t;
		return *this;
	}

	matrix &operator-=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] -= t;
		return *this;
	}

	matrix &operator*=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] *= t;
		return *this;
	}

	matrix &operator/=(const T &t) {
		int n = height(), m = width();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*this)[i][j] /= t;
		return *this;
	}

	matrix operator+(const T &t) const {
		return (matrix(*this) += t);
	}

	matrix operator-(const T &t) const {
		return (matrix(*this) -= t);
	}

	matrix operator*(const T &t) const {
		return (matrix(*this) *= t);
	}

	matrix operator/(const T &t) const {
		return (matrix(*this) /= t);
	}

	friend std::ostream &operator<<(std::ostream &os, matrix &p) {
		size_t n = p.height(), m = p.width();
		for(int i = 0; i < n; i++) {
			os << '[';
			for(int j = 0; j < m; j++)
				os << p[i][j] << (j == m - 1 ? "]\n" : ",");
		}
		return (os);
	}

	T determinant() {
		matrix B(*this);
		size_t n = height(), m = width();
		assert(n == m);
		T ret = 1;
		for(int i = 0; i < n; i++) {
			int idx = -1;
			for(int j = i; j < n; j++)
				if(B[j][i] != 0) idx = j;
			if(idx == -1) return 0;
			if(i != idx) {
				ret *= -1;
				swap(B[i], B[idx]);
			}
			ret *= B[i][i];
			T vv = B[i][i];
			for(int j = 0; j < n; j++) B[i][j] /= vv;
			for(int j = i + 1; j < n; j++) {
				T a = B[j][i];
				for(int k = 0; k < n; k++) {
					B[j][k] -= B[i][k] * a;
				}
			}
		}
		return ret;
	}
};
#line 7 "aoj-2397.test.cpp"

using mint = atcoder::static_modint<1000000009>;
mint res;
int c = 1;
void main_() {
	while(true) {
		INT(w);
		LL(h);
		INT(n);
		if(w == 0) return;
		matrix<mint> dp(1, w);
		dp[0][0] = 1;
		matrix<mint> mul(w, w);
		REP(i, w) {
			REP(j, max(i - 1, 0), min(i + 2, w)) {
				mul[i][j] = 1;
			}
		}
		map<ll, V<>> mp;
		REP(i, n) {
			LL(x, y);
			--x, --y;
			if(!y) continue;
			mp[y].pb(x);
		}
		mp[h - 1].pb(w);
		ll bef = 0;
		for(auto [val, vec] : mp) {
			dp *= mul ^ (val - bef);
			foa(v, vec) {
				if(v < w)
					dp[0][v] = 0;
				else {
					cout << "Case " << c++ << ": ";
					print(dp[0].back().val());
				}
			}
			bef = val;
		}
	}
}
