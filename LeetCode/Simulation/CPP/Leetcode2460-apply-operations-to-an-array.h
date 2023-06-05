#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> applyOperations(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i + 1 < n && nums[i] == nums[i + 1]) {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) continue;
      nums[j++] = nums[i];
    }
    for (; j < n; j++) nums[j] = 0;
    return nums;
  }
};
