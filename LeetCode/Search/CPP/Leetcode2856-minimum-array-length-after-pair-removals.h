#if 0
class Solution {
 public:
  int minLengthAfterRemovals(vector<int> &nums) {
    int l = -1, r = nums.size() / 2 + 1;
    int n      = nums.size();
    auto check = [&](int ops) {
      for (int i = ops - 1, j = n - 1; i >= 0; i--, j--) {
        if (nums[j] <= nums[i])
          return false;
      }
      return true;
    };
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    if (l == -1) {
      return nums.size();
    }
    return nums.size() - l * 2;
  }
};
#endif

/*
  NOTE: 找最多的元素x的cnt
  如果2 * cnt > n, 则n - cnt的元素要去消除x，剩下n - 2 * (n - cnt) = 2 * cnt - n
  如果2 * cnt <= n, 则n - cnt的元素可以用来消除x,
  如果是奇数，还会剩下1，是偶数则不剩下什么
  如果一个元素出现的次数超过了一半，nums[nums.size() / 2]一定是这个元素
*/

class Solution {
 public:
  int minLengthAfterRemovals(vector<int> &nums) {
    int tar = nums[nums.size() / 2];
    int cnt = ranges::upper_bound(nums, tar) - ranges::lower_bound(nums, tar);
    return max(2 * cnt - (int)nums.size(), (int)nums.size() % 2);
  }
};