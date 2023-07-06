#include <vector>

using namespace std;

class Solution {
 public:
  using LL = int64_t;
  vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum & 1) {
      return {};
    }
    vector<LL> res;
    for (LL i = 2; finalSum >= i; i += 2) {
      res.push_back(i);
      finalSum -= i;
    }
    if (finalSum) {
      res.back() += finalSum;
    }
    return res;
  }
};