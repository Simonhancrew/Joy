#include <unordered_set>

using namespace std;

// 算mod就行，(x * 10 + 1） % k，x是111和111 %
// k没有区别，重复出现会进入一个循环，没有意义
class Solution {
 public:
  int smallestRepunitDivByK(int k) {
    if (k == 1) return 1;
    unordered_set<int> st;
    int num = 1, len = 1;
    while (true) {
      num = (num * 10 + 1) % k;
      len++;
      if (num == 0) {
        return len;
      } else if (st.count(num)) {
        break;
      }
      st.insert(num);
    }
    return -1;
  }
};
