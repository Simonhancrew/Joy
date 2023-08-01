#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int countCompleteSubarrays(vector<int>& nums) {
    unordered_set<int> st;
    for (const auto x : nums) {
      st.insert(x);
    }
    int n = nums.size();
    int m = st.size();
    int ans = 0;
    unordered_map<int, int> mp;
    for (int l = 0, r = 0; l <= n - m; l++) {
      while (r < n && mp.size() < m) {
        mp[nums[r++]]++;
      }
      if (mp.size() == m) {
        ans += n - r + 1;
      }
      mp[nums[l]]--;
      if (mp[nums[l]] == 0) {
        mp.erase(nums[l]);
      }
    }
    return ans;
  }
};
