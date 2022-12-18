class Solution {
 public:
  int minMoves(vector<int>& nums, int k) {
    int res = numeric_limits<int>::max(), n = nums.size();
    vector<int> rec;
    for (int i = 0; i < n; i++) {
      if (nums[i]) rec.push_back(i - rec.size());
    }
    int m = rec.size();
    vector<int> s(m + 1);
    for (int i = 1; i <= m; i++) {
      s[i] = s[i - 1] + rec[i - 1];
    }
    for (int i = k; i <= m; i++) {
      int l = i - k + 1, r = i;
      int mid = l + r >> 1;
      int x = rec[mid - 1];
      int left = x * (mid - l) - s[mid - 1] + s[l - 1];
      int right = s[r] - s[mid] - x * (r - mid);
      res = min(res, left + right);
    }
    return res;
  }
};