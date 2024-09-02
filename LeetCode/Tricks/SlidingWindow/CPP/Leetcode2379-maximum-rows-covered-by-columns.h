#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int ans = 110;
    int n = blocks.size();
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (blocks[i] == 'W')
        cur++;
      if (i < k - 1)
        continue;
      ans = min(ans, cur);
      if (blocks[i - k + 1] == 'W')
        cur--;
    }
    return ans;
  }
};
