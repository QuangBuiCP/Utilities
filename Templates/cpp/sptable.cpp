/**
 *  --------------------------------------------------------------------------
 *    Author:          QuangBuiCP
 *    Template:        Sparse Table (Bugged) (0-indexed)
 *    Original author: tourist
 *    Original source: https://github.com/the-tourist/algo/blob/master/data/sparsetable.cpp
 *    Status:          N/A
 *  --------------------------------------------------------------------------
 *    Overall time:   O(n * log(n))
 *    Memory size:    O(n * log(n))
 *
 *    Usage: SparseTable<typename> variable_name(std::vector, idempotent_operation's_lambda_function)
 *  --------------------------------------------------------------------------
 **/
template <typename T, class F = std::function<T(const T&, const T&)>>
class SparseTable {
   private:
	int n;
	std::vector<vector<T>> data;
	std::vector<int> logg;
	F func;

	void pre_calculate_log(const int& max_log) {
		logg.resize(max_log + 1, 0);
		for (int i = 2; i <= max_log; ++i) {
			logg[i] = logg[i >> 1] + 1;
		}
	}

   public:
	SparseTable(const std::vector<T>& a, const F& f) : func(f) {
		n = static_cast<int>(a.size());
		const int max_log = 32 - __builtin_clz(n);
		pre_calculate_log(max_log);
		data.resize(max_log);
		data[0] = a;
		for (int j = 1; j < max_log; j++) {
			data[j].resize(n - (1 << j) + 1);
			for (int i = 0; i <= n - (1 << j); i++) {
				data[j][i] = func(data[j - 1][i], data[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	T get(int from, int to) const {
		assert(0 <= from && from <= to && to <= n - 1);
		const int lg = logg[to - from + 1] - 1;	 // 32 - __builtin_clz(to - from + 1) - 1;
		return func(data[lg][from], data[lg][to - (1 << lg) + 1]);
	}
};