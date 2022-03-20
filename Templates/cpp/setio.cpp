inline namespace fileio {
  void setin(string s) {
    freopen(s.c_str(), "r", stdin);
  }
  void setout(string s) {
    freopen(s.c_str(), "w", stdout);
  }
  void setio(string s = "") {
    if (int(s.size())) {
      setin(s + ".in");
      setout(s + ".out");
    }
  }
}