#include <vector>
#include <ranges>

using namespace std;

/*
遍历passenger和buses，双指针，找到最后能遍历到的passenger[j]和当前容量

容量分情况，ans初始值为
  1. 满的，直接buses.back()开始
  2. 空的，从passenger[j]开始

往前找，ans--，j--, 直到找到ans != passenger[j]为止
*/ 

class Solution {
public:
  int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers,
                            int capacity) {
    ranges::sort(buses);
    ranges::sort(passengers);
    int cap = capacity;
    int j = 0, i = 0;
    for (const auto &bus : buses) {
      for (cap = capacity;
           cap > 0 && j < passengers.size() && passengers[j] <= bus; cap--) {
        ++j;
      }
    }
    j--;
    int ans = cap ? buses.back() : passengers[j];
    while (j >= 0 && ans == passengers[j]) {
      ans--;
      j--;
    }
    return ans;
  }
};
