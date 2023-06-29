template<typename T, typename M>
T multiply(const T& x, const T& y, const M& md) {
	if (y == 0) {
		return 0;
	}
	T ret = multiply(x, y / 2, md);
	if (y & 1) {
		return ((ret + ret) % md + x % md) % md;
	} else {
		return (ret + ret) % md;
	}
}