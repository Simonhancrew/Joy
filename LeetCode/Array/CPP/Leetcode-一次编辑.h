class Solution {
 public:
  bool oneEditAway(string first, string second) {
    int n = first.size(), m = second.size(), cnt = 0;
    if (abs(n - m) > 1) return false;
    if (n > m) swap(first, second);
    n = first.size(), m = second.size();
    int i = 0, j = 0;
    while (i < n && j < m && cnt <= 1) {
      if (first[i] == second[j])
        ++i, ++j;
      else {
        if (n == m) {
          ++i, ++j, ++cnt;
        } else {
          ++j, ++cnt;
        }
      }
    }
    return cnt <= 1;
  }
};