// Thanks to SlavicG
struct dsu {
  vector<pair<int,int>> p;
  vector<int> rank;
  vector<int> bipartite;
  // Adds a node to the graph
  void add(int v) {
    p[v] = make_pair(v, 0);
    rank[v] = 0;
    bipartite[v] = true;
  }
  // Returns the root of the subtree of a node and its parity
  pair<int,int> getb(int v) {
    if (v != p[v].first) {
      int parity = p[v].second;
      p[v] = getb(p[v].first);
      p[v].second ^= parity;
    }
    return p[v];
  }
  // Return the root of the subtree of a node
  int get(int v) {
    return getb(v).first;
  }
  // Merges 2 components
  void uni(int a, int b) {
    pair<int,int> ap = getb(a), bp = getb(b);
    a = ap.first, b = bp.first;
    int x = ap.second, y = bp.second;
    if (a == b) {
      if (x == y) bipartite[a] = false;
    }
    else {
      if (rank[a] < rank[b]) swap(a, b);
      p[b] = make_pair(a, x ^ y ^ 1);
      bipartite[a] &= bipartite[b];
      if (rank[a] == rank[b]) ++rank[a];
    }
  }
  // Returns true if the graph is bipartite and false otherwise
  bool is_bipartite(int v) {
    return bipartite[get(v)];
  }
  // Returns true if 2 nodes are in the same component and false otherwise
  bool same_component(int a, int b) {
    return get(a) == get(b);
  }
  // Returns the number of components
  int count_components(int n) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
      if (p[i].first == i) ++ret;
    }
    return ret;
  }
  // Initialize the graph / Make set
  dsu(int n) {
    p.resize(n), rank.resize(n), bipartite.resize(n);
    for (int i = 0; i < n; i++) {
      add(i);
    }
  }
};