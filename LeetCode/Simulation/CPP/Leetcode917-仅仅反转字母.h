class Solution {
 public:
  string reverseOnlyLetters(string s) {
    int n = s.size();
    for (int i = 0, j = n - 1; i < j;) {
      while (i < j && !isalpha(s[i])) i++;
      while (i < j && !isalpha(s[j])) j--;
      swap(s[i], s[j]);
      i++, j--;
    }
    return s;
  }
};