#include <array>
#include <vector>


using namespace std;

class Solution {
public:
  using LL = long long;
  long long maxEnergyBoost(vector<int> &energyDrinkA,
                           vector<int> &energyDrinkB) {
    int n = energyDrinkA.size();
    vector<array<LL, 2>> f(n, array<LL, 2>{-1, -1});
    auto dfs = [&](auto &&dfs, int i, int pre) {
      if (i >= n) {
        return 0ll;
      }
      if (f[i][pre] != -1) {
        return f[i][pre];
      }
      auto &ans = f[i][pre];
      ans = (pre ? energyDrinkA[i] : energyDrinkB[i]);
      ;
      ans += max(dfs(dfs, i + 1, pre), dfs(dfs, i + 2, pre ^ 1));
      return ans;
    };
    return max(dfs(dfs, 0, 0), dfs(dfs, 0, 1));
  }
};
