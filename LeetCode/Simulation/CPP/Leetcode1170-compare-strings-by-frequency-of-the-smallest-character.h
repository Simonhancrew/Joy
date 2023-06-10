#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> numSmallerByFrequency(vector<string>& queries,
                                    vector<string>& words) {
    int n = queries.size(), m = words.size();
    vector<int> ans(n), f(m);
    auto get = [m](const auto& x) {
      char mn = x.front();
      unordered_map<int, int> mp;
      for (const auto y : x) {
        if (mn > y) mn = y;
        mp[y]++;
      }
      return mp[mn];
    };
    for (int i = 0; i < m; i++) {
      f[i] = get(words[i]);
    }
    auto check = [&](int idx) {
      auto cur = get(queries[idx]);
      int res = 0;
      for (const auto x : f) {
        if (cur < x) ++res;
      }
      return res;
    };
    for (int i = 0; i < n; i++) {
      ans[i] = check(i);
    }
    return ans;
  }
};
