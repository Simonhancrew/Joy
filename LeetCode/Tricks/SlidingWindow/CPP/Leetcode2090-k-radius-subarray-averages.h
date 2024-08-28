class Solution {
public:
  using LL = long long;
  vector<int> getAverages(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> ans(n);
    LL acc = 0;
    for (int i = 0; i < n; i++) {
      acc += nums[i];
      if (i + k > n - 1 || i - k < 0) {
        ans[i] = -1;
      }
      if (i < 2 * k)
        continue;
      ans[i - k] = acc / (2 * k + 1);
      acc -= nums[i - 2 * k];
    }
    return ans;
  }
};
