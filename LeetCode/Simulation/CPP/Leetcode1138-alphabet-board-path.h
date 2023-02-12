// 对z特判一下，终点是z的话先横着走，再竖着走
// 不是z的话，先竖着走，再横着走(可能从z出发)
#define x first
#define y second
class Solution {
 public:
  using PII = pair<int, int>;
  PII get(char c) {
    int t = c - 'a';
    return {t / 5, t % 5};
  }
  string alphabetBoardPath(string target) {
    string res;
    PII p{0, 0};
    for (auto& c : target) {
      auto t = get(c);
      if (c == 'z') {
        if (t.y > p.y)
          res += string(t.y - p.y, 'R');
        else
          res += string(p.y - t.y, 'L');
        if (t.x > p.x)
          res += string(t.x - p.x, 'D');
        else
          res += string(p.x - t.x, 'U');
      } else {
        if (t.x > p.x)
          res += string(t.x - p.x, 'D');
        else
          res += string(p.x - t.x, 'U');
        if (t.y > p.y)
          res += string(t.y - p.y, 'R');
        else
          res += string(p.y - t.y, 'L');
      }
      p = t;
      res += '!';
    }
    return res;
  }
};