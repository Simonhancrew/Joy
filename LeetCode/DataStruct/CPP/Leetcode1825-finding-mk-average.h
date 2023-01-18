class MKAverage {
 public:
  using LL = long long;
  struct TreeSet {
    LL sum = 0;
    multiset<int> st;
    int front() const { return *st.begin(); }
    int back() const { return *st.rbegin(); }
    void add(int num) {
      st.insert(num);
      sum += num;
    }
    void del(int num) {
      st.erase(st.find(num));
      sum -= num;
    }
    bool has(int num) const { return st.find(num) != st.end(); }
    int size() const { return st.size(); }
  };
  int m, k;
  vector<int> q;
  TreeSet lhs, mid, rhs;
  MKAverage(int m, int k) : m(m), k(k) {}

  void addElement(int num) {
    q.push_back(num);
    if (q.size() < m) return;
    if (q.size() == m) {
      auto t = q;
      sort(t.begin(), t.end());
      for (int i = 0; i < k; i++) lhs.add(t[i]);
      for (int i = k; i < m - k; i++) mid.add(t[i]);
      for (int i = m - k; i < m; i++) rhs.add(t[i]);
    } else {
      // 先插中间然后交换
      mid.add(num);
      // 左边不满足要求
      int x = lhs.back(), y = mid.front();
      if (x > y) {
        mid.del(y), mid.add(x);
        lhs.del(x), lhs.add(y);
      }
      // 右边不满足要求
      y = mid.back();
      int z = rhs.front();
      if (z < y) {
        mid.del(y), mid.add(z);
        rhs.del(z), rhs.add(y);
      }
      // 移除过期元素
      int tar = q[q.size() - 1 - m];
      if (lhs.has(tar)) {
        lhs.del(tar);
        int tmp = mid.front();
        lhs.add(tmp), mid.del(tmp);
      } else if (mid.has(tar)) {
        mid.del(tar);
      } else {
        rhs.del(tar);
        int tmp = mid.back();
        rhs.add(tmp), mid.del(tmp);
      }
    }
  }

  int calculateMKAverage() {
    if (q.size() < m) return -1;
    return mid.sum / mid.size();
  }
};
