#include <vector>

using namespace std;


// 中间的点 + 考虑左右两边的

class Solution {
 public:
  int maxDistToClosest(vector<int>& seats) {
    int x = -1, y = -1;
    int d = INT_MIN;
    int n = seats.size();
    for (int i = 0; i < n; i++) {
      if (seats[i] == 1) {
        if (y != -1) {
          d = max(d, i - y);
        }
        if (x == -1) {
          x = i;
        }
        y = i;
      }
    }
    return max({x, d / 2, n - 1 - y});
  }
};
