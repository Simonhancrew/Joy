class Solution {
 public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int n = l.size();
    vector<bool> ans(n, false);
    auto check = [&ans](const vector<int> s, int idx) {
      int n = s.size();
      bool flag = true;
      for (int i = 1; i < n - 1; i++) {
        if (s[i + 1] - s[i] == s[1] - s[0]) continue;
        flag = false;
        break;
      }
      ans[idx] = flag;
    };
    for (int i = 0; i < n; i++) {
      auto cp = vector<int>{nums.begin() + l[i], nums.begin() + r[i] + 1};
      sort(cp.begin(), cp.end());
      check(cp, i);
    }
    return ans;
  }
};
