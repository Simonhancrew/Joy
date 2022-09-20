class Solution {
 public:
  int ave;
  vector<bool> st;

  bool dfs(vector<int> &nums, int start, int cur, int k) {
    if (k == 1)
      return true;
    if (cur > ave)
      return false;
    if (cur == ave)
      return dfs(nums, 0, 0, k - 1);
    for (int i = start; i < nums.size(); i++) {
      if (st[i])
        continue;
      if (cur + nums[i] <= ave) {
        st[i] = true;
        if (dfs(nums, start + 1, cur + nums[i], k))
          return true;
        st[i] = false;
      }
      if (!cur)
        return false;
    }
    return false;
  }

  bool canPartitionKSubsets(vector<int> &nums, int k) {
    // this->nums = nums;
    st.resize(nums.size());
    int acc = accumulate(nums.begin(), nums.end(), 0);
    if (acc % k)
      return false;
    ave = acc / k;
    sort(nums.begin(), nums.end(), [](int lhs, int rhs) {
      return lhs > rhs;
    });
    return dfs(nums, 0, 0, k);
  }
};
