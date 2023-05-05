#include <vector>

using namespace std;

class Solution {
 public:
  int hardestWorker(int n, vector<vector<int>>& logs) {
    int mx = 0, pre = 0, id = n, m = logs.size();
    for (int i = 0; i < m; i++) {
      if (mx < logs[i][1] - pre) {
        mx = logs[i][1] - pre;
        id = logs[i][0];
      } else if (mx == logs[i][1] - pre) {
        id = min(id, logs[i][0]);
      }
      pre = logs[i][1];
    }
    return id;
  }
};
