class Solution {
 public:
  bool isAcronym(vector<string>& words, string s) {
    if (s.size() != words.size()) {
      return false;
    }
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (words[i].front() != s[i]) {
        return false;
      }
    }
    return true;
  }
};
