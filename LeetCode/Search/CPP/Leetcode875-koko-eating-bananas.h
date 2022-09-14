class Solution {
 public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1, r = *max_element(piles.begin(), piles.end());
    auto check = [&](int k) {
      int cnt = 0;
      for (auto pile : piles) {
        if (pile <= k)
          cnt++;
        else
          cnt += (pile + k - 1) / k;
      }
      return cnt <= h;
    };
    while (l < r) {
      int mid = l + r >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
};