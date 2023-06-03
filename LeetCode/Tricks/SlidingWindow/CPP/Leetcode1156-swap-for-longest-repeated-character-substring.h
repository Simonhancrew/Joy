#include <string>
#include <vector>

using namespace std;

// 只有两种可能，同种字母在一个区间内，中间没有空格，这种看看前后有没有可以增补的可以替换边缘两个
// 非同种字母就可以了
// 第二种可能是一个区间，中间恰好一个不是同种字母，分成了两个区间，这种同理看看有没有前后可以增补替换的就可以
// 为了方便处理，直接将所有同种字母的小标聚合起来做滑动窗口就可以了

class Solution {
 public:
  int maxRepOpt1(string text) {
    vector<int> f[26]{};
    for (int i = 0; i < text.size(); i++) {
      f[text[i] - 'a'].push_back(i);
    }
    int res = 0;
    for (const auto& p : f) {
      if (p.empty()) continue;
      // 中间空位
      for (int i = 0, j = 0; i < p.size(); i++) {
        while (p[i] - p[j] > i - j + 1) j++;
        if (i + 1 < p.size() || j) {
          res = max(res, p[i] - p[j] + 1);
        }
      }
      // 中间不空位
      for (int i = 0, j = 0; i < p.size(); i++) {
        while (p[i] - p[j] > i - j) j++;
        int cur = p[i] - p[j] + 1;
        if (i + 1 < p.size() || j) ++cur;
        res = max(res, cur);
      }
    }
    return res;
  }
};
