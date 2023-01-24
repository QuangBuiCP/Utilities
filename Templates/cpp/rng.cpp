mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rando(long long l, long long r) {
	return uniform_int_distribution<long long>(l, r)(rng);
}