#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
 public:
  int minStoneSum(vector<int>& piles, int k) {
    // [begin, last)构成堆
    make_heap(piles.begin(), piles.end());
    while (k-- && piles[0]) {
      // [begin, last- 1)成堆，之前的最大值已经被放到了最后
      pop_heap(piles.begin(), piles.end());
      piles.back() -= piles.back() / 2;
      // 将last - 1放到堆里，[begin, last)成堆
      push_heap(piles.begin(), piles.end());
    }
    return accumulate(piles.begin(), piles.end(), 0);
  }
};
