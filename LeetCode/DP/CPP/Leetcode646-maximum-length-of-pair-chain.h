// 最蠢的做法，sort + dp
class Solution {
 public:
  int findLongestChain(vector<vector<int>> &pairs) {
    sort(pairs.begin(), pairs.end(),
         [](vector<int> &lhs, vector<int> &rhs) { return lhs[0] < rhs[0]; });
    int ans = 1, n = pairs.size();
    vector<int> f(n, 1);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (pairs[i][0] > pairs[j][1]) f[i] = max(f[i], f[j] + 1);
      }
    }
    for (int i = 0; i < n; i++) ans = max(ans, f[i]);
    return ans;
  }
};