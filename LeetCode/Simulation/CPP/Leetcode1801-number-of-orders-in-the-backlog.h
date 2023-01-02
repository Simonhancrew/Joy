#include <queue>
#include <algorithm>

using namespace std;

class Solution {
 public:
  const int N = 1e9 + 7;
  using PII = pair<int, int>;
  int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    priority_queue<PII, vector<PII>, greater<PII>> sell;
    priority_queue<PII, vector<PII>, less<PII>> buy;
    int ans = 0;
    for (auto& x : orders) {
      auto p = x[0], c = x[1], t = x[2];
      if (t == 0) {
        while (sell.size() && c && sell.top().first <= p) {
          auto cur = sell.top();
          sell.pop();
          int sub = min(c, cur.second);
          c -= sub, cur.second -= sub;
          if (cur.second) sell.push(cur);
        }
        if (c) buy.emplace(p, c);
      } else {
        while (buy.size() && c && buy.top().first >= p) {
          auto cur = buy.top();
          buy.pop();
          int sub = min(c, cur.second);
          c -= sub, cur.second -= sub;
          if (cur.second) buy.push(cur);
        }
        if (c) sell.emplace(p, c);
      }
    }
    while (sell.size()) {
      ans = (ans + sell.top().second) % N;
      sell.pop();
    }
    while (buy.size()) {
      ans = (ans + buy.top().second) % N;
      buy.pop();
    }
    return ans;
  }
};