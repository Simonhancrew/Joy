class StreamChecker {
 public:
  static const int N = 1e5 + 10;
  int son[N][26]{}, cnt[N]{}, idx = 0, len = 0;
  string s;
  void insert(const std::string& s) {
    int n = s.size();
    len = max(len, n);
    int p = 0;
    for (int i = n - 1; i >= 0; i--) {
      int u = s[i] - 'a';
      if (!son[p][u]) son[p][u] = ++idx;
      p = son[p][u];
    }
    cnt[p]++;
  }

  StreamChecker(vector<string>& words) {
    for (const auto& s : words) insert(s);
  }

  bool query(char letter) {
    s = letter + s;
    if (s.size() > len) s.pop_back();
    int n = s.size(), p = 0;
    for (int i = 0; i < n; i++) {
      int u = s[i] - 'a';
      if (!son[p][u]) return false;
      p = son[p][u];
      if (cnt[p] > 0) return true;
    }
    return false;
  }
};
