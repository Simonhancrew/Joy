#include <algorithm>
#include <string>
#include <vector>


using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](auto& lhs, auto& rhs) { return lhs[0] < rhs[0]; });
    int n = intervals.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      int j = i + 1;
      int l = intervals[i][0], r = intervals[i][1];
      while (j < n && intervals[j][0] >= l && intervals[j][0] <= r) {
        r = max(r, intervals[j][1]);
        j++;
      }
      ans.push_back({l, r});
      i = j - 1;
    }
    return ans;
  }
};
