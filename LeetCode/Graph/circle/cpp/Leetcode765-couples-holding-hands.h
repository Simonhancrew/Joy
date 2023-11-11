#pragma once

#include <vector>
#include <numeric>

using namespace std;

// 本质上是要有n个自环，一对情侣的id是一样的
// 用并查集来做，每次合并两个情侣的id，如果两个情侣的id已经在一个集合里了，说明这两个情侣是连通的，不需要交换
// 最理想的状态就是所有情侣都是做好的，有n个正确的自环，所以最后答案就是n-连通分量的个数
// 其余情况下，找到所有存在的环，这个环大小是x，则需要交换x-1次

class Solution {
 public:
  vector<int> p;
  int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  }
  int minSwapsCouples(vector<int>& row) {
    int n = row.size() / 2;
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    int circle_cnt = n;
    for (int i = 0; i < 2 * n; i += 2) {
      int x = row[i] / 2, y = row[i + 1] / 2;
      if (find(x) != find(y)) {
        p[find(x)] = find(y);
        circle_cnt--;
      }
    }
    return n - circle_cnt;
  }
};
