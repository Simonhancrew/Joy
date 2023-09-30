#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// 针对任意growTime，需要流出来的planttime结束时间点至少是x - growTime
// 根据x - growTime从小到大排序，遍历
// 在点i能不能work，要满足小于等于i的点的planttime的累加小于等于当前的x -
// growTime
// x是要知道的量，反过来按照growTime从大到小排序，重复上述累加过程,
// 记录累加值，更新结束时间点max(x, acc + growTime)

class Solution {
 public:
  int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
    int n = growTime.size();
    vector<int> rec(n);
    iota(rec.begin(), rec.end(), 0);
    sort(rec.begin(), rec.end(),
         [&growTime](int l, int r) { return growTime[l] > growTime[r]; });
    int acc{}, ans{};
    for (const auto i : rec) {
      acc += plantTime[i];
      ans = max(ans, acc + growTime[i]);
    }
    return ans;
  }
};