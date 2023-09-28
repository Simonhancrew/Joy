#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                               vector<int>& people) {
    vector<int> start;
    vector<int> end;
    auto n = flowers.size();
    start.reserve(n), end.reserve(n);
    for (const auto& f : flowers) {
      start.push_back(f[0]);
      end.push_back(f[1]);
    }
    // 到当前时间点t， 所有开过的花 - 已经凋谢的花
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    vector<int> ans;
    auto get = [&start, &end, n](int t) -> int {
      return upper_bound(start.begin(), start.end(), t) - start.begin() -
             (lower_bound(end.begin(), end.end(), t) - end.begin());
    };
    auto Get = [&start, &end, n](int t) -> int {
      int l = 0, r = n - 1;
      // 开花时间小雨等于当前时间
      while (l < r) {
        int mid = l + r + 1 >> 1;
        if (start[mid] <= t)
          l = mid;
        else
          r = mid - 1;
      }
      if (start[l] > t) {
        return 0;
      }
      int all = l;
      // 凋谢时间小于等于当前时间的下界
      l = 0, r = n - 1;
      while (l < r) {
        int mid = l + r >> 1;
        if (end[mid] >= t)
          r = mid;
        else
          l = mid + 1;
      }
      if (end[l] < t) {
        return 0;
      }
      // 区间计数
      return all - l + 1;
    };
    n = people.size();
    ans.reserve(n);
    for (const auto p : people) {
      ans.push_back(get(p));
    }
    return ans;
  }
};
