/*
  [L, R],  中间点 = (L + R) / 2
  前一半不包含中间， L..(L + R - 1) / 2
  后一半包含中间， (L + R) / 2 + 1..R
  分情况讨论
    1. L..L or R..R, 直接填充
    2. R..L, 先填充前一半，再填充后一半
    3. L..R, 不变
  用pre维护前一个值
*/
class Solution {
 public:
  string pushDominoes(string dominoes) {
    auto s  = "L" + dominoes + "R";
    int pre = 0;
    int n   = s.size();
    for (int i = 1; i < n; ++i) {
      if (s[i] == '.') {
        continue;
      }
      if (s[i] == s[pre]) {
        fill(s.begin() + pre + 1, s.begin() + i, s[i]);
      } else if (s[i] == 'L') {
        fill(s.begin() + pre + 1, s.begin() + (pre + i + 1) / 2, 'R');
        fill(s.begin() + (pre + i) / 2 + 1, s.begin() + i, 'L');
      }
      pre = i;
    }
    return s.substr(1, n - 2);
  }
};
