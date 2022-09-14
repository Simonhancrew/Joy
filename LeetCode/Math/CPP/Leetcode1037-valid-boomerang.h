class Solution {
 public:
  bool isBoomerang(vector<vector<int>> &points) {
    int k1 = (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]);
    int k2 = (points[2][1] - points[1][1]) * (points[1][0] - points[0][0]);
    return k1 != k2;
  }
};