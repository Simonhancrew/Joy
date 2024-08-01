#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int maxmiumScore(vector<int> &cards, int cnt) {
    if (cnt > cards.size()) {
      return 0;
    }
    vector<int> a{0}, b{0};
    for (const auto x : cards) {
      if (x & 1)
        a.push_back(x);
      else
        b.push_back(x);
    }
    ranges::sort(a);
    ranges::sort(b);
    partial_sum(a.begin(), a.end(), a.begin());
    partial_sum(b.begin(), b.end(), b.begin());
    int n = b.size(), m = a.size();
    int ans = 0, limit = min(cnt, n);
    for (int i = 0; i <= limit; i++) {
      int j = cnt - i;
      if (a.size() - 1 < j || b.size() - 1 < i || j % 2 != 0) {
        continue;
      }
      int cur = 0;
      if (i > 0) {
        cur = b[n - 1] - (i == n ? 0 : b[n - 1 - i]);
      }
      if (j > 0) {
        cur += a[m - 1] - (j == m ? 0 : a[m - 1 - j]);
      }
      ans = max(ans, cur);
    }
    return ans;
  }
};
