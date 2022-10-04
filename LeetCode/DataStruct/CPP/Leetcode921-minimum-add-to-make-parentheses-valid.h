class Solution {
 public:
  int minAddToMakeValid(string s) {
    int l = 0, r = 0;
    for (auto c : s) {
      if (c == '(')
        l++;
      else if (c == ')') {
        if (!l)
          r++;
        else
          l--;
      }
    }
    return l + r;
  }
};