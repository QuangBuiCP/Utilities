long long binmul(long long a, long long b, long long c) {
	long long ret = 0;
	a %= c;
	while (b > 0) {
		if (b % 2) {
			ans = (ans + a) % c;
		}
		a = (a * 2) % c;
		b /= 2;
	}
	return ret;
}

long long binpow(long long a, long long b, long long c) {
	long long ret = 1;
	a %= c;
	while (b > 0) {
		if (b % 2) {
			ans = binmul(ans, a, c);
		}
		a = binmul(a, a, c);
		b /= 2;
	}
	return ret;
}