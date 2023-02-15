class Solution {
 public:
  int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
  bool isGoodArray(vector<int>& nums) {
    int base = nums[0];
    for (int i = 0; i < nums.size(); i++) {
      base = gcd(base, nums[i]);
      if (base == 1) {
        break;
      }
    }
    return base == 1;
  }
};