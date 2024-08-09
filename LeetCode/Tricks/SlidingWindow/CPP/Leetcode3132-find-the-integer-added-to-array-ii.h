#include <algorithm>
#include <vector>

using namespace std;

// 最小的元素一定在0, 1, 2中产生，最多只能移除2个元素，所以最小元素不会大于2
// 枚举最小元素，判断合法性

class Solution {
public:
  int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2) {
    ranges::sort(nums1);
    ranges::sort(nums2);
    for (int i = 2; i > 0; i--) {
      int diff = nums2[0] - nums1[i];
      int j = 0;
      for (int k = i; k < nums1.size(); k++) {
        if (nums1[k] + diff == nums2[j]) {
          ++j;
        }
        if (j == nums2.size()) {
          return diff;
        }
      }
    }
    return nums2[0] - nums1[0];
  }
};
