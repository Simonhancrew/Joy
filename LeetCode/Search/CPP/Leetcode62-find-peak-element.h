#include <vector>

using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    auto check = [&nums](int i) { return nums[i] > nums[i + 1]; };
    while (l < r) {
      int mid = l + r >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
};
