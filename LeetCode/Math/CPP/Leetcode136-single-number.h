#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (const auto x : nums) {
      ans ^= x;
    }
    return ans;
  }
};
