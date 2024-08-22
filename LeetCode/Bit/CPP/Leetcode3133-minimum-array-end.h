// 因为要&之后结果还是x，所以x是1的位一定是1，0的位不能全为1
// x是1的不动，要逐步变大，所以最后一位(n - 1), 把n -
// 1的每个1逐步放到x的0上，最开始一定最小，直接放x
class Solution {
public:
  using LL = long long;
  long long minEnd(int n, int x) {
    --n;
    int i{}, j{};
    LL ans = x;
    while (n >> j) {
      if ((ans >> i & 1) == 0) {
        ans |= (LL)(n >> j & 1) << i;
        j++;
      }
      i++;
    }
    return ans;
  }
};
