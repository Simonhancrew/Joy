#include <bitset>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int maxPointsInsideSquare(vector<vector<int>> &points, string s) {
    int ans = 0;
    auto check = [&](int size) {
      std::bitset<32> st{};
      int n = points.size();
      for (int i = 0; i < n; ++i) {
        auto &p = points[i];
        if (abs(p[0]) <= size && abs(p[1]) <= size) {
          auto c = s[i] - 'a';
          if (st.test(c)) {
            return false;
          }
          st.set(c);
        }
      }
      ans = st.count();
      return true;
    };
    int l = -1, r = 1e9 + 1;
    while (l + 1 < r) {
      // NOTE: l = -INF, h = INF, l永远合法，h永远不合法
      int mid = (l + r) >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    return ans;
  }
};
