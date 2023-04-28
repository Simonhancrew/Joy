class DinnerPlates {
 public:
  int cap, top = -1; // 最顶端
  set<int> st; // 不满的idx
  vector<vector<int>> s; // 记录每个index的
  DinnerPlates(int capacity) : cap(capacity) {}

  void push(int val) {
    if (st.empty()) {
      st.insert(++top);
      s.push_back(vector<int>());
    }
    auto l = st.begin();
    auto& tar = s[*l];
    top = max(top, *l);
    tar.push_back(val);
    if (tar.size() == cap) {
      st.erase(l);
    }
  }

  int pop() { return popAtStack(top); }

  int popAtStack(int index) {
    if (index == -1 || index > top) return -1;
    auto& tar = s[index];
    if (tar.empty()) return -1;
    auto res = tar.back();
    tar.pop_back();
    if (tar.size() == cap - 1) st.insert(index);
    while (top >= 0 && s[top].empty()) top--;
    return res;
  }
};
