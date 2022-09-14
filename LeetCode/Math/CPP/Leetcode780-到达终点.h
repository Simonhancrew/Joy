/*
    1. 一定有一个数变大，所以从反向考虑，方向的变化是确定的
    2. 数据很大，不要减，mod操作
    3. 最后判断的时候完全无法凑成的情况和可能凑成（差值被整除）的情况
*/
class Solution {
 public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (tx >= sx && ty >= sy) {
      if (tx == ty) break;
      if (tx > ty) {
        if (ty > sy)
          tx %= ty;
        else
          return (tx - sx) % ty == 0;
      } else {
        if (tx > sx)
          ty %= tx;
        else
          return (ty - sy) % tx == 0;
      }
    }
    return sx == tx && sy == ty;
  }
};