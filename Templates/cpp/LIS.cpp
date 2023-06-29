int LIS(const vector<int>& ar, bool equal) {
	int n = (int) ar.size();
	vector<int> f(n + 1, INF);
	f[0] = -INF;
	for (int i = 0; i < n; ++i) {
		int id;
		if (equal) // a[i] <= a[j]
			id = (int) (upper_bound(f.begin(), f.end(), ar[i]) - f.begin());
		else // a[i] < a[j]
			id = (int) (lower_bound(f.begin(), f.end(), ar[i]) - f.begin());
		if (f[id - 1] <= ar[i] && ar[i] <= f[id]) {
			f[id] = ar[i];
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		if (f[i] < INF)
			ans = i;
	}
	return ans;
}