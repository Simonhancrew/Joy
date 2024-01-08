#include <unordered_map>

using namespace std;

class Solution {
public:
  static int calcu(vector<int> &l, vector<int> &r) {
    return (l[0] - r[0]) * (l[0] - r[0]) + (l[1] - r[1]) * (l[1] - r[1]);
  }

  int numberOfBoomerangs(vector<vector<int>> &points) {
    int n = points.size();
    if (n < 3) {
      return 0;
    }
    int res = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp.clear();
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        auto dis = calcu(points[i], points[j]);
        res += mp[dis]++ * 2;
      }
    }
    return res;
  }
};
