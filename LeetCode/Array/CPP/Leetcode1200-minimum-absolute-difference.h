class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    int mini = INT_MAX, n = arr.size();
    for (int i = 0; i < n - 1; i++) {
      int diff = arr[i + 1] - arr[i];
      if (diff == mini)
        res.emplace_back(vector<int>{arr[i], arr[i + 1]});
      else if (diff < mini) {
        mini = diff;
        res.clear();
        res.emplace_back(vector<int>{arr[i], arr[i + 1]});
      }
    }
    return res;
  }
};