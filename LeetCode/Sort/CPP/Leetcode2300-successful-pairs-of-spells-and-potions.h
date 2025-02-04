#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  using LL = long long;
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    ranges::sort(potions.begin(), potions.end());
    vector<int> res;
    res.reserve(spells.size());
    auto get = [&](int x) -> int {
      int l = -1, r = potions.size();
      while (l + 1 < r) {
        int mid = l + r >> 1;
        if ((LL)x * potions[mid] < success)
          l = mid;
        else
          r = mid;
      }
      if (r == potions.size()) {
        return 0;
      }
      return potions.size() - r;
    };
    for (const auto x : spells) {
      res.push_back(get(x));
    }
    return res;
  }
};
