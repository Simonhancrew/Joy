#include <cstring>

using namespace std;

// 重新理解一下不贴上接且无前导0， 不贴上界代表后续状态可以复用
// 参考123XX, 此时x没有贴上接的话， 可以填1-9， 贴上界的话可以填[1, up], 状态是不一致的
// 前导0， 如果前导0影响结果的话，当前pos是前导0. 说明搜索没有结束， 状态依然不能复用， 需要从后面
// 的dfs返回答案上来

class Solution {
public:
  // 当前位置 + 二进制枚举出现的数 + 是否有重复
  int f[11][1024 + 10][2];
  int a[11];
  int dfs(int pos, int st ,bool succ, bool lead, bool limit) {
    if (!pos) {
      return succ;
    }
    if (!limit && !lead && f[pos][st][succ] != -1) return f[pos][st][succ];
    int res = 0, up = limit ? a[pos] : 9;
    for (int i = 0;i <= up;i++) {
        // 前导0不计入状态
        if (lead && i == 0) {
            res += dfs(pos - 1, st, succ, lead, limit && i == up);
        } else {
            res += dfs(pos - 1, st | (1 << i), succ | ((st >> i) & 1), lead && !i, limit && i == up);
        }
    }
    return limit ? res : (lead ? res : f[pos][st][succ] = res);
  }
  int numDupDigitsAtMostN(int n) {
    int len = 0;
    while (n) {
      a[++len] = n % 10;
      n /= 10;
    }
    memset(f, -1, sizeof f);
    return dfs(len, 0, 0, 1, 1);
  }
};
