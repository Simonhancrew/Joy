#include <cmath>

// 直接恰好走完就是最优解，如果没有恰好走完，超过了偶数k的话，反向走一步k/2
// 超出步数是奇数的话，再走一步，如果回到前一个偶数的超出情况
// 如果依然是奇数的话，那么就是情况就是奇数 + 偶数，再走一步一定回到超出是偶数的情况

class Solution {
public:
    int reachNumber(int target) {
      target = abs(target);
      int cnt = 0, acc = 0;
      while(acc < target || (acc - target) & 1) {
        cnt++;
        acc += cnt;
      }
      return cnt;
    }
};
