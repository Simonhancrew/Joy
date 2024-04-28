#include <string>
#include <vector>

using namespace std;

// n = a[k] * base^k + a[k-1] * base^(k-1) + ... + a[1] * base + a[0]
// n % base = a[0] * (flag)
// n / base = a[k] * base^(k-1) + a[k-1] * base^(k-2) + ... + a[1]
// 做进制转换

class Solution {
public:
  string baseNeg2(int n) {
    if (!n) {
      return "0";
    }
    string res;
    int base = -2;
    while (n != 0) {
      int cur = abs(n % base);
      res.push_back('0' + cur);
      n = (n - cur) / base;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
