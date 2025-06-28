class Solution {
 public:
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    int n           = nums.size();
    vector<int> rec = vector<int>(n, 0);
    iota(rec.begin(), rec.end(), 0);
    sort(rec.begin(), rec.end(), [&nums](auto l, auto r) {
      return nums[l] > nums[r];
    });
    rec.resize(k);
    ranges::sort(rec);
    for (auto &x : rec) {
      x = nums[x];
    }
    return rec;
  }
};
