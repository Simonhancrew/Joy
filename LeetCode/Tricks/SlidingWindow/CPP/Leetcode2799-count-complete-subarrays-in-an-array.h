#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int countCompleteSubarrays(vector<int> &nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int tot = st.size();
    int l = 0, ans = 0;
    unordered_map<int, int> mp;
    for (int r = 0; r < nums.size(); ++r) {
      mp[nums[r]]++;
      while (mp.size() == tot) {
        int tar = mp[nums[l]];
        if (--mp[nums[l]] == 0) {
          mp.erase(nums[l]);
        }
        ++l;
      }
      ans += l;
    }
    return ans;
  }
};
