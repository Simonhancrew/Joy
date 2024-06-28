#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<unordered_map<int, int>> f;
  vector<int> cost;
  vector<int> time;
  int dfs(int i, int j) {
    if (j > i) {
      return 0;
    }
    if (i < 0) {
      return INT_MAX / 2;
    }
    if (f[i].count(j)) {
      return f[i][j];
    }
    auto &res = f[i][j];
    return res = min(dfs(i - 1, j + time[i]) + cost[i], dfs(i - 1, j - 1));
  }

  int paintWalls(vector<int> &cost, vector<int> &time) {
    int n = cost.size();
    f.resize(n);
    this->cost = std::move(cost);
    this->time = std::move(time);
    return dfs(n - 1, 0);
  }
};
