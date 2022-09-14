class Solution {
 public:
  string removeOuterParentheses(string s) {
    string ans;
    for (int i = 0, n = s.size(); i < n; i++) {
      int j = i + 1, cnt = 1;
      while (j < n && cnt != 0) {
        if (s[j] == '(')
          cnt++;
        else
          cnt--;
        j++;
      }
      ans += s.substr(i + 1, j - i - 2);
      i = j - 1;
    }
    return ans;
  }
};