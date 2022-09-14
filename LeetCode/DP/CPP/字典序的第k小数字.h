#include <string>

using namespace std;

/*
    prefix从1开始，分类讨论
        1. k = 1的时候，直接结束了
        2. k > 1，找到当前前缀的在不超过n的前提下有多少合法总数cnt
           k > cnt，表明前缀更大，减去
           k <=cnt，表明当前期待值就在这个区间中，前缀扩大一位再计算就行了
           并且需要将自己本身减去
*/

class Solution {
 public:
  using LL = long long;
  // 其实prefix是从第一位开始算的，只不过第一位的可能情况只有1
  int f(int prefix, int n) {
    string a = to_string(n), b = to_string(prefix);
    int d = a.size() - b.size();
    LL res = 0, p = 1;
    // 添加每一位的可能结果，并求和
    for (int i = 0; i < d; i++) {
      res += p;
      p *= 10;
    }
    // 当等长的时候就不能xjb取了，最大不能超过n
    a = a.substr(0, b.size());
    if (a == b)
      res += n - prefix * p + 1;
    else if (a > b)
      res += p;
    return res;
  }
  int findKthNumber(int n, int k) {
    int prefix = 1;
    while (k > 1) {
      int cnt = f(prefix, n);
      // cout << cnt << endl;
      if (k > cnt) {
        k -= cnt;
        prefix++;
      } else {
        k--;
        prefix *= 10;
      }
    }
    return prefix;
  }
};