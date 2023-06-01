#include <vector>

using namespace std;

// 最大值最小比较天然的能想到二分， 先sort数组
// 发现只要按照最小的diff来做判断就行了，排序后的两个相邻元素的diff一定相对最优
// 能够满足这个diff说明可能可以找到更大的，收缩下边界

class Solution {
 public:
  int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(), price.end());
    int l = 0, r = price.back() - price.front();
    int n = price.size();
    auto check = [&](int diff) {
      int cnt = 1, num = price[0];
      for (int i = 1; i < n; i++) {
        if (price[i] - num >= diff) {
          ++cnt;
          num = price[i];
        }
        if (cnt >= k) return true;
      }
      return false;
    };
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }
};
