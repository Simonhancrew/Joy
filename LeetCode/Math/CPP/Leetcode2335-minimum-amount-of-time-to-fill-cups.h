class Solution {
 public:
  int fillCups(vector<int>& amount) {
    int res = 0;
    while (accumulate(amount.begin(), amount.end(), 0) != 0) {
      sort(amount.begin(), amount.end());
      amount[2]--;
      if (amount[1]) amount[1]--;
      res++;
    }
    return res;
  }
};