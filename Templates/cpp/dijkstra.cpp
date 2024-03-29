template<typename T>
struct Dijkstra {
	const T INF = numeric_limits<T>::max();

	struct State {
		int u;
		T dist;

		State() {}

		State(int _u, T _dist) : u(_u), dist(_dist) {}

		bool operator < (const State &other) const {
			return dist > other.dist;
		}
	};

	int n;
	vector<vector<pair<int, T>>> graph;
	vector<T> dist;
	vector<int> parent;

	Dijkstra(int _n = 0) {
		init(_n);
	}

	void init(int _n) {
		n = _n;
		graph.resize(n);
	}

	void add_directed_edge(int u, int v, T weight) {
		graph[u].emplace_back(v, weight);
	}

	void add_edge(int u, int v, T weight) {
		add_directional_edge(u, v, weight);
		add_directional_edge(v, u, weight);
	}

	void run(const vector<int> &source) {
		priority_queue<State> pq;
		dist.assign(n, INF);
		parent.assign(n, -1);

		for (const auto &u : source) {
			dist[u] = 0;
			parent[u] = u;

			pq.emplace(u, 0);
		}

		while (!pq.empty()) {
			State top = pq.top();
			int u = top.u;
			T cur_dist = top.dist;
			pq.pop();

			if (dist[u] != cur_dist) continue;

			for (const auto &[v, weight] : graph[u]) {
				T new_dist = cur_dist + weight;

				if (new_dist < dist[v]) {
					dist[v] = new_dist;
					parent[v] = u;
					pq.emplace(v, new_dist);
				}
			}
		}
	}

	bool reachable(int u) {
		return dist[u] < INF;
	}
};