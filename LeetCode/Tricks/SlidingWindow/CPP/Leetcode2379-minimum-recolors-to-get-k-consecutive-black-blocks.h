class Solution {
 public:
  int minimumRecolors(string blocks, int k) {
    int res = numeric_limits<int>::max();
    int n = blocks.size(), cur = 0;
    for (int i = 0, j = 0; i <= n - k; i++) {
      while (j - i + 1 <= k) {
        if (blocks[j] == 'W') cur++;
        j++;
      }
      res = min(res, cur);
      if (blocks[i] == 'W') cur--;
    }
    return res;
  }
};