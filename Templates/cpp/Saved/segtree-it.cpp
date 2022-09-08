template <typename T, class F = std::function<T(const T&, const T&)>>
struct SegmentTree {
	std::vector<T> tree;
	T unit;
	int N;
	F func;

	SegmentTree(std::vector<int> a, T def, F f) : tree(2 * int(a.size()) + 1, def), unit(def), N(int(a.size())), func(f) { build(a); }
	SegmentTree(int n, T def, F f) : tree(2 * n + 1, def), unit(def), N(n), func(f) {}

	void update(int p, T val) {
		for (tree[p += N] = val; p /= 2; ) {
			tree[p] = func(tree[p * 2], tree[p * 2 + 1]);
		}
	}

	T query(int l, int r) {
		T ra = unit, rb = unit;
		for (l += N, r += N; l < r; r /= 2, l /= 2) {
			if (l % 2) ra = func(ra, tree[l++]);
			if (r % 2) rb = func(rb, tree[--r]);
		}
		return func(ra, rb);
	}

	void build(const std::vector<int>& a) {
		int n = int(a.size());
		assert(N == n);
		/*
		for (int i = 0; i < n; ++i) {
			update(i, a[i]);
		}
		*/
		for (int i = 0; i < n; ++i) {
			tree[i + n] = a[i];
		}
		for (int i = n - 1; i >= 0; --i) {
			tree[i] = func(tree[2 * i], tree[2 * i + 1]);
		}
	}
};