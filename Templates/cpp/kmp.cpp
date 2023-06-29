vector<int> prefunc(const string &s) {
	int n = (int) s.size();
	vector<int> pf(n);
	for (int i = 1; i < n; ++i) {
		int j = pf[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = pf[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		pf[i] = j;
	}
	return pf;
}