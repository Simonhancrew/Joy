class Solution {
 public:
  int longestDecomposition(string s) {
    if (s.empty()) return 0;
    for (int i = 1; i * 2 <= s.size(); i++) {
      if (s.substr(0, i) == s.substr(s.size() - i)) {
        return 2 + longestDecomposition(s.substr(i, s.size() - i * 2));
      }
    }
    return 1;
  }
};
