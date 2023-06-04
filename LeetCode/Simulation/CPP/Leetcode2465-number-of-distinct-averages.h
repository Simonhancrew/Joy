#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int distinctAverages(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    unordered_set<double> st;
    while (i <= j) {
      auto mid = (nums[i++] + nums[j--]) / 2.0;
      st.insert(mid);
    }
    return st.size();
  }
};
