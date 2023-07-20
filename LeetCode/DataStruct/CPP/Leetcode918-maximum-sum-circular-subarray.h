#include <queue>

using namespace std;

class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    vector<int> s(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
      s[i] = s[i - 1] + nums[(i - 1) % n];
    }
    int ans = INT_MIN;
    deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= 2 * n; i++) {
      while (q.size() && i - q.front() > n) q.pop_front();
      auto cur = s[i] - s[q.front()];
      while (q.size() && s[i] <= s[q.back()]) q.pop_back();
      q.push_back(i);
      ans = max(ans, cur);
    }
    return ans;
  }
};