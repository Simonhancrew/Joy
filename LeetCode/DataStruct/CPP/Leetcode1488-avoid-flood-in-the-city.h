#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 从右往左，先算一下当前下过雨的湖泊下一次下雨是那一天
// 从左往右遍历的时候记录有水的湖泊，用一个小根堆维护下过雨的湖泊的下一次下雨的时间
// 某个晴天，拿堆顶，把堆顶的湖泊抽干，当前晴天抽干的湖泊就是这个湖泊
// 将这个湖泊从有水的湖泊中移除后继续遍历

class Solution {
 public:
  using PII = pair<int, int>;
  vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();
    unordered_map<int, int> mp;
    vector<int> next_day(n, n + 1);
    for (int i = n - 1; i >= 0; i--) {
      if (rains[i] > 0) {
        if (mp.count(rains[i])) next_day[i] = mp[rains[i]];
        mp[rains[i]] = i;
      }
    }
    unordered_set<int> fill;
    vector<int> ans;
    ans.reserve(n);
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++) {
      if (rains[i] > 0) {
        if (fill.count(rains[i])) return {};
        fill.insert(rains[i]);
        if (next_day[i] != n + 1) heap.emplace(next_day[i]);
        ans.push_back(-1);
      } else {
        if (fill.empty() || heap.empty())
          ans.push_back(1);
        else {
          auto t = heap.top();
          heap.pop();
          fill.erase(rains[t]);
          ans.push_back(rains[t]);
        }
      }
    }
    return ans;
  }
};
