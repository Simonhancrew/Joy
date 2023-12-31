#include <array>
#include <numeric>
#include <string>

using namespace std;

// 闰年，是4和400的倍数，但不是100的倍数

class Solution {
public:
  array<int, 12> mp = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int dayOfYear(string date) {
    auto y = stoi(date.substr(0, 4));
    auto m = stoi(date.substr(5, 2));
    auto d = stoi(date.substr(8, 2));
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
      mp[1] = 29;
    }
    return accumulate(mp.begin(), mp.begin() + m - 1, d);
  }
};
