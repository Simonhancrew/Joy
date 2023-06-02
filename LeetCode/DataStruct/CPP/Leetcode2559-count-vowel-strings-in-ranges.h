#include <string>
#include <unordered_set>
#include <vector>


using namespace std;

class Solution {
 public:
  vector<int> vowelStrings(vector<string>& words,
                           vector<vector<int>>& queries) {
    int n = words.size();
    vector<int> presum(n + 1);
    unordered_set<char> mp{'a', 'e', 'i', 'o', 'u'};
    auto check = [&mp](const string& c) {
      return mp.count(c.front()) && mp.count(c.back());
    };
    for (int i = 1; i <= n; i++) {
      presum[i] = presum[i - 1] + check(words[i - 1]);
    }
    n = queries.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      auto l = queries[i][0], r = queries[i][1];
      ans[i] = presum[r + 1] - presum[l];
    }
    return ans;
  }
};
