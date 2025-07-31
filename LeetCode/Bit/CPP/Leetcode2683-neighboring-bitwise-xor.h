class Solution {
 public:
  bool doesValidArrayExist(vector<int> &nums) {
    return reduce(nums.begin(), nums.end(), 0, bit_xor()) == 0;
  }
};
