#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  using PII = pair<int, int>;
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    unordered_map<int, unordered_set<int>> mp;
    for (const auto& x : obstacles) {
      mp[x[0]].insert(x[1]);
    }
    int d = 0, ans = 0;
    int x = 0, y = 0;
    for (const auto p : commands) {
      if (p == -1)
        d = (d + 1) % 4;
      else if (p == -2)
        d = (d + 3) % 4;
      else {
        for (int i = 0; i < p; i++) {
          int nx = x + dx[d], ny = y + dy[d];
          if (mp[nx].count(ny)) break;
          ans = max(ans, nx * nx + ny * ny);
          x = nx, y = ny;
        }
      }
    }
    return ans;
  }
};
