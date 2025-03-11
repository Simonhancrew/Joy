class Solution {
 public:
  int sumOfBeauties(vector<int> &nums) {
    int n = nums.size();
    vector<int> lmx(n, INT_MIN), rmin(n, INT_MAX);
    lmx[0] = nums[0], rmin[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      rmin[i] = min(rmin[i + 1], nums[i]);
    }
    int acc = 0;
    for (int i = 1; i <= n - 2; i++) {
      lmx[i] = max(lmx[i - 1], nums[i]);
      if (nums[i] < rmin[i + 1] && nums[i] > lmx[i - 1]) {
        acc += 2;
        continue;
      }
      if (nums[i] < nums[i + 1] && nums[i] > nums[i - 1]) {
        acc += 1;
      }
    }
    return acc;
  }
};
