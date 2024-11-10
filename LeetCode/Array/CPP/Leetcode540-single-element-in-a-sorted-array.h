/*
  相等的两个元素一定是相邻的，不相等的元素一定是在奇数下标位置
  因此找分界点就可以
*/
class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int l = -1, r = nums.size() / 2;
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (nums[mid * 2] == nums[mid * 2 + 1])
        l = mid;
      else
        r = mid;
    }
    return nums[r * 2];
  }
};
