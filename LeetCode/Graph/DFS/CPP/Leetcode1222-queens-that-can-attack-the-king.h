#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  static vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                          vector<int>& king) {
    vector<vector<int>> ans;
    int x = king[0], y = king[1];
    unordered_map<int, unordered_set<int>> mp;
    for (const auto& q : queens) {
      int x = q[0], y = q[1];
      mp[x].insert(y);
    }
    function<void(int x, int y, int dx, int dy)> dfs = [&](int x, int y, int dx,
                                                           int dy) {
      if (mp[x].count(y)) {
        ans.push_back({x, y});
        return;
      }
      int nx = x + dx, ny = y + dy;
      if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
        dfs(nx, ny, dx, dy);
      }
    };
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) continue;
        dfs(x, y, i, j);
      }
    }
    return ans;
  }
};
