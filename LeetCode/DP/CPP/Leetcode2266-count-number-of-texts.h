/*
  NOTE:
    按键盘输入，然后给出按键顺序，求有多少种可能的输入，这种等价在做fibonacci数列
      f[i]是连续i个一样按键下，有多少种可能的字母，可以固定后几位，然后前面的可能性就是f[i-1]，f[i-2]，f[i-3]
      将他们累加起来就是f[i]的可能性。
*/
const int MOD = 1e9 + 7;
const int N   = 1e5 + 1;
using LL      = long long;
LL f[N]{};
LL g[N]{};
auto _ = []() {
  f[0] = g[0] = 1;
  f[1] = g[1] = 1;
  f[2] = g[2] = 2;
  f[3] = g[3] = 4;
  for (int i = 4; i < N; i++) {
    f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % MOD;
    g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % MOD;
  }
  return 0;
}();

class Solution {
 public:
  int countTexts(string pressedKeys) {
    int ans = 1;
    int cnt = 0;
    for (int i = 0; i < pressedKeys.size(); i++) {
      auto c = pressedKeys[i];
      ++cnt;
      if (i == pressedKeys.size() - 1 || pressedKeys[i + 1] != c) {
        ans = ans *
              ((pressedKeys[i] == '7' || pressedKeys[i] == '9') ? g[cnt]
                                                                : f[cnt]) %
              MOD;
        cnt = 0;
      }
    }
    return ans;
  }
};
