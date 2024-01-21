#include <vector>

using namespace std;

// 最大值最小，考虑二分
// 二分考虑当前最值，是否可行，因为要连续的，所以顺序贪心划分就可了

class Solution {
public:
  using LL = int;
  int splitArray(vector<int> &nums, int k) {
    int n = nums.size();
    LL l = 0, r = 0;
    for (const auto x : nums) {
      r += x;
      if (l < x) {
        l = x;
      }
    }
    auto check = [&nums, k](LL mx) {
      LL cnt = 1;
      LL acc = 0;
      for (const auto x : nums) {
        if (acc + x > mx) {
          acc = x;
          cnt++;
        } else {
          acc += x;
        }
      }
      return cnt <= k;
    };
    l = l - 1, r = r + 1;
    while (l + 1 < r) {
      LL mid = (l + r) >> 1;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return l + 1;
  }
};
