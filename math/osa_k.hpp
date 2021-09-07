#include <vector>

struct osa_k {
private:
	std::vector<int> spf, pr;

public:
	osa_k() = default;

	osa_k(int MAX) : spf(MAX + 1) {
		for(int i = 2; i <= MAX; i++) {
			if(spf[i] == 0) {
				spf[i] = i;
				pr.push_back(i);
			}
			for(int j = 0; j < pr.size() and pr[j] <= spf[i] and i * pr[j] <= MAX; j++)
				spf[i * pr[j]] = pr[j];
		}
	}

	std::vector<std::pair<int, int>> PF(int n) {
		std::vector<std::pair<int, int>> divisor;
		if(n == 1) return divisor;
		int before = spf[n], cnt = 0;
		while(n > 1) {
			if(spf[n] == before) {
				cnt++;
				n /= spf[n];
			} else {
				divisor.emplace_back(before, cnt);
				before = spf[n];
				cnt = 1;
				n /= spf[n];
			}
		}
		divisor.emplace_back(before, cnt);
		return divisor;
	}

	int smallestprimefactor(const int n) const {
		return spf[n];
	}

	bool isPrime(const int n) const {
		return n == spf[n];
	}
};
