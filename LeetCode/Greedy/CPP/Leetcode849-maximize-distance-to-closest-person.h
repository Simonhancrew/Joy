#include <vector>

using namespace std;

// 要么是左右边界，要么是两个坐了人的中间，看那个距离大。
// 遍历构成中找最大的区间，然后跟左右两个边界区间求最值

class Solution {
 public:
  int maxDistToClosest(vector<int> &seats) {
    int first = -1, last = -1;
    int d = 0;
    int n = seats.size();
    for (int i = 0; i < seats.size(); ++i) {
      if (seats[i] == 1) {
        if (last != -1) {
          d = max(d, i - last);
        }
        last = i;
        if (first == -1) {
          first = i;
        }
      }
    }
    return max({first, n - last - 1, d / 2});
  }
};
