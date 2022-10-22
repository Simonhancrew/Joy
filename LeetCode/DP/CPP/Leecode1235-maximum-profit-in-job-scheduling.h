#include <vector>
#include <algorithm>

using namespace std;

// 线性dp + 二分。
// 首先按照结束时间将整体排序,f[i]表示前i个item的最大利润
// 针对i，有选和不选两种可能，分别讨论，选的时候，只要前面的item的右边界
// 是小于当前i的左边界的就可以选择。这里可以用二分找到之前右边界小于等于i左边界的j
// f[i] = max(f[i], f[j] + arr[i].profit),
// 其中i初始化f[i] = max(f[i - 1], arr[i].profit)
class Solution {
 public:
  struct Item {
    int l, r, p;
    Item(int l, int r, int p) : l(l), r(r), p(p) {}
  };
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    const int n = startTime.size();
    vector<Item> arr;
    for (int i = 0; i < startTime.size(); i++) {
      arr.emplace_back(startTime[i], endTime[i], profit[i]);
    }
    sort(arr.begin(), arr.end(), [](const auto& lhs, const auto& rhs) { return lhs.r < rhs.r; });
    vector<int> f(n);
    f[0] = arr[0].p;
    for (int i = 1; i < n; i++) {
      f[i] = max(f[i - 1], arr[i].p);
      if (arr[0].r <= arr[i].l) {
        int l = 0, r = i - 1;
        while (l < r) {
          int mid = l + r + 1 >> 1;
          if (arr[mid].r <= arr[i].l)
            l = mid;
          else
            r = mid - 1;
        }
        f[i] = max(f[i], f[r] + arr[i].p);
      }
    }
    return f[n - 1];
  }
};