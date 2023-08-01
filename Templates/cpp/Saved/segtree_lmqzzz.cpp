// I will need to understand this somehow...
class segtree_t {
   public:
	segtree_t *left, *right;
	int l, r, m;
	int64_t val, lazy;

	segtree_t(int l, int r) : l(l), r(r), m(l + r >> 1), val(0), lazy(0) {
		if (l == r) return;
		left = new segtree_t(l, m);
		right = new segtree_t(m + 1, r);
	}

	void Update(int s, int t, int64_t x) {
		if (r < s or l > t) return;
		if (s <= l && r <= t) {
			val += 1ll * x * (r - l + 1);
			lazy += x;
			return;
		}
		Down();
		left->Update(s, t, x);
		right->Update(s, t, x);
		Up();
	}

	int64_t Get(int s, int t) {
		if (r < s or l > t) return 0;
		if (s <= l && r <= t) return val;
		Down();
		return left->Get(s, t) + right->Get(s, t);
	}

	void Up() {
		val = left->val + right->val;
	}

	void Down() {
		left->lazy += lazy;
		right->lazy += lazy;
		right->val += lazy * (r - m);
		left->val += lazy * (m - l + 1);
		lazy = 0;
	}
};