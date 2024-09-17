#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {
    if (source == target) {
      return 0;
    }
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < routes.size(); ++i) {
      for (const auto station : routes[i]) {
        mp[station].push_back(i);
      }
    }
    if (!mp.contains(source) || !mp.contains(target)) {
      return -1;
    }
    queue<int> q;
    unordered_map<int, int> d;
    d[source] = 0;
    q.push(source);
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      auto dis = d[t];
      for (const auto &route_idx : mp[t]) {
        for (const auto x : routes[route_idx]) {
          if (!d.contains(x)) {
            d[x] = dis + 1;
            q.push(x);
          }
        }
        routes[route_idx].clear();
      }
    }
    return d.contains(target) ? d[target] : -1;
  }
};
