#include <vector>

using namespace std;

class Solution {
 public:
  static constexpr int INF = 0x3f3f3f3f;
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dis(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) dis[i][i] = 0;
    for (const auto& e : edges) {
      dis[e[0]][e[1]] = e[2];
      dis[e[1]][e[0]] = e[2];
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }
    int mn_cnt = INF;
    int idx = 0;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (i != j && dis[i][j] <= distanceThreshold) {
          cnt++;
        }
      }
      if (cnt <= mn_cnt) {
        mn_cnt = cnt;
        idx = i;
      }
    }
    return idx;
  }
};
