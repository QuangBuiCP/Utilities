/**
 *  --------------------------------------------------------------------------
 *    Author:   QuangBuiCP
 *    Template: Reachability Tree (0-indexed)
 *    Article:  https://codeforces.com/blog/entry/85714
 *  --------------------------------------------------------------------------
 *    Description: Given a graph with N vertices and M edges. RT* will create a tree
 *                 with N + M vertices where there is a virtual vertex between (u, v).
 *    Notice: - Can't optimized with union by size/rank.
 *            - Can optimized with path compression.
 *    Time complexity: O(N * log(N))
 *  --------------------------------------------------------------------------
**/
struct ReachabilityTree {
	int n;
	std::vector<int> par;
	std::vector<std::vector<int>> edge;
 
	ReachabilityTree(int _n = 0) : n(_n) {
		par.resize(n);
		edge.assign(n, {});
		iota(par.begin(), par.end(), 0);
	}
 
	int get_par(int x) {
		while (par[x] != x) {
			x = par[x] = par[par[x]];
		}
		return x;
	}
 
	bool unite(int x, int y) {
		x = get_par(x);
		y = get_par(y);
		if (x == y) return false;
		par.push_back(0);
		edge.emplace_back();
		par[n] = par[x] = par[y] = n;
		edge[n].push_back(x);
		edge[n].push_back(y);
		n++;
		return true;
	}
};