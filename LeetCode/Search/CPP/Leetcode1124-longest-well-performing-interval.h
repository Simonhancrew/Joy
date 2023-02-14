class Solution {
 public:
  int longestWPI(vector<int>& hours) {
    int n = hours.size();
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
    }
    int res = 0;
    vector<int> stk;
    stk.push_back(0);
    for (int i = 1; i <= n; i++) {
      int l = 0, r = stk.size() - 1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (s[i] > s[stk[mid]]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      if (s[stk[l]] < s[i]) {
        res = max(res, i - stk[l]);
      }
      if (s[i] < s[stk.back()]) {
        stk.push_back(i);
      }
    }
    return res;
  }
};
