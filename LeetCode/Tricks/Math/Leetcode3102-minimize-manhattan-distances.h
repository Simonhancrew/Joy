#include <algorithm>
#include <set>
#include <vector>

using namespace std;

// 曼哈顿转切比雪夫距离的技巧，绕原点旋转90度之后扩大根号2倍

class Solution {
public:
  int minimumDistance(vector<vector<int>> &points) {
    multiset<int> sx, sy;
    for (const auto &p : points) {
      sx.insert(p[0] + p[1]);
      sy.insert(p[0] - p[1]);
    }
    int ans = INT_MAX;
    for (const auto &p : points) {
      int x = p[0] + p[1];
      int y = p[0] - p[1];
      sx.erase(sx.find(x));
      sy.erase(sy.find(y));
      auto dx = *sx.rbegin() - *sx.begin();
      auto dy = *sy.rbegin() - *sy.begin();
      ans = min(ans, max(dx, dy));
      sx.insert(x);
      sy.insert(y);
    }
    return ans;
  }
};
