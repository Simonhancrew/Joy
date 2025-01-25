#include <vector>

using namespace std;

class Solution {
 public:
  using LL = long long;
  /*
      if cost - cashback < 0
          lost += cost - cashback
      赚钱， cashback更大
      + money - lost >= cost => lost + cost
      亏钱，cost更大
      money - (lost - (cost - cashback)) >= cost
      money - lost - cashback >= 0
      + money  >= lost + cashback
  */
  long long minimumMoney(vector<vector<int>> &transactions) {
    LL lost = 0;
    int add = 0;
    for (const auto &x : transactions) {
      auto cost = x[0], cashback = x[1];
      lost += max(0, cost - cashback);
      add = max(add, min(cost, cashback));
    }
    return lost + add;
  }
};
