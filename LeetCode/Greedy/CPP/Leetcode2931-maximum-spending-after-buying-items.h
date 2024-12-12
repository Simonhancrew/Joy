#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  using LL = long long;
  using TI3 = tuple<int, int, int>;
  long long maxSpending(vector<vector<int>> &values) {
    const int n = values.size(), m = values[0].size();
    LL ans = 0;
    priority_queue<TI3, vector<TI3>, greater<>> heap;
    for (int i = 0; i < n; i++) {
      heap.emplace(values[i][m - 1], i, m - 1);
    }
    for (int d = 1; d <= m * n; ++d) {
      auto [val, i, j] = heap.top();
      heap.pop();
      ans += (LL)val * d;
      if (j - 1 >= 0) {
        heap.emplace(values[i][j - 1], i, j - 1);
      }
    }
    return ans;
  }
};
