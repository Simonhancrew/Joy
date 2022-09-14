class Solution {
 public:
  double largestTriangleArea(vector<vector<int>> &p) {
    int n = p.size();
    double ans = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          double x1 = p[i][0], y1 = p[i][1];
          double x2 = p[j][0] - x1, x3 = p[k][0] - x1;
          double y2 = p[j][1] - y1, y3 = p[k][1] - y1;
          ans = max(ans, abs(x2 * y3 - x3 * y2) / 2);
        }
      }
    }
    return ans;
  }
};