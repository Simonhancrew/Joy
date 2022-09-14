/*
    从前往后走，如果走不到就在前面的加油站中选择最大的油加入
*/
class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    int res = 0;
    stations.emplace_back(vector<int>{target, 0});
    priority_queue<int> q;
    for (auto &p : stations) {
      int x = p[0], y = p[1];
      while (q.size() && startFuel < x) {
        startFuel += q.top();
        q.pop();
        res++;
      }
      if (startFuel < x) return -1;
      q.push(y);
    }
    return res;
  }
};