#include <queue>

using namespace std;
class Solution {
 public:
  using PII = pair<int, int>;
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    sort(trips.begin(), trips.end(), [](auto &lhs, auto &rhs) {
      return lhs[1] < rhs[1];
    });
    int cur = 0;
    priority_queue<PII, vector<PII>, greater<>> tos;
    for (const auto &x : trips) {
      while (!tos.empty()) {
        auto t = tos.top();
        if (x[1] < t.first)
          break;
        tos.pop();
        capacity += t.second;
      }
      if (capacity < x[0]) {
        return false;
      }
      capacity -= x[0];
      tos.emplace(x[2], x[0]);
    }
    return true;
  }
};
