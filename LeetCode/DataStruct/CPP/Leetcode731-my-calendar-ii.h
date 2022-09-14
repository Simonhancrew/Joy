class segtree {
 public:
  segtree(int l, int r)
      : l(l), r(r), left(nullptr), right(nullptr), val(0), tag(0) {}

  void push_down() {
    int mid = l + r >> 1;
    if (!left) {
      left = new segtree(l, mid);
    }
    if (!right) {
      right = new segtree(mid + 1, r);
    }
    if (!tag) return;
    left->val += tag;
    right->val += tag;
    left->tag += tag;
    right->tag += tag;
    tag = 0;
  }
  void push_up() { val = max(left->val, right->val); }

  void add(int L, int R, int k) {
    if (l >= L && r <= R) {
      val += k;
      tag += k;
    } else {
      push_down();
      int mid = l + r >> 1;
      if (mid >= L) {
        left->add(L, R, k);
      }
      if (mid < R) {
        right->add(L, R, k);
      }
      push_up();
    }
  }

  int query(int L, int R) {
    if (l >= L && r <= R) {
      return val;
    }
    push_down();
    int mid = l + r >> 1;
    int ans = 0;
    if (mid >= L) {
      ans = max(ans, left->query(L, R));
    }
    if (mid < R) {
      ans = max(ans, right->query(L, R));
    }
    return ans;
  }

 private:
  segtree *left, *right;
  int l, r;
  int val, tag;
};
class MyCalendarTwo {
 public:
  segtree *seg;
  MyCalendarTwo() { seg = new segtree(0, 1e9); }

  bool book(int start, int end) {
    int cnt = seg->query(start, end - 1);
    if (cnt < 2) {
      seg->add(start, end - 1, 1);
      return true;
    }
    return false;
  }
};
