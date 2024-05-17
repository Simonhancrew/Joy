#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  using PII = pair<int, int>;
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {
    vector<PII> jobs;
    int n = difficulty.size();
    for (int i = 0; i < n; i++) {
      jobs.emplace_back(difficulty[i], profit[i]);
    }
    ranges::sort(jobs);
    ranges::sort(worker);
    int ans = 0, max_profit = 0;
    int j = 0;
    for (const auto &x : worker) {
      while (j < n && jobs[j].first <= x) {
        max_profit = max(max_profit, jobs[j].second);
        ++j;
      }
      ans += max_profit;
    }
    return ans;
  }
};
