#include <queue>
#include <vector>

using namespace std;

/*
    先用更多的，如果即将凑成连续三个就用次多的，此时没有次多的就结束
*/

class Solution {
 public:
  using PII = pair<int, int>;
  string longestDiverseString(int a, int b, int c) {
    string ans;
    auto cmp = [](PII lhs, PII rhs) { return lhs.second < rhs.second; };
    priority_queue<PII, vector<PII>, decltype(cmp)> heap(cmp);
    if (a > 0) heap.push({0, a});
    if (b > 0) heap.push({1, b});
    if (c > 0) heap.push({2, c});
    while (heap.size()) {
      auto t = heap.top();
      heap.pop();
      char cur = 'a' + t.first;
      int n = ans.size();
      if (n >= 2 && ans[n - 1] == cur && ans[n - 2] == cur) {
        if (heap.empty()) break;
        auto ne = heap.top();
        heap.pop();
        char next = ne.first + 'a';
        ans += next;
        ne.second--;
        if (ne.second > 0) heap.push(ne);
        heap.push(t);
      } else {
        ans += cur;
        t.second--;
        if (t.second > 0) heap.push(t);
      }
    }
    return ans;
  }
};