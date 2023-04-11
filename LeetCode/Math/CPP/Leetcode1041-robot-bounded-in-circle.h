// 1. 走了一圈之后回到原点
// 2. 走了一圈之后不面向北方， 其走的效果可以被后续的抵消
//    后续走的可以形成一个reverse（方向不同， 其走的其实是一个reverse）
class Solution {
 public:
  const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
  bool isRobotBounded(string instructions) {
    int x = 0, y = 0, d = 0;
    for (const auto c : instructions) {
      switch (c) {
        case 'G':
          break;
        case 'L':
          d = (d - 1 + 4) % 4;
          break;
        case 'R':
          d = (d + 1) % 4;
          break;
      }
      if (c == 'G') {
        x = x + dx[d], y = y + dy[d];
      }
    }
    return x == 0 && y == 0 || d != 0;
  }
};
