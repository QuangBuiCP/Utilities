template<typename A, typename B> ostream& operator<<(ostream &cerr, pair<A, B> const &p) { 
	return cerr << "(" << p.first << ", " << p.second << ")"; 
}
template<typename A> ostream& operator<<(ostream &cerr, vector<A> const &v) {
	cerr << "["; for(unsigned ll int i = 0; i < v.size(); i++) {if (i) cerr << ", "; cerr << v[i];} return cerr << "]";
}