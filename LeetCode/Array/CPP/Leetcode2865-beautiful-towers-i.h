#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  using LL = long long;
  long long maximumSumOfHeights(vector<int> &maxHeights) {
    int n = maxHeights.size();
    stack<int> stk;
    stk.push(-1);
    LL sum = 0;
    vector<LL> pre;
    pre.reserve(n + 1);
    pre.push_back(0);
    for (int i = 0; i < n; i++) {
      while (stk.size() > 1 && maxHeights[i] <= maxHeights[stk.top()]) {
        int j = stk.top();
        stk.pop();
        sum -= (LL)maxHeights[j] * (j - stk.top());
      }
      sum += (LL)maxHeights[i] * (i - stk.top());
      stk.push(i);
      pre.push_back(sum);
    }
    sum = 0;
    LL ans = 0;
    stk = stack<int>{};
    stk.push(n);
    for (int i = n - 1; i >= 0; i--) {
      while (stk.size() > 1 && maxHeights[i] <= maxHeights[stk.top()]) {
        int j = stk.top();
        stk.pop();
        sum -= (LL)maxHeights[j] * (stk.top() - j);
      }
      sum += (LL)maxHeights[i] * (stk.top() - i);
      stk.push(i);
      ans = max(ans, sum + pre[i]);
    }
    return ans;
  }
};
