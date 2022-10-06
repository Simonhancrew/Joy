#include <functional>
#include <numeric>
#include <vector>

using std::accumulate;
using std::function;
using std::vector;

// 要能三等分，首先每个部分的1一定一致，找到每个部分1的首尾
// 针对最后一部分，其尾部的0是固定的，所以其余的两部分，尾部的0应该也是这么多
// 所以，前一部分的最后一个1和后一部分的第一个1之间的距离至少和最后一部分1之后的0数目相等
// 前导零无所谓，然后最后一步要确定这个长度的1是完全一致的

class Solution {
 public:
  vector<int> threeEqualParts(vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (!sum)
      return {0, 2};
    if (sum % 3)
      return {-1, -1};
    int avg  = sum / 3;
    int p[6] = {0}, n = arr.size(),
        s[6] = {1, avg, avg + 1, 2 * avg, 2 * avg + 1, 3 * avg};
    for (int i = 0, c = 0, j = 0; i < n; i++) {
      if (arr[i] == 0)
        continue;
      c++;
      while (j < 6 && s[j] == c)
        p[j++] = i;
    }
    int last0 = n - 1 - p[5];
    int dis1 = p[2] - p[1] - 1, dis2 = p[4] - p[3] - 1;
    if (dis1 < last0 || dis2 < last0)
      return {-1, -1};
    function<bool(int a, int b, int c, int d)> check =
        [&arr, &n](int a, int b, int c, int d) {
          for (int i = a, j = c; i <= b; i++, j++) {
            if (arr[i] != arr[j])
              return false;
          }
          return true;
        };
    if (!check(p[0], p[1] + last0, p[2], p[3] + last0))
      return {-1, -1};
    if (!check(p[2], p[3] + last0, p[4], n - 1))
      return {-1, -1};
    return {p[1] + last0, p[3] + last0 + 1};
  }
};