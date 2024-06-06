#include <string>

using namespace std;

// 逆序对， 每个0的贡献，每个0要和其左侧的1交换

class Solution {
public:
  using LL = long long;
  long long minimumSteps(string s) {
    int n = s.size();
    LL ans = 0;
    int cnt1 = 0;
    for (const auto x : s) {
      if (x == '1') {
        ++cnt1;
      } else {
        ans += cnt1;
      }
    }
    return ans;
  }
};
