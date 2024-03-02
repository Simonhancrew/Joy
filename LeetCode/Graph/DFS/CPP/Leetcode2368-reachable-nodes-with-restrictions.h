#include <functional>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int reachableNodes(int n, vector<vector<int>> &edges,
                     vector<int> &restricted) {
    vector<vector<int>> g(n);
    unordered_set<int> st{restricted.begin(), restricted.end()};
    for (const auto &e : edges) {
      if (st.count(e[0]) || st.count(e[1]))
        continue;
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    function<int(int, int)> dfs = [&dfs, &st, &g](int node, int fa) {
      int ans = 1;
      for (const auto ne : g[node]) {
        if (fa == ne)
          continue;
        ans += dfs(ne, node);
      }
      return ans;
    };
    auto res = dfs(0, -1);
    return res;
  }
};
