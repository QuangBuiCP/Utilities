template <typename Graph>
vector<int> Dial(Graph& graph, int src, int lim) {
	vector<vector<int>> qs(lim);
	vector<int> dist(graph.size(), -1);
	dist[src] = 0;
	qs[0].push_back(src);
	for (int d = 0, maxd = 0; d <= maxd; ++d) {
		for (auto& q = qs[d % lim]; q.size();) {
			int node = q.back();
			q.pop_back();
			if (dist[node] != d) continue;
			for (auto [vec, cost] : graph[node]) {
				if (dist[vec] != -1 && dist[vec] <= d + cost) continue;
				dist[vec] = d + cost;
				qs[(d + cost) % lim].push_back(vec);
				maxd = max(maxd, d + cost);
			}
		}
	}
	return dist;
}