#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 分情况了，按照字母分组，每个组里最长长度len[0]，次长长度，还有len[3]
// 可以形成的3次的就三种情况，len[0]里构造，最大len[0] - 2
// len[1] + len[0]里构造，相等和不相等分别考虑，综合min(a[0] - 1, a[1])
// 还有一种就取len[3]的长度

class Solution {
public:
  static int maximumLength(string s) {
    vector<int> group[26];
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      ++cnt;
      if (i + 1 == n || s[i] != s[i + 1]) {
        group[s[i] - 'a'].push_back(cnt);
        cnt = 0;
      }
    }
    int ans = 0;
    for (auto &x : group) {
      if (x.empty())
        continue;
      ranges::sort(x, [](auto lhs, auto rhs) { return lhs > rhs; });
      x.push_back(0);
      x.push_back(0);
      ans = max({ans, x[0] - 2, min(x[0] - 1, x[1]), x[2]});
    }
    return ans == 0 ? -1 : ans;
  }
};
