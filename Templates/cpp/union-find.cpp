struct union_find {
	// When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
	vector<int> data;
	int components = 0;

	union_find(int n = -1) {
		if (n >= 0)
			init(n);
	}

	void init(int n) {
		data.assign(n + 1, -1);
		components = n;
	}

	int find(int x) {
		return data[x] < 0 ? x : data[x] = find(data[x]);
	}

	int get_size(int x) {
		return -data[find(x)];
	}

	bool unite(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y)
			return false;

		if (-data[x] < -data[y])
			swap(x, y);

		data[x] += data[y];
		data[y] = x;
		components--;
		return true;
	}
};