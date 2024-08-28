#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/*
  定长滑动窗口，分三步
    1. 入，进入窗口，更新统计值，如果还没到窗口，就重复步骤1
    2. 更新，达到了定长的窗口，更新答案
    3. 这次结束之后，下表位i - d + 1的位置要离开窗口，处理掉，更新当前值
*/

class Solution {
public:
  unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
  int maxVowels(string s, int k) {
    int cur = 0, ans = 0, n = s.size(); // NOLINT
    for (int i = 0; i < n; i++) {
      if (st.count(s[i])) {
        cur++;
      }
      if (i < k - 1) {
        continue;
      }
      ans = max(ans, cur);
      char out = s[i - k + 1];
      if (st.count(out)) {
        cur--;
      }
    }
    return ans;
  }
};
