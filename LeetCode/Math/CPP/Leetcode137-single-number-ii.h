#include <vector>

using namespace std;

// 贡献法，因为是int，4字节，位数是确定的，所以可以用32个int来记录每一位上1出现的次数，如果出现3次，就清0
// 最后剩下的就是只出现一次的数

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
      int cnt = 0;
      for (const auto x : nums) {
        cnt += (x >> i) & 1;
      }
      ans += (cnt % 3) << i;
    }
    return ans;
  }
};
