class Solution {
 public:
  vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    int cnt = 0, n = security.size();
    vector<int> l(n, 0), r(n, 0), ans;
    for (int i = 1; i < n; i++) {
      if (security[i] <= security[i - 1])
        cnt++;
      else
        cnt = 0;
      l[i] = cnt;
    }
    cnt = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (security[i] <= security[i + 1])
        cnt++;
      else
        cnt = 0;
      r[i] = cnt;
    }
    for (int i = 0; i < n; i++) {
      if (l[i] >= time && r[i] >= time) ans.push_back(i);
    }
    return ans;
  }
};