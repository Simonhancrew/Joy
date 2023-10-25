#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  bool dfs(int id, int sum, int remain, const string& s) {
    if (sum > remain) {
      return false;
    }

    if (id == s.size()) {
      return sum == remain;
    }

    if (dfs(id + 1, sum * 10 + s[id] - '0', remain, s)) {
      return true;
    }
    return dfs(id + 1, s[id] - '0', remain - sum, s);
  }

  bool check(int x) {
    auto s = to_string(x * x);
    return dfs(0, 0, x, s);
  }

  int punishmentNumber(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (check(i)) {
        ans += i * i;
      }
    }
    return ans;
  }
};
