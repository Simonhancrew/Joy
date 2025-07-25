class Solution {
 public:
  int maxSum(vector<int> &nums) {
    unordered_set<int> st;
    int ans = -1, mx = -101;
    for (const auto x : nums) {
      mx = max(mx, x);
      if (st.contains(x) || x < 0) {
        continue;
      }
      if (ans == -1)
        ans = 0;
      ans += x;
      st.insert(x);
    }
    if (ans == -1) {
      ans = mx;
    }
    return ans;
  }
};
