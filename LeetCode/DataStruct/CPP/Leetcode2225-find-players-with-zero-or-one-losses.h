#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    unordered_map<int, int> mp;
    for (const auto &m : matches) {
      auto x = m[0], y = m[1];
      mp[y]++;
      if (!mp.contains(x)) {
        mp[x] = {};
      }
    }
    vector<vector<int>> ans(2);
    for (const auto &[k, v] : mp) {
      if (v == 0) {
        ans[0].push_back(k);
      } else if (v == 1) {
        ans[1].push_back(k);
      }
    }
    ranges::sort(ans[0]);
    ranges::sort(ans[1]);
    return ans;
  }
};
