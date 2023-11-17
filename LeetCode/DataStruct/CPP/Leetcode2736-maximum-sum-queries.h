#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
 public:
  using PII = pair<int, int>;
  vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2,
                                vector<vector<int>> &queries) {
    int n = nums1.size();
    vector<PII> nums(n);
    for (int i = 0; i < n; i++) {
      nums[i] = {nums1[i], nums2[i]};
    }
    sort(nums.begin(), nums.end(),
         [](auto &lhs, auto &rhs) { return lhs.first > rhs.first; });
    int m = queries.size();
    vector<int> id(m);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(),
         [&queries](int l, int r) { return queries[l][0] > queries[r][0]; });
    vector<int> ans(m);
    int j = 0;
    vector<PII> st;
    for (auto i : id) {
      int x = queries[i][0], y = queries[i][1];
      for (; j < n && nums[j].first >= x; j++) {
        while (!st.empty() &&
               st.back().second <=
                   nums[j].first +
                       nums[j].second) {  // a[j].second >= st.back().first
          st.pop_back();
        }
        if (st.empty() || st.back().first < nums[j].second) {
          st.emplace_back(nums[j].second, nums[j].first + nums[j].second);
        }
      }
      auto it =
          lower_bound(st.begin(), st.end(), y,
                      [](const auto &p, int val) { return p.first < val; });
      ans[i] = it != st.end() ? it->second : -1;
    }
    return ans;
  }
};
