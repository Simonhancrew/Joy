class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1, v = 0; j <= k && j <= i; j++) {
        v = max(v, arr[i - j]);
        f[i] = max(f[i], f[i - j] + v * j);
      }
    }
    return f[n];
  }
};