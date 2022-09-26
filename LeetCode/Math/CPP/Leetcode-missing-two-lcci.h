class Solution {
public:
  vector<int> missingTwo(vector<int>& nums) {
    int acc = 0, n = nums.size() + 2;
    for(auto &num : nums) {
      acc ^= num;
    }
    for(int i = 1;i <= n;i++) {
      acc ^= i;
    }
    int lowbit = acc & (-acc);
    vector<int> ans(2,0);
    for(auto &num : nums) {
      if(num & lowbit) {
        ans[0] ^= num;
      }else {
        ans[1] ^= num;
      }
    }
    for(int i = 1;i <= n;i++) {
      if(i & lowbit) {
        ans[0] ^= i;
      }else {
        ans[1] ^= i;
      }
    }
    return ans;
  }   
};
