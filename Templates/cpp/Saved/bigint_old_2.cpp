typedef vector<int> BigNum;
typedef long long ll;
const int BASE = 1e9;

void clean(BigNum& a) {
	while (a.size() > 1 && a.back() == 0) a.pop_back();
}

BigNum convert(const string& s) {
	BigNum a;
	for (int i = (int)s.size(); i > 0; i -= 9) {
		if (i < 9)
			a.push_back(atoi(s.substr(0, i).c_str()));
		else
			a.push_back(atoi(s.substr(i - 9, 9).c_str()));
	}
	return a;
}

BigNum Read() {
	string s;
	cin >> s;
	return convert(s);
}

void Write(const BigNum& a) {
	cout << (a.empty() ? 0 : a.back());
	for (int i = (int)a.size() - 2; i >= 0; i--) {
		cout << setw(9) << setfill('0') << a[i];
	}
}

BigNum Add(BigNum a, const BigNum& b) {
	int carry = 0;
	int sz = max(a.size(), b.size());
	for (int i = 0; i < sz || carry; i++) {
		if (i == a.size()) a.push_back(0);
		a[i] += carry + (i < b.size() ? b[i] : 0);
		carry = a[i] >= BASE;
		if (carry) a[i] -= BASE;
	}
	return a;
}

// return 1 if a > b, 0 if a = b, -1 if a < b
int comp(const BigNum& a, const BigNum& b) {
	if (a.size() != b.size()) {
		return (a.size() > b.size() ? 1 : -1);
	} else {
		for (int i = (int)a.size() - 1; i >= 0; i--) {
			if (a[i] == b[i]) continue;
			return (a[i] > b[i] ? 1 : -1);
		}
		return 0;
	}
}

// a >= b
BigNum Sub(BigNum a, const BigNum& b) {
	int carry = 0;
	for (int i = 0; i < b.size() || carry; i++) {
		if (i == a.size()) a.push_back(0);
		a[i] -= carry + (i < b.size() ? b[i] : 0);
		carry = a[i] < 0;
		if (carry) a[i] += BASE;
	}
	clean(a);
	return a;
}

BigNum Mul(BigNum a, const int& b) {
	int carry = 0;
	for (int i = 0; i < a.size() || carry; i++) {
		if (i == a.size()) a.push_back(0);
		ll cur = carry + a[i] * 1LL * b;
		a[i] = cur % BASE;
		carry = cur / BASE;
	}
	clean(a);
	return a;
}

BigNum Mul(const BigNum& a, const BigNum& b) {
	BigNum c(a.size() + b.size());
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0, carry = 0; j < b.size() || carry; j++) {
			ll cur = carry + c[i + j] + a[i] * 1LL * (j < b.size() ? b[j] : 0);
			c[i + j] = cur % BASE;
			carry = cur / BASE;
		}
	}
	clean(c);
	return c;
}

BigNum Div(BigNum a, const int& b) {
	int carry = 0;
	for (int i = (int)a.size() - 1; i >= 0; i--) {
		ll cur = a[i] + carry * 1LL * BASE;
		a[i] = cur / b;
		carry = cur % b;
	}
	clean(a);
	return a;
}