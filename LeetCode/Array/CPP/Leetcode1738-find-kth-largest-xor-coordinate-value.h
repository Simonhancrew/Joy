#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int kthLargestValue(vector<vector<int>> &matrix, int k) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> pre(n + 1, vector<int>(m + 1));
    priority_queue<int, vector<int>, greater<>> heap;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        auto cur = pre[i - 1][j] ^ pre[i][j - 1] ^ pre[i - 1][j - 1] ^
                   matrix[i - 1][j - 1];
        if (heap.size() < k) {
          heap.push(cur);
        } else {
          if (heap.top() < cur) {
            heap.push(cur);
            heap.pop();
          }
        }
        pre[i][j] = cur;
      }
    }
    return heap.top();
  }
};
