void Mo() {
	sort(queries + 1, queries + tt + 1);
	int l = queries[1].l, r = queries[1].r;
	for (int i = l; i <= r; ++i) {
		Add(a[i]);
	}
	ans[queries[1].id] = Ans();
	for (int i = 2; i <= tt; ++i) {
		while (r < queries[i].r) {
			Add(a[++r]);
		}
		while (r > queries[i].r) {
			Remove(a[r--]);
		}
		while (l > queries[i].l) {
			Add(a[--l]);
		}
		while (l < queries[i].l) {
			Remove(a[l++]);
		}
		ans[queries[i].id] = Ans();
	}
	for (int i = 1; i <= tt; ++i) {
		cout << ans[i] << '\n';
	}
}