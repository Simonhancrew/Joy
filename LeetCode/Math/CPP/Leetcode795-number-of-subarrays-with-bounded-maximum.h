class Solution {
 public:
  using LL = long long;
  int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    int n = nums.size();
    auto calcu = [&nums, &n](int mx) {
      int res = 0;
      for (int i = 0; i < n; i++) {
        if (nums[i] > mx) continue;
        int j = i + 1;
        while (j < n && nums[j] <= mx) j++;
        int dis = j - i;
        res += (LL)dis * (dis + 1) / 2;
        i = j;
      }
      return res;
    };
    return calcu(right) - calcu(left - 1);
  }
};