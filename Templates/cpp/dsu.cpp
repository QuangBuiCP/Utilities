struct DSU {
	int n;
	vector<int> sz;
	vector<int> par;

	DSU(int _n = 0) : n(_n) {
		sz.assign(n, 1);
		par.resize(n);
		iota(par.begin(), par.end(), 0);
	}

	int get_par(int x) {
		while (x != par[x]) {
			x = par[x] = par[par[x]];
		}
		return x;
	}

	bool unite(int x, int y) {
		x = get_par(x);
		y = get_par(y);
		if (x == y) {
			return false;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		sz[x] += sz[y];
		par[y] = x;
		return true;
	}
};