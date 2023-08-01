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

// pref_cnt[i] = Number of S[0..(i-1)] appeared in the string S (by using prefunc(S)).
vector<int> prefix_count(const vector<int>& pf) {
	int n = (int) pf.size();
	vector<int> pref_cnt(n + 1, 1);
	for (int i = n; i >= 1; --i) {
		pref_cnt[pf[i - 1]] += pref_cnt[i];
	}
	return pref_cnt;
}