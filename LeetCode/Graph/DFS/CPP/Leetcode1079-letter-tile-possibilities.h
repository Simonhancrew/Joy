#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numTilePossibilities(string tiles) {
    unordered_map<char, int> mp;
    int n = tiles.size();
    for (const auto c : tiles) mp[c]++;
    std::function<int(int)> dfs = [&](int idx) {
      int res = 1;
      if (idx == n) {
        return res;
      }
      for (auto& [k, v] : mp) {
        if (v > 0) {
          v -= 1;
          res += dfs(idx + 1);
          v += 1;
        }
      }
      return res;
    };
    return dfs(0) - 1;
  }
};
