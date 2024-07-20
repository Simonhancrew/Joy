#include <algorithm>
#include <numeric>
#include <vector>


using namespace std;

class Solution {
public:
  using PII = pair<int, int>;
  int minimumMoves(vector<vector<int>> &grid) {
    vector<PII> from, to;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (grid[i][j]) {
          for (int k = 1; k < grid[i][j]; k++) {
            from.emplace_back(i, j);
          }
        } else {
          to.emplace_back(i, j);
        }
      }
    }
    int ans = INT_MAX;
    do {
      int tot = 0;
      for (int i = 0; i < from.size(); i++) {
        tot += abs(from[i].first - to[i].first) +
               abs(from[i].second - to[i].second);
      }
      ans = min(ans, tot);
    } while (next_permutation(from.begin(), from.end()));
    return ans;
  }
};
