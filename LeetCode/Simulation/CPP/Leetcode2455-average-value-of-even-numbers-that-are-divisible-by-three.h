#include <vector>

using namespace std;

class Solution {
 public:
  int averageValue(vector<int>& nums) {
    int n = 0, acc = 0;
    for (const auto x : nums) {
      if (x % 6 == 0) {
        ++n;
        acc += x;
      }
    }
    return n > 0 ? acc / n : 0;
  }
};
