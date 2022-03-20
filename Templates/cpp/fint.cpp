long long add(long long A, long long B) {
  long long ret = A + B;
  if (ret >= mod) ret -= mod;
  return ret;
}

long long sub(long long A, long long B) {
  long long ret = A - B;
  if (ret < 0) ret += mod;
  return ret;
}

long long mul(long long A, long long B) {
  return (A * B) % mod;
}

long long bin_pow(long long x, long long p) {
  if (p == 0) return 1;
  if (p & 1) return mul(x, bin_pow(x, p - 1));
  return bin_pow(mul(x, x), p / 2);
}

long long rev(long long x) {
  return bin_pow(x, mod - 2);
}