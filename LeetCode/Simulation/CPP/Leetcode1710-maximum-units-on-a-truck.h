class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](auto& lhs, auto rhs) { return lhs[1] > rhs[1]; });
    int ans = 0, idx = 0, n = boxTypes.size();
    for (int i = 0; i < n; i++) {
      if (truckSize) {
        int tmp = min(boxTypes[i][0], truckSize);
        truckSize -= tmp;
        ans += tmp * boxTypes[i][1];
      } else {
        break;
      }
    }
    return ans;
  }
};