class Solution {
 public:
  int maxFreeTime(int eventTime, int k, vector<int> &startTime,
                  vector<int> &endTime) {
    int n    = startTime.size();
    auto get = [&](int i) {
      if (i == 0) {
        return startTime[0];
      }
      if (i == n) {
        return eventTime - endTime.back();
      }
      return startTime[i] - endTime[i - 1];
    };
    int ans = 0, tmp = 0;
    for (int i = 0; i <= n; ++i) {
      tmp += get(i);
      if (i < k) {
        continue;
      }
      ans = max(ans, tmp);
      tmp -= get(i - k);
    }
    return ans;
  }
};
