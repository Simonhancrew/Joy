#include <vector>

using namespace std;

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int tot = flowerbed.size();
    int cnt = 0;
    for (int i = 0; i < tot; i++) {
      if (flowerbed[i] == 0) {
        if (i - 1 >= 0 && flowerbed[i - 1] == 1) continue;
        if (i + 1 < tot && flowerbed[i + 1] == 1) continue;
        cnt++;
        flowerbed[i] = 1;
      }
      if (cnt >= n) break;
    }
    return cnt >= n;
  }
};
