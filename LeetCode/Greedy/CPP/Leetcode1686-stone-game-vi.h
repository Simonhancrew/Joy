#include <algorithm>
#include <ranges>
#include <vector>

using namespace std;

// 假设bob全拿，alice拿第i个，则最后A = a[i], B = tot - b[i]
// 要让add_diff最大 = add_on(A - B) -> 让a[i] + b[i]最大化，所以可以对合排序
// alice和bob都选择对自己最好的一手

class Solution {
public:
  using PII = pair<int, int>;
  int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {
    vector<PII> rec;
    int n = aliceValues.size();
    rec.reserve(n);
    for (int i = 0; i < n; i++) {
      rec.emplace_back(aliceValues[i], bobValues[i]);
    }
    ranges::sort(rec, [](auto &lhs, auto rhs) {
      return lhs.first + lhs.second > rhs.first + rhs.second;
    });
    auto diff = 0;
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        diff -= rec[i].second;
        continue;
      }
      diff += rec[i].first;
    }
    return (diff > 0) - (diff < 0);
  }
};
