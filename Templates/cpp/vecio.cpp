template<typename T_vector> void vecin(T_vector &v, int size = -1, int start = -1, int end = -1) {
	if (size < 0) size = int(v.size()); else v.resize(size);
	assert(size > 0);
	if (end < 0) end = size;
	if (start < 0) start = 0;
	assert(end <= size);
	assert(start <= end);
	for (int i = start; i < end; ++i)
		cin >> v[i];
}

template<typename T_vector> void vecout(const T_vector &v, int add_in = 0, int start = -1, int end = -1) {
	if (start < 0) start = 0;
	if (end < 0) end = int(v.size());
	for (int i = start; i < end; ++i)
		cout << v[i] + add_in << " \n"[i == end - 1];
}