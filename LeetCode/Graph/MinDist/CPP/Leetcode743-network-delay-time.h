#include <queue>
#include <vector>


using namespace std;

class Solution {
 public:
  using PII = pair<int, int>;
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<PII>> g(n + 1);
    for (const auto &time : times) {
      int x = time[0], y = time[1], w = time[2];
      g[x].emplace_back(y, w);
    }
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.emplace(0, k);
    while (!heap.empty()) {
      auto [d, node] = heap.top();
      heap.pop();
      if (d > dist[node])
        continue;
      for (const auto [ne, w] : g[node]) {
        if (dist[ne] > dist[node] + w) {
          dist[ne] = dist[node] + w;
          heap.emplace(dist[ne], ne);
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int x = dist[i];
      if (x == INT_MAX)
        return -1;
      ans = max(ans, x);
    }
    return ans;
  }
};
