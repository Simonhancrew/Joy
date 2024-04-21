#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> cur;
    int sum{};
    function<void(int)> dfs = [&](int i) {
      if (i < 0) {
        return;
      }
      if (sum == n) {
        if (cur.size() == k) {
          ans.push_back(cur);
        }
        return;
      }
      if (i == 0) {
        return;
      }
      cur.push_back(i);
      sum += i;
      dfs(i - 1);
      sum -= i;
      cur.pop_back();
      dfs(i - 1);
    };
    dfs(9);
    return ans;
  }
};
