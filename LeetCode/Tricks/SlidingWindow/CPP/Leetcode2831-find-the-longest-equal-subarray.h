#include <unordered_map>

using namespace std;

class Solution {
public:
  int longestEqualSubarray(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      auto x = nums[i];
      mp[x].push_back(i);
    }
    int ans = 0;
    for (const auto &[_, v] : mp) {
      int l = 0;
      for (int r = 0; r < v.size(); r++) {
        while (v[r] - v[l] - (r - l) > k) {
          ++l;
        }
        ans = max(ans, r - l + 1);
      }
    }
    return ans;
  }
};
