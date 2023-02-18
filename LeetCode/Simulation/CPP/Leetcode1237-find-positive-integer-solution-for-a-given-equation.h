class Solution {
 public:
  vector<vector<int>> findSolution(CustomFunction& func, int z) {
    vector<vector<int>> res;
    int x = 1, y = 1000;
    while (x <= 1000 && y >= 1) {
      if (func.f(x, y) > z) {
        y--;
      } else if (func.f(x, y) < z) {
        x++;
      } else {
        res.push_back({x, y});
        x++, y--;
      }
    }
    return res;
  }
};