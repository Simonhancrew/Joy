class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    int mask = 0, res = 0;
    for (auto c : allowed) mask |= 1 << (c - 'a');
    for (auto word : words) {
      int cur = 0;
      for (auto c : word) {
        cur |= 1 << (c - 'a');
      }
      res += (mask | cur) == mask;
    }
    return res;
  }
};
