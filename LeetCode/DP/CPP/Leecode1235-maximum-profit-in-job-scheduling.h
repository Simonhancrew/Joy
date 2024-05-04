#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// 因为要不交叠，天然想到按照终点排序然后遍历每个点
// 针对每一个点，选/不选，选的话，前面一个要不交叠
// 所以前面能选的点要满足endTime[j] <= startTime[i],
// i是要选的点，j是前面能选的最大的点，这个二分就可以
// 因此满足一个递推的步骤，f[i] = max(f[i-1], f[j] + profit[i])

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    int n = startTime.size();
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0);
    ranges::sort(arr, [&](int l, int r) { return endTime[l] < endTime[r]; });
    vector<int> f(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int l = -1, r = i + 1;
      while (l + 1 < r) {
        auto mid = (l + r) >> 1;
        if (endTime[arr[mid]] <= startTime[arr[i]])
          l = mid;
        else
          r = mid;
      }
      auto j = l;
      f[i + 1] = max(f[i], f[j + 1] + profit[arr[i]]);
    }
    return f[n];
  }
};
