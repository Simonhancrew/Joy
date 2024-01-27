#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  using LL = long long;
  int maxNumberOfAlloys(int n, int k, int budget,
                        vector<vector<int>> &composition, vector<int> &stock,
                        vector<int> &cost) {
    int ans = 0;
    int mx = budget + ranges::min(stock);
    for (const auto com : composition) {
      auto check = [&](int num) {
        LL money = 0;
        for (int i = 0; i < n; i++) {
          if (stock[i] < (LL)com[i] * num) {
            money += ((LL)com[i] * num - stock[i]) * cost[i];
            if (money > budget) {
              return false;
            }
          }
        }
        return true;
      };
      int l = ans, r = mx + 1;
      while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
          l = mid;
        } else {
          r = mid;
        }
      }
      ans = l;
    }
    return ans;
  }
};
