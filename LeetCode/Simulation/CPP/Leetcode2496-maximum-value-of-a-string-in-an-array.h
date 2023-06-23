#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool check(const string& s) {
    for (const auto c : s) {
      if (c < '0' || c > '9') return true;
    }
    return false;
  }

  int maximumValue(vector<string>& strs) {
    int ans = 0;
    for (const auto& s : strs) {
      if (check(s)) {
        ans = max(ans, static_cast<int>(s.size()));
      } else {
        ans = max(ans, stoi(s));
      }
    }
    return ans;
  }
};
