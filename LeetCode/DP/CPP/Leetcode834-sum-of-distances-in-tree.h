#include <vector>

using namespace std;

// 树上dp，先明确一点，正常dfs是从下往上的，因此比较好算当前节点往下的距离是多少
// 父节点a到子节点b的通路是唯一的，子节点b到其下方的叶子节点路径也是唯一的，做一次+法就可以
// 随后，需要做一个从上往下的dfs，计算过程在递归之前，求取上方的距离
// 只要把下方算的距离减去就可以了

class Solution {
 public:
  vector<int> up, down, cnt;
  vector<vector<int>> g;
  int n;

  void dfs_d(int cur, int pre) {
    for (const auto ne : g[cur]) {
      if (ne == pre) continue;
      dfs_d(ne, cur);
      down[cur] += down[ne] + cnt[ne];
      cnt[cur] += cnt[ne];
    }
  }

  void dfs_u(int cur, int pre) {
    for (const auto ne : g[cur]) {
      if (ne == pre) continue;
      up[ne] = up[cur] + down[cur] - (down[ne] + cnt[ne]) + n - cnt[ne];
      dfs_u(ne, cur);
    }
  }

  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    g.resize(n);
    this->n = n;
    for (const auto& x : edges) {
      g[x[0]].push_back(x[1]);
      g[x[1]].push_back(x[0]);
    }
    up.resize(n), down.resize(n), cnt.resize(n, 1);
    dfs_d(0, -1);
    dfs_u(0, -1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = up[i] + down[i];
    }
    return ans;
  }
};
