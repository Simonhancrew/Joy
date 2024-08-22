#include <string>

using namespace std;

class Solution {
public:
  int divisorSubstrings(int num, int k) {
    auto s = to_string(num);
    int l = 0, ans = 0, n = s.size(); // NOLINT
    for (int i = k - 1; i < n; i++) {
      auto cur = stoi(s.substr(l, i - l + 1));
      if (cur && num % cur == 0) {
        ans++;
      }
      l++;
    }
    return ans;
  }
};
