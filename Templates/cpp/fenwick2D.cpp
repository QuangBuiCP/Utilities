template <typename T>
struct FenwickTree2D {
	int n;
	bool compressed;
	vector<vector<int>> node;
	vector<vector<T>> tree;

	FenwickTree2D(int _n = 0) : n(_n), compressed(false) {
		tree.assign(n + 2, vector<T>());
		node.resize(n + 1);
	}

	// Fake query (must use)

	void fake_get(int x, int y) {
		compressed = false;
		while (x > 0) {
			node[x].push_back(y);
			x -= x & -x;
		}
	}

	void fake_update(int x, int y) {
		compressed = false;
		while (x <= n) {
			node[x].push_back(y);
			x += x & -x;
		}
	}

	// Compress the id (must use before using real query function)
	void compress() {
		compressed = true;
		for (int i = 0; i <= n; ++i) {
			sort(node[i].begin(), node[i].end());
			node[i].erase(unique(node[i].begin(), node[i].end()), node[i].end());
			tree[i].resize((int) node[i].size() + 2);
		}
	}

	int get_id(int x, int y) {
		return (int) (lower_bound(node[x].begin(), node[x].end(), y) - node[x].begin());
	}

	// Real query

	T get(int x, int y) {
		assert(compressed == true);
		T ret = T();
		while (x > 0) {
			for (int i = get_id(x, y) + 1; i > 0; i -= i & -i) {
				ret += tree[x][i];
			}
			x -= x & -x;
		}
		return ret;
	}

	void update(int x, int y, T val) {
		assert(compressed == true);
		while (x <= n) {
			for (int i = get_id(x, y) + 1; i <= (int) node[x].size(); i += i & -i) {
				tree[x][i] += val;
			}
			x += x & -x;
		}
	}

	// Custom function:

	T get(int l, int r, int x) {
		if (l > r) return T();
		return get(r, x - 1) - get(l - 1, x - 1);
	}

	T get_suff(int l, int r, int x) {
		if (l > r) return T();
		return (r - get(r, x)) - ((l - 1) - get(l - 1, x));
	}

	void fake_get(int l, int r, int x) {
		fake_get(r, x - 1);
		fake_get(l - 1, x - 1);
	}

	void fake_get2(int l, int r, int x) {
		fake_get(r, x);
		fake_get(l - 1, x);
	}
};