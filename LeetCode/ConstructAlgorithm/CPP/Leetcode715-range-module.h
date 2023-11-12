#include <algorithm>
#include <set>
#include <vector>

using namespace std;

const int INF = 1e9 + 10;
using PII = pair<int, int>;

#define x first
#define y second

class RangeModule {
 public:
  set<PII> st;
  RangeModule() {
    st.insert({INF, INF});
    st.insert({-INF, -INF});
  }

  void addRange(int left, int right) {
    auto it = st.lower_bound({left, -INF});
    it--;
    if (it->y < left) it++;
    if (it->x > right)
      st.insert({left, right});
    else {
      auto j = it;
      while (j->x <= right) j++;
      j--;
      PII t({min(left, it->x), max(right, j->y)});
      while (it != j) {
        auto k = it;
        k++;
        st.erase(it);
        it = k;
      }
      st.erase(it);
      st.insert(t);
    }
  }

  bool queryRange(int left, int right) {
    auto it = st.upper_bound({left, INF});
    it--;
    return it->y >= right;
  }

  vector<PII> get(PII a, PII b) {
    vector<PII> res;
    if (a.x < b.x) {
      if (a.y > b.y) {
        res.push_back({a.x, b.x});
        res.push_back({b.y, a.y});
      } else {
        res.push_back({a.x, b.x});
      }
    } else {
      if (a.y > b.y) res.push_back({b.y, a.y});
    }
    return res;
  }

  void removeRange(int left, int right) {
    auto it = st.lower_bound({left, -INF});
    it--;
    if (it->y < left) it++;
    if (it->x <= right) {
      auto j = it;
      while (j->x <= right) j++;
      j--;

      auto a = get(*it, {left, right});
      auto b = get(*j, {left, right});

      while (it != j) {
        auto k = it;
        k++;
        st.erase(it);
        it = k;
      }
      st.erase(it);
      for (auto t : a) st.insert(t);
      for (auto t : b) st.insert(t);
    }
  }
};

#if DYNAMIC
class SegTree {
 public:
  SegTree() = default;

  void PushUp() {
    sum_ = 0;
    if (lhs_) {
      sum_ += lhs_->sum_;
    }
    if (rhs_) {
      sum_ += rhs_->sum_;
    }
  }

  void PushDown(int l_, int r_) {
    if (flag_ == -1) {
      return;
    }
    int mid = l_ + r_ >> 1;
    if (!lhs_) {
      lhs_ = new SegTree();
    }
    if (!rhs_) {
      rhs_ = new SegTree();
    }
    lhs_->sum_ = (mid - l_ + 1) * flag_;
    lhs_->flag_ = flag_;
    rhs_->sum_ = (r_ - mid) * flag_;
    rhs_->flag_ = flag_;
    flag_ = -1;
  }

  void Add(int l_, int r_, int l, int r, int val) {
    if (l <= l_ && r >= r_) {
      sum_ = (r_ - l_ + 1) * val;
      flag_ = val;
      return;
    }
    PushDown(l_, r_);
    int mid = l_ + r_ >> 1;
    if (!lhs_) {
      lhs_ = new SegTree();
    }
    if (mid >= l) {
      lhs_->Add(l_, mid, l, r, val);
    }
    if (!rhs_) {
      rhs_ = new SegTree();
    }
    if (mid < r) {
      rhs_->Add(mid + 1, r_, l, r, val);
    }
    PushUp();
  }

  int Query(int l_, int r_, int l, int r) {
    if (l_ >= l && r_ <= r) {
      return sum_;
    }
    PushDown(l_, r_);
    int mid = l_ + r_ >> 1;
    int sum = 0;
    if (mid >= l && lhs_) {
      sum += lhs_->Query(l_, mid, l, r);
    }
    if (mid < r && rhs_) {
      sum += rhs_->Query(mid + 1, r_, l, r);
    }
    return sum;
  }

 private:
  SegTree *lhs_{nullptr}, *rhs_{nullptr};
  int flag_{-1};
  int sum_{};
};

class RangeModule {
 public:
  RangeModule() {}

  void addRange(int left, int right) { tr_->Add(1, 1e9, left, right - 1, 1); }

  bool queryRange(int left, int right) {
    int sum = tr_->Query(1, 1e9, left, right - 1);
    return sum == right - left;
  }

  void removeRange(int left, int right) {
    tr_->Add(1, 1e9, left, right - 1, 0);
  }
  SegTree* tr_ = new SegTree;
};

#elif STATIC

const int N = 8e6;
struct Node {
  int ls, rs, val, tag;
  int l, r;
  Node() {
    l = r = rs = ls = val = 0;
    tag = -1;
  }
  Node(int l, int r) : l(l), r(r), ls(0), rs(0), val(0), tag(-1) {}
};

Node tr[N];
int cnt = 1;

void lazy_create(int u) {
  int mid = tr[u].l + tr[u].r >> 1;
  if (tr[u].ls == 0) {
    tr[u].ls = ++cnt;
    tr[tr[u].ls].l = tr[u].l;
    tr[tr[u].ls].r = mid;
    tr[tr[u].ls].tag = -1;
    tr[tr[u].ls].val = 0;
  }
  if (tr[u].rs == 0) {
    tr[u].rs = ++cnt;
    tr[tr[u].rs].l = mid + 1;
    tr[tr[u].rs].r = tr[u].r;
    tr[tr[u].rs].tag = -1;
    tr[tr[u].rs].val = 0;
  }
}

void push_down(int u) {
  if (tr[u].tag != -1) {
    int &tag = tr[u].tag;
    tr[tr[u].ls].val = tag * (tr[tr[u].ls].r - tr[tr[u].ls].l + 1);
    tr[tr[u].rs].val = tag * (tr[tr[u].rs].r - tr[tr[u].rs].l + 1);
    tr[tr[u].ls].tag = tag;
    tr[tr[u].rs].tag = tag;
    tag = -1;
  }
}

void push_up(int u) {
  int lhs = tr[u].ls, rhs = tr[u].rs;
  tr[u].val = tr[lhs].val + tr[rhs].val;
}

void add(int u, int L, int R, int k) {
  if (tr[u].l >= L && tr[u].r <= R) {
    tr[u].val = (tr[u].r - tr[u].l + 1) * k;
    tr[u].tag = k;
    return;
  }
  lazy_create(u);
  push_down(u);
  int mid = tr[u].l + tr[u].r >> 1;
  if (mid >= L) add(tr[u].ls, L, R, k);
  if (mid < R) add(tr[u].rs, L, R, k);
  push_up(u);
}

int query(int u, int L, int R) {
  if (tr[u].l >= L && tr[u].r <= R) {
    return tr[u].val;
  }
  lazy_create(u);
  push_down(u);
  int mid = tr[u].l + tr[u].r >> 1;
  int ans = 0;
  if (mid >= L) ans += query(tr[u].ls, L, R);
  if (mid < R) ans += query(tr[u].rs, L, R);
  return ans;
}

void clear() {
  for (int i = 1; i < N; i++) tr[i].ls = 0, tr[i].rs = 0;
  cnt = 1;
}

class RangeModule {
 public:
  RangeModule() {
    clear();
    tr[1].l = 1;
    tr[1].r = 1e9;
  }

  void addRange(int left, int right) { add(1, left, right - 1, 1); }

  bool queryRange(int left, int right) {
    auto sum = query(1, left, right - 1);
    return sum == right - left;
  }

  void removeRange(int left, int right) { add(1, left, right - 1, 0); }
};

#endif
