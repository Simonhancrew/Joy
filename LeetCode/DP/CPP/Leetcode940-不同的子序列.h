// 序列问题，考虑每一位选或者不选
// f[i][j], 前i为，以j结尾。此时有两种情况，选一个a[i]单独结尾，或者把a[i]
// append到结尾 所以, f[i][s[i] - 'a'] = 1 + accmulate(f[i][j], j [0,26))
// 进一步发现第一维度其实可以优化掉
class Solution {
 public:
  int distinctSubseqII(string s) {
    int n = s.size();
    const int P = 1e9 + 7;
    array<int, 26> f = {0};
    f[s[0] - 'a'] = 1;
    for (int i = 1; i < n; i++) {
      int rec = 0;
      rec = accumulate(f.begin(), f.end(), 1ll) % P;
      f[s[i] - 'a'] = rec;
    }
    return accumulate(f.begin(), f.end(), 0ll) % P;
  }
};