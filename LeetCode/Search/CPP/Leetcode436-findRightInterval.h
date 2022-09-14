class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    int n = intervals.size();
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) intervals[i].push_back(i);
    sort(intervals.begin(), intervals.end());
    for (auto &x : intervals) {
      int l = 0, r = n - 1;
      while (l < r) {
        int mid = l + r >> 1;
        if (intervals[mid][0] >= x[1])
          r = mid;
        else
          l = mid + 1;
      }
      if (intervals[l][0] >= x[1]) res[x[2]] = intervals[l][2];
    }
    return res;
  }
};