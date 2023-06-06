#include <map>
#include <vector>

using namespace std;

// 因为map是红黑树， 只要key实现了大小比较的运算符就可以了
class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    vector<vector<int>> rev;
    map<vector<int>, int> mp;
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      vector<int> tmp;
      for (int j = 0; j < n; j++) {
        tmp.push_back(grid[j][i]);
      }
      mp[grid[i]]++;
      rev.push_back(tmp);
    }
    int ans{};
    for (int i = 0; i < n; i++) {
      if (mp.count(rev[i])) {
        ans += mp[rev[i]];
      }
    }
    return ans;
  }
};
