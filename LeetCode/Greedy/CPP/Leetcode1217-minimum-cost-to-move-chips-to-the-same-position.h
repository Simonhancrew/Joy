/*
    greedy:看每个位置奇偶性，两个步骤中只有移一位才改变奇偶性
*/
class Solution {
public:
  int minCostToMoveChips(vector<int> &position) {
    int odd = 0, even = 0;
    for (auto p : position) {
      if (p % 2 == 1)
        odd++;
      else
        even++;
    }
    if (odd == 0 || even == 0)
      return 0;
    return min(odd, even);
  }
};