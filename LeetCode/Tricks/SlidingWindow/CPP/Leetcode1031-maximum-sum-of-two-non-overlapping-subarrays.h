class Solution {
 public:
  int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    int n = nums.size();
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
    int res = 0;
    auto f = [&nums, n, &res, &s](int l, int r) {
      int mx = s[l];
      for (int i = l + r; i <= n; i++) {
        int rhs = s[i] - s[i - r];
        mx = max(mx, s[i - r] - s[i - r - l]);
        res = max(res, mx + rhs);
      }
    };
    f(firstLen, secondLen);
    f(secondLen, firstLen);
    return res;
  }
};