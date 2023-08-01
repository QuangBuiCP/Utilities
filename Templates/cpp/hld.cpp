// https://codeforces.com/blog/entry/53170
// Then you will have such array that subtree of $u$ correspond to segment $[tin[u], tout[u])$
//   and the path from $u$ to the last vertex in ascending heavy path from $u$ (which is $chain_root[u]$) will be $[tin[chain_root[u]], tin[u]]$ subsegment
//   which gives you the opportunity to process queries on pathes and subtrees simultaneously in the same segment tree.
// TODO: Verify the code and write it with "struct"
int n;
int par[N], depth[N], subtree[N];
vector<int> g[N], ng[N];

int tin[N], tout[N], chain_root[N];

void dfs_par(int u, int pre) {
	for (int v : g[u]) if (v != pre) {
		par[v] = u;
		dfs_par(v, u);
	}
}

void dfs_size(int u, int pre) {
	subtree[u] = 1;
	for (int& v : ng[u]) if (v != pre) {
		dfs_size(v, u);
		subtree[u] += subtree[v];
		if (subtree[v] > subtree[ng[u][0]]) {
			swap(v, ng[u][0]);
		}
	}
}

int timer = 0;
void dfs_hld(int u, int pre) {
	tin[u] = ++timer;
	for (int v : ng[u]) if (v != pre) {
		chain_root[v] = (v == ng[u][0] ? chain_root[u] : v);
		depth[v] = depth[u] + 1;
		dfs_hld(v, u);
	}
	tout[u] = timer;
}

void build_hld(int root) {
	dfs_par(root, -1);
	for (int i = 1; i <= n; ++i) {
		for (int v : g[i]) {
			if (par[v] == i) {
				ng[i].push_back(v);
			}
		}
	}
	dfs_size(root, -1);
	dfs_hld(root, -1);
}

int get_lca(int x, int y) {
	while (chain_root[x] != chain_root[y]) {
		if (depth[chain_root[x]] < depth[chain_root[y]])
			swap(x, y);
		x = par[chain_root[x]];
	}
	return (depth[x] < depth[y] ? x : y);
}

... query_path(int x, int y) {
	... ans = ...;
	while (chain_root[x] != chain_root[y]) {
		if (depth[chain_root[x]] < depth[chain_root[y]])
			swap(x, y);
		int from = tin[chain_root[x]];
		int to = tin[x];
		...
		x = par[chain_root[x]];
	}
	if (depth[x] > depth[y])
		swap(x, y);
	int from = tin[x];
	int to = tin[y];
	...
	return ans;
}