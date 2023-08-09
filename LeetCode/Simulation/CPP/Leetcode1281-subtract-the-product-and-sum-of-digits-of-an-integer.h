#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int subtractProductAndSum(int n) {
    vector<int> rec;
    rec.reserve(5);
    while (n) {
      rec.push_back(n % 10);
      n /= 10;
    }
    int mul = 1;
    for (const auto x : rec) mul *= x;
    return mul - accumulate(rec.begin(), rec.end(), 0);
  }
};
