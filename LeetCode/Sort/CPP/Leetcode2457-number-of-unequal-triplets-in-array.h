#include <vector>

using namespace std;

class Solution {
 public:
  int unequalTriplets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), res = 0;
    for (int i = 0, j = 0; i < n; i = j) {
      while (j < n && nums[i] == nums[j]) {
        j++;
      }
      res += i * (j - i) * (n - j);
    }
    return res;
  }
};
