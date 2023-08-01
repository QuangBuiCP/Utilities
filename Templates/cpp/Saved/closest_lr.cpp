// For every i, finds the largest j < i such that `compare(values[j], values[i])` is true, or -1 if no such j exists.
template <typename T, typename T_compare>
vector<int> closest_left(const vector<T> &values, T_compare &&compare) {
	int n = int(values.size());
	vector<int> closest(n);
	vector<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && !compare(values[st.back()], values[i]))
			st.pop_back();
		closest[i] = st.empty() ? -1 : st.back();
		st.push_back(i);
	}
	return closest;
}

// For every i, finds the smallest j > i such that `compare(values[j], values[i])` is true, or `n` if no such j exists.
template <typename T, typename T_compare>
vector<int> closest_right(const vector<T> &values, T_compare &&compare) {
	int n = int(values.size());
	vector<int> closest(n);
	vector<int> st;
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && !compare(values[st.back()], values[i]))
			st.pop_back();
		closest[i] = st.empty() ? n : st.back();
		st.push_back(i);
	}
	return closest;
}