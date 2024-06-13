#include <algorithm>
#include <stack>
#include <unordered_set>


using namespace std;

// 子序列选择 + 求取值最大问题，顺序无关
// 我们先贪心的选择profit最大的k个值，后面再让catgory变大
// 这里自然想到要按照profit递减排序
// 然后在后面遍历到k之后的item时，total profit一定是变小的，因此要尝试让total
// category变大
// 此时自然想到优先把重复category的最小的profit的item给置换掉，如果有新的category的话
// 因此在遍历中要记录一个重复category的最小值，因为已经是profit逆序了，所以拿stack记录就可以了
// 最后求取最大值

class Solution {
public:
  using LL = long long;
  long long findMaximumElegance(vector<vector<int>> &items, int k) {
    int n = items.size();
    ranges::sort(items,
                 [](const auto &l, const auto &r) { return l[0] > r[0]; });
    unordered_set<int> vis;
    LL ans{};
    LL total_profit = 0;
    stack<int> dup;
    for (int i = 0; i < n; i++) {
      int profit = items[i][0], category = items[i][1];
      if (i < k) {
        total_profit += profit;
        if (!vis.insert(category).second) {
          dup.push(profit);
        }
      } else if (!dup.empty() && vis.insert(category).second) {
        total_profit += profit - dup.top();
        dup.pop();
      }
      ans = max(ans, total_profit + (LL)vis.size() * (LL)vis.size());
    }
    return ans;
  }
};
