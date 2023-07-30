#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 从顶往下做dfs，统计一下当前路径上出现的奇数个数的字符 + 偶数个数的字符
// 要保证回文，所以奇数个字符最多只能有一个
// 技巧就是用二进制表示奇偶，0是偶数，1是奇数，最多26个字母，只需要26位
// 遇到新的节点，做异或就行，这样奇数变成偶数，偶数变成奇数
// 单字母也是回文，所以开始push一个0进去
// 然后就等价在做一个两数之和的题目

class Solution {
 public:
  using LL = long long;
  using PII = pair<int, int>;
  LL ans = 0;
  vector<vector<PII>> g;
  unordered_map<int, int> mp;

  void dfs(int node, int wt) {
    ans += mp[wt];
    for (int i = 0; i <= 25; i++) {
      ans += mp[wt ^ (1 << i)];
    }
    mp[wt] += 1;
    for (const auto& x : g[node]) {
      auto ne = x.first, nwt = wt ^ x.second;
      dfs(ne, nwt);
    }
  }

  long long countPalindromePaths(vector<int>& parent, const string& s) {
    auto n = s.size();
    g.resize(n);
    mp.reserve(n);
    for (auto i = 1; i < parent.size(); i++) {
      g[parent[i]].emplace_back(i, 1 << (s[i] - 'a'));
    }
    dfs(0, 0);
    return ans;
  }
};
