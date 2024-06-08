#include <cstring>
#include <functional>
#include <vector>

using namespace std;

constexpr int N = 2001;
int f[N][N];
class Solution {
public:
  int maxOperations(vector<int> &nums) {
    int n = nums.size();
    int pre = 0;
    function<int(int, int)> dfs = [&](int l, int r) {
      if (r <= l) {
        return 0;
      }
      if (f[l][r] != -1) {
        return f[l][r];
      }
      int &res = f[l][r];
      res = 0;
      if (pre == nums[l] + nums[l + 1]) {
        res = dfs(l + 2, r) + 1;
      }
      if (pre == nums[r] + nums[r - 1]) {
        res = max(res, dfs(l, r - 2) + 1);
      }
      if (pre == nums[l] + nums[r]) {
        res = max(res, dfs(l + 1, r - 1) + 1);
      }
      return res;
    };
    pre = nums[0] + nums[1];
    memset(f, -1, sizeof(f));
    auto res = dfs(2, n - 1);
    pre = nums[n - 1] + nums[n - 2];
    memset(f, -1, sizeof(f));
    res = max(res, dfs(0, n - 3));
    pre = nums[0] + nums[n - 1];
    memset(f, -1, sizeof(f));
    res = max(res, dfs(1, n - 2));
    return res + 1;
  }
};
