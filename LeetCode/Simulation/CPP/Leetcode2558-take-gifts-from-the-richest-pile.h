#include <queue>

using namespace std;

class Solution {
 public:
  using LL = long long;
  long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<int> heap;
    for (const auto x : gifts) {
      heap.push(x);
    }
    for (int i = 0; i < k; i++) {
      if (heap.empty()) return 0;
      auto t = heap.top();
      heap.pop();
      t = sqrt(t);
      if (t) heap.push(t);
    }
    LL ans = 0;
    while (!heap.empty()) {
      ans += heap.top();
      heap.pop();
    }
    return ans;
  }
};
