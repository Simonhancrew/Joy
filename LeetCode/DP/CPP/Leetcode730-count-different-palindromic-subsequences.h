/*
    f[i][j]，从i到j有多少个回文。因为限定了出现的字母，所以回文只会在
    a..a,b..b,c..c,d..d，或者单个字母中出现。做区间dp的时候找两边字母的位置
    结果就是f[i][j] = (f[i][j] + f[l + 1][r - 1]),其中l和r是字母出现两端的位置
    因为单一字符也算回文，所以总情况需要+1。
    最后去掉空串贡献的结果就是答案
*/
class Solution {
 public:
  const int P = 1e9 + 7;
  int countPalindromicSubsequences(string s) {
    int n = s.size();
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 1));
    for (int i = 1; i <= n; i++) f[i][i]++;
    for (int len = 2; len <= n; len++) {
      deque<int> q[4];
      for (int j = 1; j <= n; j++) {
        q[s[j - 1] - 'a'].push_back(j);
        int i = j - len + 1;
        if (i >= 1) {
          for (int k = 0; k < 4; k++) {
            while (q[k].size() && q[k].front() < i) q[k].pop_front();
            if (q[k].size()) {
              f[i][j]++;
              int l = q[k].front(), r = q[k].back();
              if (l < r) {
                f[i][j] = (f[i][j] + f[l + 1][r - 1]) % P;
              }
            }
          }
        }
      }
    }
    cout << f[1][n] << endl;
    return (f[1][n] - 1) % P;
  }
};