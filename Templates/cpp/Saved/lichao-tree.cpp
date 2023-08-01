struct Line {
	long long a, b;
	Line(long long a = 0, long long b = INF) : a(a), b(b) {}
	long long get(long long x) {
		return a * x + b;
	}
};

struct LiChao {
	struct Node {
		Line line;
		int ch[2] = {0, 0};
	};

	vector<Node> T;
	LiChao(int n) : T(n + 1) {}

	void Insert(int root, Line x) {
		int n = root;
		int tl = -MAX, tr = MAX;
		while (tl <= tr) {
			int md = (tl + tr) >> 1;
			if (T[n].line.get(tl) > x.get(tl)) {
				swap(T[n].line, x);
			}
			if (T[n].line.get(tr) <= x.get(tr)) {
				return;
			}
			if (T[n].line.get(md) <= x.get(md)) {
				tl = md + 1;
				if (!T[n].ch[1]) {
					T[n].ch[1] = T.size();
					T.emplace_back();
				}
				n = T[n].ch[1];
			} else {
				swap(T[n].line, x);
				tr = md;
				if (!T[n].ch[0]) {
					T[n].ch[0] = T.size();
					T.emplace_back();
				}
				n = T[n].ch[0];
			}
		}
	}

	long long Query(int root, long long x) {
		long long res = INF;	 // -INF for maximum
		int n = root;
		int tl = -MAX, tr = MAX;
		while (tl <= tr) {
			if (!n) break;
			int md = (tl + tr) >> 1;
			res = min(res, T[n].line.get(x));  // max() for maximum
			if (x <= md) {
				tr = md;
				n = T[n].ch[0];
			} else {
				tl = md + 1;
				n = T[n].ch[1];
			}
		}
		return res;
	}
};