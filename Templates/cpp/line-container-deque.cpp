struct Line {
  long long a, b;

  Line(long long _a = 0, long long _b = 0) {
    a = _a, b = _b;
  }

  long long val(long long x) {
    return a * x + b;
  }

  long double insect(line c) {
    return (long double) (b - c.b) / (c.a - a);
  }
};

struct LineContainer {
  deque<Line> q;
  // vector<Line> q;
  int j = 0;

  void add(Line c) {
    if (!q.empty()) {
      assert(c.a >= q.back().a);
    }
    if (!q.empty() && c.a == q.back().a) {
      if (c.b >= q.back().b) {
        q.pop_back();
      }
      else return;
    }
    while ((int)q.size() > 1 && c.insect(q.back()) <= q.back().insect(q[(int)q.size() - 2])) {
      q.pop_back();
    }
    q.push_back(c);
  }

  // get max a*x+b
  long long get(long long x) {
    while ((int)q.size() > 1 && q.front().val(x) <= q[1].val(x)) {
      q.pop_front();
    }
    assert(!q.empty());
    return q.front().val(x);
    // while ((int)q.size() - j > 1 && q[j].val(x) <= q[j + 1].val(x)) {
      // j++;
    // }
    // assert(!q.empty());
    // return q[j].val(x);
  }
};