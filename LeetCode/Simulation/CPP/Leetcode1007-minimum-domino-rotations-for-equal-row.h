class Solution {
 public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
    int n      = tops.size();
    auto calcu = [&](int tar) {
      int x = 0, y = 0;
      for (int i = 0; i < n; ++i) {
        if (tops[i] != tar && bottoms[i] != tar) {
          return INT_MAX;
        }
        if (tops[i] != tar) {
          x++;
        } else if (bottoms[i] != tar) {
          y++;
        }
      }
      return min(x, y);
    };
    auto ans = min(calcu(tops[0]), calcu(bottoms[0]));
    return ans == INT_MAX ? -1 : ans;
  }
};
