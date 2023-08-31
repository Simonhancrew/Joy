#include <vector>
#include <unordered_set>

using namespace std;

// 暴力判断边有没有相连，连接了的话算下度
// 每条边和点连接的算1(一整条边可以贡献2)，最后减去6(内部的边)

class Solution {
 public:
  int minTrioDegree(int n, vector<vector<int>>& edges) {
    int res = INT_MAX;
    unordered_set<int> st;
    vector<int> d(n + 1);
    for (const auto x : edges) {
      int a = x[0], b = x[1];
      if (a > b) swap(a, b);
      d[a]++, d[b]++;
      st.insert(a * 1000 + b);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (st.count(i * 1000 + j)) {
          for (int k = j + 1; k <= n; k++) {
            if (st.count(i * 1000 + k) && st.count(j * 1000 + k)) {
              res = min(res, d[i] + d[j] + d[k] - 6);
            }
          }
        }
      }
    }
    if (res == INT_MAX) return -1;
    return res;
  }
};
