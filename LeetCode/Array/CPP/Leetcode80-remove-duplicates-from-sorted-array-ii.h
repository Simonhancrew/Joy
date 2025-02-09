/*
  NOTE:
    一个stack，当前数不能等于栈顶的前一个数，否则就是重复的数
*/
class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    int n          = nums.size();
    int stack_size = 2;
    for (int i = 2; i < n; i++) {
      if (nums[i] != nums[stack_size - 2]) {
        nums[stack_size++] = nums[i];
      }
    }
    return min(stack_size, n);
  }
};
