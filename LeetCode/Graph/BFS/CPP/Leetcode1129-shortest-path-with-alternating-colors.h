#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  using PII = pair<int, int>;
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<int> ans(n);
    vector<vector<PII>> edge(n);
    for (const auto& link : redEdges) {
      int s = link[0], e = link[1];
      edge[s].emplace_back(make_pair(e, 0));
    }
    for (const auto& link : blueEdges) {
      int s = link[0], e = link[1];    
      edge[s].emplace_back(make_pair(e, 1));
    }
    queue<PII> q;
    vector<vector<int>> dis(n, vector<int> (2, 0x3f3f3f3f));
    dis[0][0] = dis[0][1] = 0;
    q.push({0, 0}), q.push({0, 1});
    while (q.size()) {
      auto t = q.front();
      q.pop();
      int node = t.first, c = t.second;
      for (auto& ne : edge[node]) {
        if (c != ne.second && dis[ne.first][ne.second] > dis[node][c] + 1) {
          dis[ne.first][ne.second] = dis[node][c] + 1;
          q.push(ne);
        }
      }
    }
    for (int i = 0;i < n;i++) {
      ans[i] = min(dis[i][0], dis[i][1]);
      if (ans[i] == 0x3f3f3f3f) ans[i] = -1;
    }
    return ans;
  }
};

