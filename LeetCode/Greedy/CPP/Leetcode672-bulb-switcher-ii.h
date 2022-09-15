// 找规律，只有四个开关，所以根据抽屉原理，按的次数大于4的时候
// 一定是有相同的开关被按到了，总的按次数等价于可以-2，所以有效的按次数一定是
// 小于等于4的
// 又因为按下1 + 2 = 3，1 + 3 = 2， 2 + 3 = 1，因此
// 当按的次数>=3,且全部是不一样的时候，又可以 -1，
// 又可以发现，k和k + 6的状态是一致的，所以灯是按照6一个循环
// 所以其实只要关注前6个灯的状态就可了。
// 因此按照按的次数，枚举所有的状态然后统计所有可能的status

class Solution {
 public:
  int state[8][6] = {
      {1, 1, 1, 1, 1, 1},  // 不按
      {0, 0, 0, 0, 0, 0},  // 1
      {1, 0, 1, 0, 1, 0},  // 2
      {0, 1, 0, 1, 0, 1},  // 3
      {0, 1, 1, 0, 1, 1},  // 4
      {1, 0, 0, 1, 0, 0},  // 14
      {0, 0, 1, 1, 1, 0},  // 24
      {1, 1, 0, 0, 0, 1},  // 34
  };
  int f(int n, vector<int> pos) {
    unordered_set<int> st;
    for (auto p : pos) {
      int t = 0;
      for (int i = 0; i < n; i++) {
        t = t * 2 + state[p][i];
      }
      st.insert(t);
    }
    return st.size();
  }

  int flipLights(int n, int presses) {
    n = min(n, 6);
    if (presses == 0)
      return f(n, {0});
    else if (presses == 1)
      return f(n, {1, 2, 3, 4});
    else if (presses == 2)
      return f(n, {0, 1, 2, 3, 5, 6, 7});
    return f(n, {0, 1, 2, 3, 4, 5, 6, 7});
  }
};
