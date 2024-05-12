#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int minDays(int n) {
    unordered_map<int, int> mp;
    function<int(int)> dfs = [&](int x) -> int {
      if (x <= 1) {
        return x;
      }
      if (mp.contains(x)) {
        return mp[x];
      }
      auto res = 1 + min((x % 2) + dfs(x / 2), (x % 3) + dfs(x / 3));
      mp[x] = res;
      return res;
    };
    return dfs(n);
  }
};
