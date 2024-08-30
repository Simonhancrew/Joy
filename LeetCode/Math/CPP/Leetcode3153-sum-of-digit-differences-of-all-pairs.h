#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  using LL = int64_t;
  long long sumDigitDifferences(vector<int> &nums) {
    vector<array<int, 10>> arr(to_string(nums[0]).size());
    LL ans{};
    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      for (int c = 0; x; ++c, x /= 10) {
        ans += i - arr[c][x % 10];
        ++arr[c][x % 10];
      }
    }
    return ans;
  }
};
