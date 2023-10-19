#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        mp[nums[i] * nums[j]]++;
      }
    }
    int ans = 0;
    for (const auto& [k, v] : mp) {
      // C(n, 1) * C(n - 1, 1) * C(2, 1) * C(2, 1)
      ans += v * (v - 1) * 4;
    }
    return ans;
  }
};
