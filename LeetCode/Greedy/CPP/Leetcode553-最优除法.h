/*
    加括号就是将后续的除法改成乘法，已知所有的数都是正数
    所以直接给第一个数后面的整数全部加括号就可以了
*/
class Solution {
 public:
  string optimalDivision(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return "";
    if (n == 1) return to_string(nums[0]);
    if (n == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);
    string ans = to_string(nums[0]) + "/(";
    for (int i = 1; i < n - 1; i++) {
      ans += to_string(nums[i]) + '/';
    }
    ans += to_string(nums[n - 1]) + ')';
    return ans;
  }
};