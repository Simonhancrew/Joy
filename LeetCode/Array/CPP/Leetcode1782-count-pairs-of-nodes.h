#include <algorithm>
#include <map>
#include <vector>

using namespace std;

// 统计合标准的，先不考虑去除重复，做一个同向双指针
// 统计重边，如果重边在统计中，去除掉

class Solution {
 public:
  static vector<int> countPairs(int n, vector<vector<int>>& edges,
                                vector<int>& queries) {
    vector<int> deg(n + 1);
    map<pair<int, int>, int> mp;
    for (const auto& e : edges) {
      int x = e[0];
      int y = e[1];
      if (x > y) swap(x, y);
      deg[x]++;
      deg[y]++;
      mp[{x, y}]++;
    }
    auto m = queries.size();
    vector<int> ans(m);
    auto sort_deg = deg;
    sort(sort_deg.begin(), sort_deg.end());
    for (int i = 0; i < m; i++) {
      int l = 1;
      int r = n;
      int x = queries[i];
      while (l < r) {
        if (sort_deg[l] + sort_deg[r] <= x) {
          l++;
        } else {
          ans[i] += r - l;
          r--;
        }
      }
      for (const auto& [k, v] : mp) {
        auto sum = deg[k.first] + deg[k.second];
        if (sum > x && sum <= x + v) {
          ans[i]--;
        }
      }
    }
    return ans;
  }
};
