#include <vector>

using namespace std;
/*
    需要推一个公式，不得分的部分
    1. i - a[i] < 0是不得分的，经过k次调度这个公式变为i - a[i] - k < 0
    既可以得到k的下界，k >= i - a[i] + 1
    2. 同理，i - k >= 0，k <= i.
    以上运算都是针对取模的 => k MOD n
    然后标记这些不得分的区间，最后看看那个点是最小的
    +-1一个区间可以用差分
*/
class Solution {
 public:
  int bestRotation(vector<int> &nums) {
    int n = nums.size();
    vector<int> b(n + 1);
    for (int i = 0; i < n; i++) {
      int l = i - nums[i] + 1, r = i;
      if (l >= 0)
        b[l]++, b[r + 1]--;
      else {
        b[0]++, b[r + 1]--;
        b[l + n]++, b[n]--;
      }
    }
    int res = INT_MAX, k = -1;
    for (int i = 0, sum = 0; i < n; i++) {
      sum += b[i];
      if (res > sum) {
        res = sum;
        k = i;
      }
    }
    return k;
  }
};