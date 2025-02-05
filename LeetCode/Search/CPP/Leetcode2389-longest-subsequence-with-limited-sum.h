class Solution {
 public:
  vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
    vector<int> ans;
    ranges::sort(nums);
    for (int i = 1; i < nums.size(); i++) {
      nums[i] += nums[i - 1];
    }
    for (const auto q : queries) {
      int l = -1, r = nums.size();
      while (l + 1 < r) {
        int mid = l + r >> 1;
        if (nums[mid] <= q)
          l = mid;
        else
          r = mid;
      }
      ans.push_back(l + 1);
    }
    return ans;
  }
};
