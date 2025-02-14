/*
NOTE:
  最大值最小，先考虑下二分。
  直接二分最小值，排序position,
如果能按照这个值放置m个球，那么就可以继续增大这个值，否则减小这个值。
  最后直接返回l即可。
*/
class Solution {
 public:
  int maxDistance(vector<int> &position, int m) {
    sort(position.begin(), position.end());
    int l = 0, r = (position.back() - position.front()) / (m - 1) + 1;
    auto f = [&](int x) {
      int cnt = 1, pre = position[0];
      for (int i = 1; i < position.size(); i++) {
        if (position[i] - pre >= x) {
          pre = position[i];
          cnt++;
        }
      }
      return cnt;
    };
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (f(mid) >= m)
        l = mid;
      else
        r = mid;
    }
    return l;
  }
};
