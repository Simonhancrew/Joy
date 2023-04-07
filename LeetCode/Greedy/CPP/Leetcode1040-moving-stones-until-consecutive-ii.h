class Solution {
 public:
  vector<int> numMovesStonesII(vector<int>& stones) {
    int n = stones.size();
    sort(stones.begin(), stones.end());
    int tot = stones.back() - stones[0] + 1 - n;
    vector<int> res(2);
    res[1] =
        tot - min(stones[1] - stones[0] - 1, stones[n - 1] - stones[n - 2] - 1);
    res[0] = n;
    for (int i = 0, j = 0; i < n; i++) {
      while (stones[i] - stones[j] + 1 > n) ++j;
      int len = i - j + 1;
      int r{};
      if (len == n - 1 && stones[i] - stones[j] == i - j)
        r = 2;
      else
        r = n - len;
      res[0] = min(res[0], r);
    }
    return res;
  }
};
