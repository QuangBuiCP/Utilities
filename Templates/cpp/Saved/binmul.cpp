template<typename T>
T binmul(T a, T b, T mod) {
  if (b == 0) return 0;
  if (b == 1) return a % mod;

  T ret = binmul(a, b / 2, mod);
  ret = (ret + ret) % mod;

  if (b % 2 == 1) ret = (ret + a) % mod;
  return ret;
}