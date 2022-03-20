struct Node {
  // Variable and default value function
  @@HERE@@...
};

#warning Note: Make sure N is the same as the tree init size
int n;

template<typename T>
struct segtree {
  vector<Node> tree;
  int N_tree = -1;

  Node merge(const Node &a, const Node &b) {
    Node ret;
    // Process the merge of 2 nodes
    ...
    return ret;
  }

  template<typename T_vector>
  void build(vector<T_vector> &a) {
    assert(int(a.size()) == N_tree);
    for (int i = 0; i < n; ++i) {
      Node ret;
      ...
      set(i + 1, ret);
    }
  }

  /*
  // Return the problem's query
  ... get_ans(..., int id = 1, int l = 1, int r = n) {
    ...
  }
  */

  void set(int p, Node v, int id = 1, int l = 1, int r = n) {
    if (p < l || p > r) return;
    if (l == r) {
      // Return value of tree[id] here
      ...
      return;
    }
    int mid = l + (r - l) / 2;
    set(p, v, 2 * id, l, mid);
    set(p, v, 2 * id + 1, mid + 1, r);
    tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
  }

  // Simple get funcion of the Node
  Node get(int ll, int rr, int id = 1, int l = 1, int r = n) {
    if (rr < l || ll > r) return Node();
    if (ll <= l && rr >= r) {
      return tree[id];
    }
    int m = l + (r - l) / 2;
    Node ra = get(ll, rr, 2 * id, l, m);
    Node rb = get(ll, rr, 2 * id + 1, m + 1, r);
    return merge(ra, rb);
  }

  void init(int& N) {
    assert(N_tree == -1);
    N_tree = N;
    tree.resize(4 * N + 2);
  }

  segtree(int& N) {
    init(N);
  }
};