#include <vector>

using namespace std;

struct Segtree {
  int l{}, r{};
  int sum{};
  Segtree *left{}, *right{};
  Segtree(int l, int r) : l(l), r(r) {}
  void PushUp() {
    sum = 0;
    if (left) {
      sum += left->sum;
    }
    if (right) {
      sum += right->sum;
    }
  }
  void Add(int kl, int kr, int val) {
    if (l >= kl && r <= kr) {
      sum = val;
      return;
    }
    int mid = l + r >> 1;
    if (mid >= kl) {
      if (!left) {
        left = new Segtree(l, mid);
      }
      left->Add(kl, kr, val);
    }
    if (mid < kr) {
      if (!right) {
        right = new Segtree(mid + 1, r);
      }
      right->Add(kl, kr, val);
    }
    PushUp();
  }

  int Ask(int kl, int kr) {
    if (kl <= l && kr >= r) {
      return sum;
    }
    int mid = l + r >> 1;
    int acc = 0;
    if (mid >= kl) {
      if (left) {
        acc += left->Ask(kl, kr);
      }
    }
    if (mid < kr) {
      if (right) {
        acc += right->Ask(kl, kr);
      }
    }
    return acc;
  }
};

class NumArray {
 public:
  Segtree *tr_;
  NumArray(vector<int> &nums) {
    tr_ = new Segtree(0, 3e4);
    // tr_->l = 0, tr_-> r = 3e4 - 1;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      tr_->Add(i, i, nums[i]);
    }
  }

  void update(int index, int val) { tr_->Add(index, index, val); }

  int sumRange(int left, int right) { return tr_->Ask(left, right); }
};
