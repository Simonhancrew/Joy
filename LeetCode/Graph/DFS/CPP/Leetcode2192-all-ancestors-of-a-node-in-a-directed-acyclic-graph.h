#include <functional>
#include <set>
#include <vector>


using namespace std;

class Solution {
public:
  static vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> g(n, vector<int>());
    for (const auto &e : edges) {
      g[e[1]].push_back(e[0]);
    }
    vector<uint8_t> st(n, 0);
    vector<set<int>> res(n);
    function<void(int idx)> dfs = [&](int id) {
      auto &cur = res[id];
      for (const auto ne : g[id]) {
        cur.insert(ne);
        if (st[ne] != 0) {
          cur.insert(res[ne].begin(), res[ne].end());
          continue;
        }
        dfs(ne);
        cur.insert(res[ne].begin(), res[ne].end());
      }
      st[id] = 1;
    };
    for (int i = 0; i < n; i++) {
      if (st[i] != 0) {
        continue;
      }
      dfs(i);
    }
    vector<vector<int>> ans;
    ans.reserve(n);
    for (const auto &x : res) {
      ans.emplace_back(x.begin(), x.end());
    }
    return ans;
  }
};
