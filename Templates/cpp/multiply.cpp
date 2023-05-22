template<typename T, typename M>
T multiply(const T& x, const T& y, const M& md) {
	if (y == 0) {
		return 1;
	}
	T ret = multiply(x, y / 2, md);
	ret = (1LL * ret * ret) % md;
	if (y % 2) {
		ret = (1LL * ret * x) % md;
	}
	return ret;
}