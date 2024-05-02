#include <numeric>
#include <queue>
#include <vector>

using namespace std;

// 同组同比例发，单quality的价值是一致的，所以最大的比值满足了，小的也满足，所以只需要考虑最大的比值,
// 排序
// 最大的quality价值确定后，要让k个的quality和最小，因此要维护k个最小的quality，所以用大顶堆
// 遍历的时候更新

class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
    int n = quality.size();
    double ans{};
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0);
    ranges::sort(arr, [&](int i, int j) {
      return quality[j] * wage[i] < quality[i] * wage[j];
    });
    priority_queue<int> heap;
    int sum = 0;
    for (int i = 0; i < k; i++) {
      sum += quality[arr[i]];
      heap.push(quality[arr[i]]);
    }
    ans = sum * (double)(wage[arr[k - 1]]) / quality[arr[k - 1]];
    for (int i = k; i < n; i++) {
      auto cur = quality[arr[i]];
      if (cur < heap.top()) {
        auto pre = heap.top();
        heap.pop();
        heap.push(cur);
        sum += cur - pre;
        ans = min(ans, sum * (double)(wage[arr[i]]) / cur);
      }
    }
    return ans;
  }
};
