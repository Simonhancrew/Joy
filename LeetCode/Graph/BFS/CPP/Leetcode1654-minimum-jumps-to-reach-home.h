#include <cstring>
#include <queue>
#include <utility>

using namespace std;

// 确定最远范围N

class Solution {
 public:
  using PII = pair<int, int>;
  static constexpr int N = 6000;
  static constexpr int INF = 1e8;
  int dist[N][2];
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    memset(dist, -1, sizeof(dist));
    for (const auto f : forbidden) {
      dist[f][0] = dist[f][1] = INF;
    }
    queue<PII> q;
    dist[0][0] = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
      auto t = q.front();
      int d = dist[t.first][t.second];
      int idx = t.first;
      q.pop();
      if (idx == x) {
        return d;
      }
      if (t.first + a < N && dist[t.first + a][0] == -1) {
        dist[t.first + a][0] = d + 1;
        q.emplace(idx + a, 0);
      }
      if (t.second != 1 && idx - b >= 0 && dist[idx - b][1] == -1) {
        dist[idx - b][1] = d + 1;
        q.emplace(idx - b, 1);
      }
    }
    return -1;
  }
};
