class Solution {
 public:
  vector<vector<int>> f;
  int dfs(int n, int c) {
    if (n == 1) {
      return 1;
    }
    if (f[n][c] != -1) return f[n][c];
    int ans = 0;
    for (int i = c; i < 5; i++) {
      ans += dfs(n - 1, i);
    }
    return f[n][c] = ans;
  }

  int countVowelStrings(int n) {
    int ans = 0;
    f.resize(n + 1, vector<int>(5, -1));
    for (int i = 0; i < 5; i++) {
      ans += dfs(n, i);
    }
    return ans;
  }
};