// If dp[i] = max(b[j] * a[i] + dp[j])
//   +) add(b[j], dp[j])
//   +) get(a[i])
// If dp[i] = min(b[j] * a[i] + dp[j])
//   +) add(-b[j], -dp[j]) 
//   +) -get(a[i])
struct Line {
	// a*x + b.
	// k = a
	// m = b
	// p = intersect
	mutable long long k, m, p;

	bool operator < (const Line& o) const {
		return k < o.k;
	}

	bool operator < (long long x) const {
		return p < x;
	}
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, my_floor(a, b) = a/b)
	static const long long inf = LLONG_MAX;
	long long my_floor(long long a, long long b) {
		return a / b - ((a ^ b) < 0 && a % b);
	}

	bool isect(iterator x, iterator y) {
		if (y == end()) {
			x->p = inf;
			return 0;
		}
		if (x->k == y->k) {
			x->p = x->m > y->m ? inf : -inf;
		} else {
			x->p = my_floor(y->m - x->m, x->k - y->k);
		}
		return x->p >= y->p;
	}

	void add(long long k, long long m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) {
			z = erase(z);
		}
		if (x != begin() && isect(--x, y)) {
			isect(x, y = erase(y));
		}
		while ((y = x) != begin() && (--x)->p >= y->p) {
			isect(x, erase(y));
		}
	}

	long long query(long long x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};