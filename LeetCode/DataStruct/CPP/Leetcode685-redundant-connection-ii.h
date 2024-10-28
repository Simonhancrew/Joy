#include <vector>

/*
  NOTE:
    1. 要么入度有2的，任意选一个，删了看看，是否有环，有环就是答案
    2. 要么入度都是1的，找到第一个有环的边就是答案
*/

using namespace std;

class Solution {
public:
  vector<int> fa;
  int find(int x) {
    if (fa[x] != x)
      fa[x] = find(fa[x]);
    return fa[x];
  }

  void merge(int x, int y) {
    auto fx = find(x);
    auto fy = find(y);
    if (fx != fy) {
      fa[fx] = fa[fy];
    }
  }

  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    fa.resize(n + 1);
    iota(fa.begin(), fa.end(), 0);
    vector<int> in(n + 1);
    for (const auto e : edges) {
      ++in[e[1]];
    }
    vector<int> dup;
    for (int i = 0; i < n; i++) {
      if (in[edges[i][1]] == 2) {
        dup.push_back(i);
      }
    }
    if (!dup.empty()) {
      for (int i = 0; i < n; i++) {
        if (i == dup[1]) {
          continue;
        }
        if (find(edges[i][0]) == find(edges[i][1])) {
          return edges[dup[0]];
        }
        merge(edges[i][0], edges[i][1]);
      }
      return edges[dup[1]];
    }
    for (const auto &e : edges) {
      auto x = e[0], y = e[1];
      if (find(x) == find(y)) {
        return e;
      }
      merge(x, y);
    }
    return {};
  }
};
