#include <vector>

using namespace std;

class Solution {
public:
  using LL = long long;
  LL qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
      if (k & 1)
        res = (LL)res * a % p;
      a = (LL)a * a % p;
      k >>= 1;
    }
    return res;
  }
  vector<int> getGoodIndices(vector<vector<int>> &variables, int target) {
    vector<int> res;
    for (int i = 0; i < variables.size(); i++) {
      auto x = qmi(variables[i][0], variables[i][1], 10);
      auto y = qmi(x, variables[i][2], variables[i][3]);
      if (y == target) {
        res.push_back(i);
      }
    }
    return res;
  }
};
