#include <string>

using namespace std;

class Solution {
 public:
  static constexpr int mod = 1e9 + 7;
  string rec;
  int f[110][10];
  int dfs(int pos, int pre, bool lead, bool limit) {
    if (!pos) {
      return !lead;
    }
    if (!lead && !limit && f[pos][pre] != -1) return f[pos][pre];
    int up = limit ? rec[pos - 1] - '0' : 9;
    int res = 0;
    for (int i = 0; i <= up; i++) {
      if (lead || abs(i - pre) == 1) {
        res = (res + dfs(pos - 1, i, lead && !i, limit && i == up)) % mod;
      }
    }
    if (!lead && !limit) {
      f[pos][pre] = res;
    }
    return res;
  }

  int solve(const string s) {
    rec = std::move(s);
    reverse(rec.begin(), rec.end());
    int n = rec.size();
    return dfs(n, 0, 1, 1);
  }

  int check(const std::string& s) {
    int n = s.size();
    for (int i = 1; i < n; i++) {
      if (abs(s[i] - s[i - 1]) != 1) return false;
    }
    return true;
  }

  int countSteppingNumbers(string low, string high) {
    memset(f, -1, sizeof f);
    return (solve(high) - solve(low) + mod + check(low)) % mod;
  }
};
