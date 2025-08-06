class SegTree {
 public:
  vector<int> tr;
  vector<int> &arr;
  SegTree(vector<int> &arr) : arr(arr) {
    auto n = arr.size();
    // 满2叉树 = 2 * N - 1, N是底层节点数
    // 非满2叉树 => 最底层扩为满节点，然后再扩大2倍，2 << bit_width(n - 1),
    tr.resize(2 << bit_width(n - 1));
    build(1, 0, n - 1);
  }

  void update(int node) {
    tr[node] = max(tr[node * 2], tr[node * 2 + 1]);
  }

  void build(int node, int l, int r) {
    if (l == r) {
      tr[node] = arr[l];
      return;
    }
    int mid = l + r >> 1;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    update(node);
  }

  int query(int node, int val, int l, int r) {
    if (tr[node] < val) {
      return -1;
    }
    if (l == r) {
      tr[node] = -1;
      return l;
    }
    int mid = l + r >> 1;
    int i   = query(node * 2, val, l, mid);
    if (i < 0) {
      i = query(node * 2 + 1, val, mid + 1, r);
    }
    update(node);
    return i;
  }
};

class Solution {
 public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    SegTree tr(baskets);
    int ans = 0, n = baskets.size();
    for (const auto x : fruits) {
      if (tr.query(1, x, 0, n - 1) < 0) {
        ++ans;
      }
    }
    return ans;
  }
};
