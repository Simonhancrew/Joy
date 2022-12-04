// 因为数量足够小，爆搜也没问题
class Solution {
  public:
    int res = numeric_limits<int>::max();
    int m, tar;
    void dfs(int idx, int sum, vector<int>& costs) {
      if (idx == m) {
        if (abs(sum - tar) < abs(res - tar) || abs(sum - tar) == abs(res - tar) && res > sum) {
          res = sum;
        } 
        return;
      } 
      for(int i = 0;i <= 2;i++) {
        dfs(idx + 1, sum + costs[idx] * i, costs);
      }
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
      int n = baseCosts.size();
      m = toppingCosts.size(), tar = target;
      for(int i = 0;i < n;i++) {
        int t = baseCosts[i];
        dfs(0, t, toppingCosts);
      }
      return res;
    }
};
