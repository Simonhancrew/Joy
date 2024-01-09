#include <functional>
#include <string>
#include <unordered_set>
#include <vector>


using namespace std;

class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {
    unordered_set<string> st;
    size_t min_len = INT_MAX;
    for (const auto &x : dictionary) {
      st.insert(x);
      min_len = min(min_len, x.size());
    }
    int n = s.size();
    vector<int> f(n, -1);
    function<int(int)> dfs = [&](int idx) {
      if (idx < 0) {
        return 0;
      }
      if (f[idx] != -1) {
        return f[idx];
      }
      int res = dfs(idx - 1) + 1;
      for (int i = 0, len = idx + 1; i <= idx && len >= min_len; i++) {
        auto cur = s.substr(i, idx - i + 1);
        if (st.count(cur)) {
          res = min(res, dfs(i - 1));
        }
      }
      return f[idx] = res;
    };
    return dfs(n - 1);
  }
};
