class Solution {
 public:
  bool halvesAreAlike(string s) {
    int n = s.size() / 2, cnt = 0;
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < n; i++) {
      if (st.count(s[i])) cnt++;
    }
    for (int i = n; i < n * 2; i++) {
      if (st.count(s[i])) cnt--;
      if (cnt < 0) return false;
    }
    return cnt == 0;
  }
};