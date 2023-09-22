// children > 1, 只要有的分，就不会-1
// 分情况，恰好每个人8个
// 另外一种情况，继续划分
// 1. > 8 * children, 这种有一个人要拿剩下的
// 2. < 8 * children, 这种再细分
//    2.1. 8 * children - 4, 为了不让分到4， 要再浪费一个
//    2.2 其余的 < 8 * children的， 先给每个人分1， 然后再考虑给每个人分7，
//    看能分多少个
class Solution {
 public:
  int distMoney(int money, int children) {
    if (money < children) return -1;
    if (money > children * 8) return children - 1;
    if (money == children * 8 - 4) return children - 2;
    return (money - children) / 7;
  }
};
