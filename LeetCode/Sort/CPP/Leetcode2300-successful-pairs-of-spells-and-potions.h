#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  using LL = long long;
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                              long long success) {
    int n = spells.size(), m = potions.size();
    sort(potions.begin(), potions.end());
    vector<int> ans;
    ans.reserve(n);
    auto check = [&](const LL& x) {
      auto l = 0, r = m - 1;
      while (l < r) {
        int mid = l + r >> 1;
        if (potions[mid] * x >= success)
          r = mid;
        else
          l = mid + 1;
      }
      if (potions[l] * x < success) {
        return 0;
      }
      return m - l;
    };
    for (int i = 0; i < n; i++) {
      ans.push_back(check(spells[i]));
    }
    return ans;
  }
};
