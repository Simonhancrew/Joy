#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  int splitNum(int num) {
    string s = to_string(num);
    sort(s.begin(), s.end());
    int n = s.size();
    int a[2]{};
    for (int i = 0; i < n; i++) {
      a[i % 2] = a[i % 2] * 10 + s[i] - '0';
    }
    return a[0] + a[1];
  }
};
