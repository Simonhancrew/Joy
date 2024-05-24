#include <vector>

using namespace std;

class Solution {
public:
  static vector<int> mostCompetitive(vector<int> &nums, int k) {
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      while (!ans.empty() && ans.back() > nums[i] &&
             ans.size() + n - i - 1 >= k) {
        ans.pop_back();
      }
      if (ans.size() < k) {
        ans.push_back(nums[i]);
      }
    }
    return ans;
  }
};
