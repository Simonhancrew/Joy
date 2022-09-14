#if 0
// 异或，单一。O(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int tar = 0;
        for(auto num : nums) tar ^= num;
        return tar;
    }
};
#endif

/*
    分组打包，两个一组，因为多了一个单一数（奇数个len）
    在最后推入一个数，在分界区之前打包的两个数是一样的，分界区之后
    是相异的
*/
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    nums.push_back(nums.back() + 1);
    int l = 0, r = nums.size() / 2 - 1;
    while (l < r) {
      int mid = l + r >> 1;
      if (nums[mid * 2] != nums[mid * 2 + 1])
        r = mid;
      else
        l = mid + 1;
    }
    return nums[r * 2];
  }
};