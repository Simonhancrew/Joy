class Solution {
 public:
  int maximumUniqueSubarray(vector<int> &nums) {
    unordered_set<int> st;
    int ans = 0, cur = 0;
    for (int i = 0, j = 0; i < nums.size(); i++) {
      while (st.count(nums[i]) && j < i) {
        st.erase(nums[j]);
        cur -= nums[j];
        j++;
      }
      st.insert(nums[i]);
      cur += nums[i];
      ans = max(ans, cur);
    }
    return ans;
  }
};
