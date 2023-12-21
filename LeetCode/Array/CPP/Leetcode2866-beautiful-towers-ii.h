#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:
  using LL = long long;
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    int n = maxHeights.size();
    LL ans = 0;
    stack<int> stk;
    stk.push(n);
    vector<LL> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      int x = maxHeights[i];
      while (stk.size() > 1 && x <= maxHeights[stk.top()]) {
        auto j = stk.top();
        stk.pop();
        ans -= (LL)(stk.top() - j) * maxHeights[j];
      }
      ans += (LL)(stk.top() - i) * x;
      suf[i] = ans;
      stk.push(i);
    }
    stk = stack<int>();
    stk.push(-1);
    LL pre = 0;
    for (int i = 0; i < n; i++) {
      int x = maxHeights[i];
      while (stk.size() > 1 && x <= maxHeights[stk.top()]) {
        auto j = stk.top();
        stk.pop();
        pre -= (LL)(j - stk.top()) * maxHeights[j];
      }
      pre += (LL)(i - stk.top()) * x;
      ans = max(ans, pre + suf[i + 1]);
      stk.push(i);
    }
    return ans;
  }
};