#include <string>

using namespace std;

class Solution {
public:
  int minimumOperations(string num) {
    int n = num.size();
    bool f0 = false, f5 = false;
    for (int i = n - 1; i >= 0; i--) {
      if ((f0 && (num[i] == '0' || num[i] == '5')) ||
          (f5 && (num[i] == '2' || num[i] == '7'))) {
        return n - i - 2;
      }
      if (num[i] == '0')
        f0 = true;
      else if (num[i] == '5')
        f5 = true;
    }
    return f0 ? n - 1 : n;
  }
};

#if 0

class Solution {
public:
  int minimumOperations(string num) {
    int n = num.size();
    int ans = (num.find('0') == string::npos ? n : n - 1);
    auto f = [&](const char *s) -> int {
      auto rs = num.rfind(s[1]);
      if (rs == 0 || rs == string::npos) {
        return n;
      }
      auto ls = num.rfind(s[0], rs - 1);
      if (ls == string::npos) {
        return n;
      }
      return n - ls - 2;
    };
    static const std::array<const char *, 4> tar = {"00", "25", "50", "75"};
    for (const auto &x : tar) {
      ans = min(ans, f(x));
    }
    return ans;
  }
};

#endif
