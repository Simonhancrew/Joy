#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  using LL = long long;
  long long totalCost(vector<int> &costs, int k, int candidates) {
    int n = costs.size();
    // 一定能选到k个最小的，完全覆盖
    if (n - k < 2 * candidates) {
      nth_element(costs.begin(), costs.begin() + k, costs.end());
      return accumulate(costs.begin(), costs.begin() + k, 0ll);
    }
    LL ans{};
    auto cmp = [](int l, int r) { return l > r; };
    priority_queue<int, vector<int>, decltype(cmp)> lhs(cmp), rhs(cmp);
    for (int i = 0; i < candidates; i++) {
      lhs.push(costs[i]);
      rhs.push(costs[n - 1 - i]);
    }
    // 不能完全覆盖，去掉k个时候，左右candidates都不会越界
    int i = candidates, j = n - 1 - candidates;
    while (k--) {
      if (lhs.top() <= rhs.top()) {
        auto cur = lhs.top();
        lhs.pop();
        ans += cur;
        lhs.push(costs[i++]);
      } else {
        auto cur = rhs.top();
        rhs.pop();
        ans += cur;
        rhs.push(costs[j--]);
      }
    }
    return ans;
  }
};
