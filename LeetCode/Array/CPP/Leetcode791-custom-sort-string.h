#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  string customSortString(string order, string s) {
    vector<int> pa(26, 26);
    for (int i = 0; i < order.size(); i++) {
      pa[order[i] - 'a'] = i;
    }
    sort(s.begin(), s.end(), [&pa](auto lhs, auto rhs) { return pa[lhs - 'a'] < pa[rhs - 'a']; });
    return s;
  }
};