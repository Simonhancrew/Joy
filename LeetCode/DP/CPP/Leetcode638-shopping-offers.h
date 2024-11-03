#include <map>
#include <vector>

using namespace std;

/*
  NOTE:
    完全背包，needs是背包里的内容，整体范围较小。因此根据每个special能不能放做dfs就可以
    因为同一类的needs会多次进入，但是结果是相同的，所以做个记忆化
*/

class Solution {
public:
  int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                     vector<int> &needs) {
    int n = price.size();
    map<vector<int>, int> f;
    auto dfs = [&](auto &&dfs, vector<int> cur_need) {
      if (f.count(cur_need)) {
        return f[cur_need];
      }
      int res = 0;
      for (int i = 0; i < n; i++) {
        res += cur_need[i] * price[i];
      }
      for (const auto &sp : special) {
        vector<int> ne_need;
        for (int i = 0; i < n; i++) {
          if (sp[i] > cur_need[i]) {
            break;
          }
          ne_need.push_back(cur_need[i] - sp[i]);
        }
        if (ne_need.size() == n) {
          res = min(res, dfs(dfs, ne_need) + sp[n]);
        }
      }
      return f[cur_need] = res;
    };
    return dfs(dfs, needs);
  }
};
