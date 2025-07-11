class Solution {
 public:
  int countDays(int days, vector<vector<int>> &meetings) {
    ranges::sort(meetings, {}, [](auto &m) {
      return m[0];
    });
    int start = meetings[0][0], end = meetings[0][1];
    for (int i = 1; i < meetings.size(); ++i) {
      if (meetings[i][0] > end) {
        days -= end - start + 1;
        start = meetings[i][0];
      }
      end = max(end, meetings[i][1]);
    }
    days -= end - start + 1;
    return days;
  }
};
