class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    double ans = std::numeric_limits<int>::min();
    int n = nums.size();
    int acc = 0;
    for (int i = 0; i < n; i++) {
      acc += nums[i];
      if (i < k - 1)
        continue;
      auto cur = static_cast<double>(acc) / k;
      ans = max(ans, cur);
      acc -= nums[i - k + 1];
    }
    return ans;
  }
};
