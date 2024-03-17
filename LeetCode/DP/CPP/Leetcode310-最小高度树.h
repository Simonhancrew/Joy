#include <vector>

using namespace std;

// 树形dp模板，针对每个节点找上 and 下的最大深度
// 实现上，自底向上的dfs时，要处理出当前节点的最大/次大深度，并且记录最大深度的fa是谁
// 自顶向下的dfs时，需要算往上走的最大步数，此时有两种可能
// 1. 最大值不能选，因为其父节点的最大值时经过当前节点的
// 2. 最大值可以选
// 最后算出每个节点的最大深度(上/下)，然后取最小做过滤

class Solution {
 public:
  vector<vector<int>> g;
  vector<int> d1, d2, up, p1;

  void dfs1(int u, int fa) {
    for (auto x : g[u]) {
      if (x == fa) continue;
      dfs1(x, u);
      int d = d1[x] + 1;
      if (d >= d1[u]) {
        d2[u] = d1[u], d1[u] = d;
        p1[u] = x;
      } else if (d > d2[u]) {
        d2[u] = d;
      }
    }
  }

  void dfs2(int u, int fa) {
    for (auto x : g[u]) {
      if (x == fa) continue;
      if (p1[u] == x)
        up[x] = max(up[u], d2[u]) + 1;
      else
        up[x] = max(up[u], d1[u]) + 1;
      dfs2(x, u);
    }
  }

  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    g.resize(n);
    d1 = up = p1 = d2 = vector<int>(n, 0);
    for (auto &ed : edges) {
      int a = ed[0], b = ed[1];
      g[a].push_back(b), g[b].push_back(a);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    int mind = n + 1;
    vector<int> res;
    for (int i = 0; i < n; i++) mind = min(mind, max(up[i], d1[i]));
    for (int i = 0; i < n; i++) {
      if (max(up[i], d1[i]) == mind) res.push_back(i);
    }
    return res;
  }
};