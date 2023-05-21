// 枚举蓄水的次数x，此时符合要求的桶装载能力最小是(vat[i] + x - 1) / x
// 酱紫的话就能得到一个差值，然后算一下有多少要增补的，最后算出答案
// 最大可能上限是vat的最大值，其次倒水的次数不要超过算出来的答案
class Solution {
 public:
  int storeWater(vector<int>& bucket, vector<int>& vat) {
    auto rhs = *max_element(vat.begin(), vat.end());
    if (rhs == 0) {
      return 0;
    }
    int ans = INT_MAX, n = vat.size();
    for (int pour = 1; pour <= rhs && pour < ans; pour++) {
      int add = 0;
      for (int i = 0; i < n; i++) {
        add += max(0, (vat[i] + pour - 1) / pour - bucket[i]);
      }
      ans = min(ans, add + pour);
    }
    return ans;
  }
};
