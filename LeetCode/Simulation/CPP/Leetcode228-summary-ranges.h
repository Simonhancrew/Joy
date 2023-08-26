#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j + 1 < n && nums[j + 1] == nums[j] + 1) j++;
      int len = j - i + 1;
      if (len > 1) {
        ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
      } else {
        ans.push_back(to_string(nums[i]));
      }
      i = j;
    }
    return ans;
  }
};
