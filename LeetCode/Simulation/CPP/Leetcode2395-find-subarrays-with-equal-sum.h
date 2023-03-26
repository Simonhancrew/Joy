class Solution {
 public:
  bool findSubarrays(vector<int>& nums) {
    unordered_set<int> st;
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      int cur = nums[i] + nums[i - 1];
      if (st.count(cur)) return true;
      st.insert(cur);
    }
    return false;
  }
};