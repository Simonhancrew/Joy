class Solution {
 public:
  int maxHeight(vector<vector<int>>& cuboids) {
    for (auto& x : cuboids) sort(x.begin(), x.end());
    sort(cuboids.begin(), cuboids.end(), greater<>());
    int n = cuboids.size();
    vector<int> f(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
      f[i] = cuboids[i][2];
      for (int j = 0; j < i; j++) {
        if (cuboids[j][1] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2]) {
          f[i] = max(f[i], f[j] + cuboids[i][2]);
        }
      }
      res = max(res, f[i]);
    }
    return res;
  }
};