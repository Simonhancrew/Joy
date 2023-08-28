class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    if (intervals.empty()) return {newInterval};
    int n = intervals.size();
    vector<vector<int>> ans;
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (intervals[mid][0] <= newInterval[0])
        l = mid;
      else
        r = mid - 1;
    }
    if (intervals[l][0] <= newInterval[0]) {
      intervals.insert(intervals.begin() + l + 1, newInterval);
    } else {
      intervals.insert(intervals.begin(), newInterval);
    }
    n = intervals.size();
    for (int i = 0; i < n; i++) {
      int j = i, r = intervals[i][1];
      while (j + 1 < n && intervals[j + 1][0] <= r) {
        r = max(r, intervals[j + 1][1]);
        j++;
      }
      ans.push_back({intervals[i][0], r});
      i = j;
    }
    return ans;
  }
};
