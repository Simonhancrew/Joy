#include <algorithm>
#include <array>
#include <vector>

class Solution {
 public:
  static bool isPossibleToSplit(std::vector<int> &nums) {
    std::array<int, 101> mp;
    for (const auto x : nums) {
      mp[x]++;
    }
    return std::all_of(mp.begin(), mp.end(), [](auto &item) {
      return item <= 2;
    });
  }
};
