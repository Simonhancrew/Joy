class Solution {
 public:
  int numFriendRequests(vector<int> &ages) {
    int age_cnt[121]{};
    for (const auto age : ages) {
      age_cnt[age]++;
    }
    int l = 1, ans = 0;
    int wnd_size = 0;
    for (int r = 1; r < 121; r++) {
      wnd_size += age_cnt[r];
      if (2 * l <= r + 14) {
        wnd_size -= age_cnt[l];
        ++l;
      }
      if (wnd_size > 0) {
        ans += wnd_size * age_cnt[r] - age_cnt[r];
      }
    }
    return ans;
  }
};
