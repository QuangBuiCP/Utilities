/**
 *    My implementation for integer modular arithmetic
 *    Bases on: https://github.com/quangloc99
 *    Status: N/A
**/
#define defop(type, op) \
	friend inline type operator op(type u, const type& v) { return u op ##= v; } \
	type& operator op ##= (const type& o)

template<class T>
T power(T base, int64_t exp) {
	T ret = 1;
	for ( ; exp > 0; exp /= 2, base *= base) {
		if (exp & 1) {
			ret *= base;
		}
	}
	return ret;
}

#define int int64_t

template<int MOD>
struct modint {
	int x;

	modint(int x_ = 0LL) : x(x_ % MOD) {
		if (x < 0) {
			x += MOD;
		}
	}

	defop(modint, +) {
		if ((x += o.x) >= MOD) {
			x -= MOD;
		}
		return *this;
	}

	defop(modint, -) {
		if ((x -= o.x) < 0) {
			x += MOD;
		}
		return *this;
	}

	defop(modint, *) {
		return *this = modint(1LL * x * o.x);
	}

	defop(modint, /) {
		return *this *= power(o, MOD - 2);
	}
};

#undef int

using mint = modint<(int) 1e9 + 7>;

/*
vector<mint> fact(1, 1);
vector<mint> inv_fact(1, 1);
 
mint C(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}
	while ((int) fact.size() < n + 1) {
		fact.push_back(fact.back() * (int) fact.size());
		inv_fact.push_back(1 / fact.back());
	}
	return fact[n] * inv_fact[k] * inv_fact[n - k];
}
*/