#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
vector<int> e[N];
int subTree[N];
int par[N];
int chainNum = 1;  // the number of chain
int chainRoot[N];  // root of a chain
int chainIn[N];	   // the chain of a node
int chainIdx[N];   // the ordinal number in chain of a node
int chainSize[N];  // size of a chain

void preCal(int u) {
	subTree[u] = 1;
	for (auto &v : e[u])
		if (par[u] != v) {
			par[v] = u;
			preCal(v);
			subTree[u] += subTree[v];
		}
}

void hld(int u) {
	// Add node u
	if (chainRoot[chainNum] == -1)
		chainRoot[chainNum] = u;
	chainIn[u] = chainNum;
	chainIdx[u] = ++chainSize[chainNum];

	// find special child
	int idx = 0;
	for (auto &v : e[u])
		if (v != par[u] && subTree[idx] < subTree[v])
			idx = v;

	// continue hld with node v
	if (idx > 0)
		hld(idx);

	// continue hld with new chain
	for (auto &v : e[u])
		if (v != par[u] && v != idx) {
			++chainNum;
			hld(v);
		}
}

void Solve() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	par[1] = -1;  // root is vertex 1
	preCal(1);	  // subTree[u]: number vertex in subtree vertex u

	memset(chainRoot, -1, sizeof(chainRoot));
	hld(1);
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	freopen("HLD.inp", "r", stdin);
	freopen("HLD.out", "w", stdout);
	Solve();
	return 0;
}