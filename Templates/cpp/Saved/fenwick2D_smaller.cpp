int n;
long long tree[N][N][4];

template <typename T>
void update(int x, int y, T w) {
	for (int i = x; i <= n; i += i & (-i)) {
		for (int j = y; j <= m; j += j & (-j)) {
			tree[i][j][0] += w;
			tree[i][j][1] += 1LL * x * w;
			tree[i][j][2] += 1LL * y * w;
			tree[i][j][3] += 1LL * x * y * w;
		}
	}
}

template <typename T>
void update(int x, int y, int u, int v, T w) {
	update(x, y, w);
	update(x, v + 1, -w);
	update(u + 1, y, -w);
	update(u + 1, v + 1, w);
}

long long query(int x, int y) {
	long long ans = 0;
	for (int i = x; i > 0; i -= i & (-i)) {
		for (int j = y; j > 0; j -= j & (-j)) {
			ans += (x + 1) * (y + 1) * tree[i][j][0] - (y + 1) * tree[i][j][1] - (x + 1) * tree[i][j][2] + tree[i][j][3];
		}
	}
	return ans;
}

long long query(int x, int y, int u, int v) {
	return query(u, v) - query(x - 1, v) - query(u, y - 1) + query(x - 1, y - 1);
}