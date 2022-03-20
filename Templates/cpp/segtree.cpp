/**
 *  --------------------------------------------------------------------------
 *    Author:          QuangBuiCP
 *    Template:        Segment Tree (0-indexed) (Modified)
 *    Original author: tourist
 *    Original source: https://github.com/the-tourist/algo/blob/master/data/segtree.cpp
 *    Status:          Not stable
 *  --------------------------------------------------------------------------
 *    Overall time:    O(n * log(n))
 *    Memory size:     O(2 * n - 1)
 *
 *    Basic usage:
 *    - Do SegmentTree<node> variable_name(tree_size)
 *      or SegmentTree<node> variable_name(build_from_std::vector)
 *    - apply(): value of a leaf
 *    - unite(): Merge 2 nodes
 *    - For Lazy Propagation, use "add" in "node" with push()
 *    - find_first*(), find_last*(): Binary search (I think)
 * 
 *    Standard Library required:
 *    - <vector>
 *    - <functional>
 *    - <cassert>
 *  --------------------------------------------------------------------------
**/

namespace segtreen {

struct node {
  // don't forget to set default value (used for leaves)
  // not necessarily neutral element!
  @@HERE@@

  template<typename T>
  void apply(int l, int r, T v) {
    ...
  }

  // unite(): Merge 2 nodes
  node operator + (const node &b) {
    const node &a = *this;
    node res;
    ...
    return res;
  }
};

} // segtreen

template<typename T>
class SegmentTree {
 public:
/*
  node unite(const node &a, const node &b) {
    node res;
    ...
    return res;
  }
*/

  inline void push(int x, int l, int r) {
    // push from x into (x + 1) and z
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    ...
/*
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
*/
  }

  inline void pull(int x, int z) {
    // tree[x] = unite(tree[x + 1], tree[z]);
    tree[x] = tree[x + 1] + tree[z];
  }

  int n;
  std::vector<T> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M>
  void build(int x, int l, int r, const std::vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  T get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    T res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        // res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
        res = get(x + 1, l, y, ll, rr) + get(z, y + 1, r, ll, rr);
      }
    }
    pull(x, z);
    return res;
  }

  template <typename... M>
  void update(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      update(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      update(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const std::function<bool(const T&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const std::function<bool(const T&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const std::function<bool(const T&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const std::function<bool(const T&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  SegmentTree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
  SegmentTree(const std::vector<M> &v) {
    n = (int) v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  T get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  T get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void update(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    update(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const std::function<bool(const T&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const std::function<bool(const T&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};