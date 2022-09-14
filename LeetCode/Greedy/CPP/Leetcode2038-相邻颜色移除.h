/*
    各自移除颜色互不影响，直接看看谁能移除的多就ok
*/
class Solution {
 public:
  bool winnerOfGame(string colors) {
    int n = colors.size();
    int f[2] = {0, 0}, cnt = 1;
    char cur = 'C';
    for (int i = 0; i < n; i++) {
      if (colors[i] != cur) {
        cur = colors[i];
        cnt = 1;
      } else {
        if (++cnt >= 3) f[cur - 'A']++;
      }
    }
    return f[0] > f[1];
  }
};