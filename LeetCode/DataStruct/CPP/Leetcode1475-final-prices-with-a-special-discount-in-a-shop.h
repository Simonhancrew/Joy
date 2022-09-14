/*
  单调栈，快速求一个数左边第一个比它小的数。reverse做就可以,原数组修改的话需要cache当前数最后push到栈中
  单调栈：如果一个数，来的比你晚，还比你大，那你存在的意义就没有了。
*/
class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> stk;
    for (int i = n - 1; i >= 0; i--) {
      while (stk.size() && stk.back() > prices[i]) stk.pop_back();
      auto t = prices[i];
      if (stk.size()) prices[i] -= stk.back();
      stk.push_back(t);
    }
    return prices;
  }
};
