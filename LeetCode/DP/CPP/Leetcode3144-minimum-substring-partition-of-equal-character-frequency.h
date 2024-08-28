#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 判断每个key的val都一样-> key_size * max_val == i - j + 1

class Solution {
public:
  static constexpr int INF = 0x3f3f3f3f;
  int minimumSubstringsInPartition(string s) {
    int n = s.size();
    vector<int> f(n, INF);
    auto dfs = [&](auto &&dfs, int i) {
      if (i < 0) {
        return 0;
      }
      auto &res = f[i];
      if (res != INF) {
        return res;
      }
      int mx_cnt = 0;
      unordered_map<char, int> mp;
      for (int j = i; j >= 0; j--) {
        mp[s[j]]++;
        mx_cnt = max(mx_cnt, mp[s[j]]);
        if (i - j + 1 == mx_cnt * mp.size()) {
          res = min(res, dfs(dfs, j - 1) + 1);
        }
      }
      return res;
    };
    return dfs(dfs, n - 1);
  }
};
