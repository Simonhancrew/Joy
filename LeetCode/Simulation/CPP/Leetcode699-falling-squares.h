
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> fallingSquares(vector<vector<int>> &positions) {
    const int n = positions.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int l1 = positions[i][0], r1 = positions[i][0] + positions[i][1] - 1;
      ans[i] = positions[i][1];
      for (int j = 0; j < i; j++) {
        int l2 = positions[j][0], r2 = positions[j][0] + positions[j][1] - 1;
        if (r1 >= l2 && r2 >= l1) {
          ans[i] = max(ans[i], ans[j] + positions[i][1]);
        }
      }
    }
    for (int i = 1; i < n; i++) {
      ans[i] = max(ans[i], ans[i - 1]);
    }
    return ans;
  }
};

#if 0
class SegTree {
public:
  SegTree(int kL, int kR) : l_(kL), r_(kR) {}

  void PushDown() {
    if (tag_ == 0 || l_ == r_) {
      return;
    }
    int mid = l_ + r_ >> 1;
    if (!lhs_) {
      lhs_ = make_unique<SegTree>(l_, mid);
    }
    if (!rhs_) {
      rhs_ = make_unique<SegTree>(mid + 1, r_);
    }
    lhs_->val_ = tag_;
    rhs_->val_ = tag_;
    rhs_->tag_ = tag_;
    lhs_->tag_ = tag_;
    tag_ = 0;
  }

  void PushUp() { val_ = max(lhs_->val_, rhs_->val_); }

  void Update(int kL, int kR, int val) {
    if (kL <= l_ && kR >= r_) {
      val_ = val;
      tag_ = val;
      return;
    }
    PushDown();
    int mid = l_ + r_ >> 1;
    if (!lhs_) {
      lhs_ = make_unique<SegTree>(l_, mid);
    }
    if (mid >= kL) {
      lhs_->Update(kL, kR, val);
    }
    if (!rhs_) {
      rhs_ = make_unique<SegTree>(mid + 1, r_);
    }
    if (mid < kR) {
      rhs_->Update(kL, kR, val);
    }
    PushUp();
  }

  int Query(int kL, int kR) {
    if (kL <= l_ && kR >= r_) {
      return val_;
    }
    PushDown();
    auto ans = 0;
    int mid = l_ + r_ >> 1;
    if (mid >= kL && lhs_) {
      ans = max(ans, lhs_->Query(kL, kR));
    }
    if (mid < kR && rhs_) {
      ans = max(ans, rhs_->Query(kL, kR));
    }
    return ans;
  }

private:
  unique_ptr<SegTree> lhs_{}, rhs_{};
  int val_{};
  int tag_{};
  int l_{}, r_{};
};

class Solution {
public:
  vector<int> fallingSquares(vector<vector<int>> &positions) {
    int n = positions.size();
    vector<int> ans;
    ans.reserve(n);
    SegTree seg(0, 1e8 + 1010);
    for (int i = 0; i < n; i++) {
      int l = positions[i][0], r = positions[i][1] + l - 1;
      int val = seg.Query(l, r);
      seg.Update(l, r, val + positions[i][1]);
      ans.push_back(seg.Query(0, 1e8 + 1010));
    }
    return ans;
  }
};
#endif