class CountIntervals {
 public:
  using Self = CountIntervals;
  Self *lhs_{}, *rhs_{};
  int l_{1}, r_{int(1e9)}, cnt_{};
  CountIntervals() = default;
  CountIntervals(int l, int r) : l_(l), r_(r) {}

  void add(int left, int right) {
    if (cnt_ == r_ - l_ + 1) return;
    if (l_ >= left && r_ <= right) {
      cnt_ = r_ - l_ + 1;
      return;
    }
    int mid = l_ + r_ >> 1;
    if (!lhs_) lhs_ = new Self(l_, mid);
    if (!rhs_) rhs_ = new Self(mid + 1, r_);
    if (left <= mid) lhs_->add(left, right);
    if (mid < right) rhs_->add(left, right);
    cnt_ = lhs_->cnt_ + rhs_->cnt_;
  }

  int count() { return cnt_; }
};
