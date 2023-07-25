#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:
  int halveArray(vector<int>& nums) {
    double sum = accumulate(nums.begin(), nums.end(), 0ll);
    priority_queue<double> heap;
    for (const auto x : nums) {
      heap.push(x);
    }
    double cur = sum;
    int cnt = 0;
    while (heap.size() && (cur - sum / 2.0) > 1e-3) {
      auto t = heap.top();
      heap.pop();
      auto diff = t / 2.0;
      cur -= diff;
      heap.push(diff);
      cnt++;
    }
    return cnt;
  }
};
