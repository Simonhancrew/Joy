#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

// 算每条路的最小花费，在这个花费上除以seats就是这条路要花费的油费
// 然后对路最累加，一个dfs，处理子树节点数目，然后除以seats就是这个子树上行边的油费

class Solution {
 public:
  using LL = long long;
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    LL ans = 0;
    unordered_map<int, vector<int>> edge;
    for (const auto& p : roads) {
      auto x = p[0], y = p[1];
      edge[x].push_back(y);
      edge[y].push_back(x);
    }
    function<LL(int, int)> dfs = [&](int x, int fa) {
      if (fa == x) {
        return 0;
      }
      auto size = 1;
      for (const auto y : edge[x]) {
        if (y == fa) continue;
        size += dfs(y, x);
      }
      if (x != 0) {
        ans += (size + seats - 1) / seats;
      }
      return size;
    };
    dfs(0, -1);
    return ans;
  }
};
