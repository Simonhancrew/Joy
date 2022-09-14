#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    排序的思路，从大到小,defence从小到d大
    相等atta的一组不可能有弱者，只能去下一组找垃圾的
    记录前面一组的max就可以了
*/

class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>> &ps) {
    sort(ps.begin(), ps.end(), [](vector<int> &lhs, vector<int> &rhs) {
      if (lhs[0] == rhs[0]) return lhs[1] > rhs[1];
      return lhs[0] > rhs[0];
    });
    int ans = 0, n = ps.size();
    for (int i = 0, mx = ps[i][1]; i < n;) {
      int cur = mx, j = i;
      while (j < n && ps[i][0] == ps[j][0]) {
        if (i != 0 && ps[j][1] < mx) ans++;
        cur = max(cur, ps[j][1]);
        j++;
      }
      mx = cur, i = j;
    }
    return ans;
  }
};