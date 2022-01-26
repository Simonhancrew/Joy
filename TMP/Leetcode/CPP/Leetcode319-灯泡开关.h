#include <cmath>
// 当前灯是开的，一定被按了奇数次，等价于有奇数个约数
// 简单推导之后，一个数有奇数个约数，必定是一个完全平方数。
// 从1到n一共有sqrt(n)个完全平方数
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};