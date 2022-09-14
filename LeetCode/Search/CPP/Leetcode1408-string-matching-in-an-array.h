class Solution {
 public:
  vector<string> stringMatching(vector<string> &words) {
    vector<string> res;
    int n = words.size();
    sort(words.begin(), words.end(),
         [](auto lhs, auto rhs) { return lhs.size() < rhs.size(); });
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (check(words[i], words[j])) {
          res.emplace_back(std::move(words[i]));
          break;
        }
      }
    }
    return res;
  }
  /*
      try kmp later
  */
  bool check(string &a, string &b) {
    int n = a.size();
    for (int i = 0; i <= b.size() - n; i++) {
      if (a[0] == b[i] && a == b.substr(i, n)) return true;
    }
    return false;
  }
};