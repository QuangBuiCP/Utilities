template<typename type>
struct Matrix {
  vector < vector <type> > data;

  int row() const { return (int) data.size(); } 

  int col() const { return (int) data[0].size(); }

  auto & operator [] (int i) { return data[i]; }

  const auto & operator[] (int i) const { return data[i]; }

  Matrix() = default;

  Matrix(int r, int c): data(r, vector <type> (c)) { }

  Matrix(const vector < vector <type> > &d): data(d) {
    assert(d.size());
    int size = (int) d[0].size();
    assert(size);
    for (auto x : d) assert((int) x.size() == size);
  }

  friend ostream & operator << (ostream &out, const Matrix &d) {
    for (auto x : d.data) {
      for (auto y : x) out << y << ' ';
      out << '\n';
    }
    return out;
  }

  static Matrix identity(int n) {
    Matrix a = Matrix(n, n);
    while (n--) a[n][n] = 1;
    return a;
  }

  Matrix operator * (const Matrix &b) {
    Matrix a = *this;

    assert(a.col() == b.row()); 

    Matrix c(a.row(), b.col());
    for (int i = 0; i < a.row(); ++i)
      for (int j = 0; j < b.col(); ++j)
        for (int k = 0; k < a.col(); ++k)
          c[i][j] += a[i][k] * b[k][j];
    return c;
  }

  Matrix pow(long long exp) {

    assert(row() == col());  

    Matrix base = *this, ans = identity(row());
    for (; exp > 0; exp >>= 1, base = base * base)
      if (exp & 1) ans = ans * base;
    return ans;
  }

  bool is_zero() {
    for (int i = 0; i < row(); ++i) {
      for (int j = 0; j < col(); ++j) {
        if (data[i][j] != 0) {
          return false;
        }
      }
    }
    return true;
  }
};