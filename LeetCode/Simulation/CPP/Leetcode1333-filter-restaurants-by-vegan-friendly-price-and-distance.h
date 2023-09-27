#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  using PII = pair<int, int>;
  vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                int veganFriendly, int maxPrice,
                                int maxDistance) {
    vector<PII> res;
    int n = restaurants.size();
    for (int i = 0; i < n; i++) {
      const auto& x = restaurants[i];
      if (veganFriendly && x[2] != 1) {
        continue;
      }
      if (x[3] > maxPrice || x[4] > maxDistance) {
        continue;
      }
      res.emplace_back(x[0], x[1]);
    }
    sort(res.begin(), res.end(), [](const auto& lhs, const auto& rhs) {
      if (lhs.second != rhs.second) {
        return lhs.second > rhs.second;
      }
      return lhs.first > rhs.first;
    });
    vector<int> ans;
    ans.reserve(res.size());
    for (const auto& x : res) {
      ans.push_back(x.first);
    }
    return ans;
  }
};
