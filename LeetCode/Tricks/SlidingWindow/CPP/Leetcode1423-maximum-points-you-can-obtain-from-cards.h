#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// 需要转化一下题目，头尾随机取数最大，等价求剩余的连续子数组和的最小值
// 做一个滑动窗口就可以

class Solution {
 public:
  static int maxScore(vector<int>& cardPoints, int k) {
    auto n = cardPoints.size();
    int tot = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    if (n == k) {
      return tot;
    }
    auto len = n - k;
    int minsum = accumulate(cardPoints.cbegin(), cardPoints.cbegin() + len, 0);
    auto cur = minsum;
    for (auto r = len; r < n; r++) {
      cur += cardPoints[r] - cardPoints[r - len];
      minsum = min(minsum, cur);
    }
    return tot - minsum;
  }
};
