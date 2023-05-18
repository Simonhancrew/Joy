#include <vector>
#include <algorithm>

using namespace std;

// a[i] * (-2)^k + b[i] * (-2)^k,如果进位的话 => 2 * (-2) ^ k = -(-2)^(k + 1) = (1 - 2) * (-2)^(k + 1) = (-2)^(k + 2) + (-2)^(k + 1)
// 特殊的针对无穷进位(-2)^(k + 2)可以和2 * (-2)^(k + 1)抵消，特判一下 
class Solution {
 public:
  vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());
    int n = arr1.size(), m = arr2.size();
    vector<int> ans;
    for (int i = 0, a = 0, b = 0, c = 0; i < n || i < m || a || b; i++) {
      if (a == 1 && b == 2) a = b = 0;
      c = b, b = a, a = 0;
      if (i < n) c += arr1[i];
      if (i < m) c += arr2[i];
      ans.push_back(c & 1);
      c >>= 1;
      a += c, b += c;
    }
    while (ans.size() > 1 && !ans.back()) ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
