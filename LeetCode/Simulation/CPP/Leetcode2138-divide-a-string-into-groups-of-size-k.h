class Solution {
 public:
  vector<string> divideString(string s, int k, char fill) {
    vector<string> res;
    int n = s.size();
    res.reserve((n + k - 1) / k);
    for (int l = 0; l < n; l += k) {
      string tmp = s.substr(l, k);
      if (tmp.size() < k) {
        tmp += string(k - tmp.size(), fill);
      }
      res.emplace_back(move(tmp));
    }
    return res;
  }
};
