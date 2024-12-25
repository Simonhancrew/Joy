class Solution {
 public:
  int minimumCost(int m, int n, vector<int> &horizontalCut,
                  vector<int> &verticalCut) {
    ranges::sort(horizontalCut, [](auto &lhs, auto &rhs) {
      return lhs > rhs;
    });
    ranges::sort(verticalCut, [](auto &lhs, auto &rhs) {
      return lhs > rhs;
    });
    int i = 0, j = 0;
    int h = 1, v = 1;
    int ans = 0;
    while (i < horizontalCut.size() || j < verticalCut.size()) {
      if (j == verticalCut.size() ||
          (i < horizontalCut.size() && horizontalCut[i] > verticalCut[j])) {
        ans += horizontalCut[i] * v;
        h++;
        i++;
      } else {
        ans += verticalCut[j] * h;
        v++;
        j++;
      }
    }
    return ans;
  }
};
