#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 疯狂的馒头, 并查集染色

class Solution {
 public:
  vector<int> idx;
  vector<int> minInterval(vector<vector<int>>& intervals,
                          vector<int>& queries) {
    int n = intervals.size() * 2;

    for (const auto& x : intervals) idx.push_back(x[0]), idx.push_back(x[1]);
    for (const auto x : queries) idx.push_back(x);

    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());

    n = idx.size();

    vector<int> p(n + 1), w(n + 1, -1);
    for (int i = 0; i <= n; i++) p[i] = i;

    auto get = [this](int i) {
      return lower_bound(idx.begin(), idx.end(), i) - idx.begin();
    };

    function<int(int)> find = [&](int x) {
      if (x != p[x]) {
        p[x] = find(p[x]);
      }
      return p[x];
    };

    sort(intervals.begin(), intervals.end(),
         [](const auto& lhs, const auto& rhs) {
           return lhs[1] - lhs[0] < rhs[1] - rhs[0];
         });

    for (const auto& x : intervals) {
      int l = get(x[0]), r = get(x[1]), len = x[1] - x[0] + 1;
      while (find(l) <= r) {
        l = find(l);
        w[l] = len;
        p[l] = l + 1;
      }
    }
    n = queries.size();
    vector<int> ans;
    ans.reserve(n);
    for (const auto x : queries) {
      ans.push_back(w[get(x)]);
    }
    return ans;
  }
};
