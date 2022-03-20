template <typename T, class F = function<T(const T&, const T&)>>
struct SegmentTree {
  vector<T> seg;
  T unit;
  int N;
  F func;

  SegmentTree(vector<int> a, T def, F f) : seg(2 * int(a.size()) + 1, def), unit(def), N(int(a.size())), func(f) { build(a); }
  SegmentTree(int n, T def, F f) : seg(2 * n + 1, def), unit(def), N(n), func(f) {}

  void update(int p, T val) {
    for (seg[p += N] = val; p /= 2; ) {
      seg[p] = func(seg[p * 2], seg[p * 2 + 1]);
    }
  }

  T query(int l, int r) {
    T ra = unit, rb = unit;
    for (l += N, r += N; l < r; r /= 2, l /= 2) {
      if (l % 2) ra = func(ra, seg[l++]);
      if (r % 2) rb = func(rb, seg[--r]);
    }
    return func(ra, rb);
  }

  void build(vector<int> a) {
    int n = int(a.size());
    assert(N == n);
    /*
    for (int i = 0; i < n; ++i) {
      update(i, a[i]);
    }
    */
    for (int i = 0; i < n; ++i) {
      seg[i + n] = a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
      seg[i] = func(seg[2 * i], seg[2 * i + 1]);
    }
  }
};