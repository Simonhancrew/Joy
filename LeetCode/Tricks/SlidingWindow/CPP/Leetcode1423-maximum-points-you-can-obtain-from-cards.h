#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// 需要转化一下题目，头尾随机取数最大，等价求剩余的连续子数组和的最小值
// 做一个滑动窗口就可以

class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k) {
    int n = cardPoints.size();
    int tot = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    int m = n - k;
    if (m == 0) {
      return tot;
    }
    int acc = 0, tar = INT_MAX;
    for (int i = 0; i < n; i++) {
      acc += cardPoints[i];
      if (i < m - 1)
        continue;
      tar = min(tar, acc);
      acc -= cardPoints[i - m + 1];
    }
    return tot - tar;
  }
};
