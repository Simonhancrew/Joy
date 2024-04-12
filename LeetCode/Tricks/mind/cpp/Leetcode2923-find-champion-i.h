#include <vector>

using namespace std;

class Solution {
public:
  int findChampion(vector<vector<int>> &grid) {
    int ans = 0;
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      if (grid[i][ans] == 1) {
        ans = i;
      }
    }
    return ans;
  }
};
