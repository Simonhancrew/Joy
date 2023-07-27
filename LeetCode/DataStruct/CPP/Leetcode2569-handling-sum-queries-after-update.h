class Solution {
 public:
  using LL = long long;
  struct Node {
    int l{}, r{};
    LL val{};
    bool todo{};
  };
  static const int N = 4e5 + 10;
  Node tr[N];

  void pushup(int node) {
    tr[node].val = tr[node * 2].val + tr[node * 2 + 1].val;
  }

  void pushdown(int node) {
    if (!tr[node].todo) {
      return;
    }
    auto l_node = node * 2, r_node = node * 2 + 1;
    tr[l_node].val = tr[l_node].r - tr[l_node].l + 1 - tr[l_node].val;
    tr[r_node].val = tr[r_node].r - tr[r_node].l + 1 - tr[r_node].val;
    tr[l_node].todo = !tr[l_node].todo;
    tr[r_node].todo = !tr[r_node].todo;
    tr[node].todo = 0;
  }

  void build(int node, int l, int r, const vector<int>& arr) {
    if (l == r) {
      tr[node].l = l, tr[node].r = r;
      tr[node].val = arr[l - 1];
      return;
    }
    int mid = (l + r) >> 1;
    tr[node].l = l, tr[node].r = r;
    build(node * 2, l, mid, arr);
    build(node * 2 + 1, mid + 1, r, arr);
    pushup(node);
  }

  void update(int node, int L, int R) {
    if (tr[node].l >= L && tr[node].r <= R) {
      tr[node].val = tr[node].r - tr[node].l + 1 - tr[node].val;
      // cout << tr[node].l << ' ' << tr[node].r << ' ' << tr[node].val << endl;
      tr[node].todo = !tr[node].todo;
      return;
    }
    pushdown(node);
    int mid = tr[node].l + tr[node].r >> 1;
    if (mid >= L) update(node * 2, L, R);
    if (mid + 1 <= R) update(node * 2 + 1, L, R);
    pushup(node);
  }

  vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2,
                                vector<vector<int>>& queries) {
    vector<LL> ans;
    build(1, 1, nums1.size(), nums1);
    LL acc = accumulate(nums2.begin(), nums2.end(), 0ll);
    for (const auto& op : queries) {
      if (op[0] == 1) {
        update(1, op[1] + 1, op[2] + 1);
      } else if (op[0] == 2) {
        acc += tr[1].val * op[1];
      } else {
        ans.push_back(acc);
      }
    }
    return ans;
  }
};
