#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
    int n = s.size();
    vector<int> pre(n + 1), idx, ans;
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '*') {
        pre[i] = pre[i - 1] + 1;
      } else {
        pre[i] = pre[i - 1];
        idx.push_back(i - 1);
      }
    }
    for (auto q : queries) {
      int l = q[0], r = q[1];
      int ll = lower_bound(idx.begin(), idx.end(), l) - idx.begin();
      int rr = upper_bound(idx.begin(), idx.end(), r) - idx.begin() - 1;
      if (rr < ll)
        ans.push_back(0);
      else
        ans.push_back(pre[idx[rr]] - pre[idx[ll]]);
    }
    return ans;
  }
};