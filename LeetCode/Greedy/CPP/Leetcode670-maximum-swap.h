#include <algorithm>
#include <string>

using namespace std;

// 逆序找最大的，然后越靠前的约值得交换

class Solution {
public:
  int maximumSwap(int num) {
    auto s = to_string(num);
    auto n = s.size();
    int mxidx = n - 1;
    int idx1 = -1;
    int idx2 = -1;
    for (auto i = n - 1; i >= 0; i--) {
      if (s[mxidx] < s[i]) {
        mxidx = i;
      } else if (s[i] < s[mxidx]) {
        idx1 = i;
        idx2 = mxidx;
      }
    }
    if (idx1 != -1) {
      swap(s[idx1], s[idx2]);
      return stoi(s);
    }
    return num;
  }
};
