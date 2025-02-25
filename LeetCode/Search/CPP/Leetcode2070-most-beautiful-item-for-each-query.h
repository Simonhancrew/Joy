class Solution {
 public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    vector<int> ans;
    ans.reserve(queries.size());
    ranges::sort(items);
    vector<int> rec(items.size());
    rec[0] = items[0][1];
    for (int i = 1; i < items.size(); i++) {
      rec[i] = max(rec[i - 1], items[i][1]);
    }
    for (const auto &q : queries) {
      int l = -1, r = items.size();
      while (l + 1 < r) {
        int mid = l + r >> 1;
        if (items[mid][0] <= q)
          l = mid;
        else
          r = mid;
      }
      if (l == -1) {
        ans.push_back(0);
        continue;
      }
      ans.push_back(rec[l]);
    }
    return ans;
  }
};
