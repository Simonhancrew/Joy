class Solution {
 public:
  using PII = pair<int, int>;
  int expressiveWords(string s, vector<string>& words) {
    int ans = 0, n = s.size();
    vector<PII> rec;
    for (int i = 0; i < n; i++) {
      int j = i + 1;
      while (j < n && s[i] == s[j]) j++;
      rec.emplace_back(s[i] - 'a', j - i);
      i = j - 1;
    }
    auto check = [&s, &rec, n](string& w) {
      if (w.size() > s.size()) return false;
      int m = w.size(), k = 0;
      for (int i = 0; i < m; i++) {
        if (k == rec.size()) return false;
        if (w[i] - 'a' != rec[k].first) return false;
        int j = i + 1;
        while (j < m && w[j] == w[i]) j++;
        int difw = j - i, difs = rec[k].second;
        if (difw > difs) return false;
        if (difw != difs && difs < 3) return false;
        k++, i = j - 1;
      }
      return k == rec.size();
    };
    for (auto& w : words) {
      if (check(w)) ans++;
    }
    return ans;
  }
};