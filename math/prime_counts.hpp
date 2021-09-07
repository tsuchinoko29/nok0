#include <cmath>
#include <vector>

long long prime_pi(const long long n) {
	if(n <= 2) return n == 2;
	const int v = floor(std::sqrt((long double)n));
	int s = v + 1 >> 1;
	std::vector<int> smalls(s), roughs(s);
	std::vector<long long> larges(s);
	for(int i = 1; i < s; ++i) smalls[i] = i;
	for(int i = 0; i < s; ++i) roughs[i] = 2 * i + 1;
	for(int i = 0; i < s; ++i) larges[i] = (n / (2 * i + 1) - 1) / 2;
}