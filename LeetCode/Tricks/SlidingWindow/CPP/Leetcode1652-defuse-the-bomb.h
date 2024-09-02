#include <vector>

using namespace std;

class Solution {
public:
  vector<int> decrypt(vector<int> &code, int k) {
    if (k == 0) {
      return vector<int>(code.size(), 0);
    }
    int cnt = k;
    if (k < 0) {
      reverse(code.begin(), code.end());
      cnt = -k;
    }
    int n = code.size();
    for (int i = 0; i < n; i++) {
      code.push_back(code[i]);
    }
    int acc = 0;
    for (int i = 0; i < n + cnt; i++) {
      acc += code[i];
      if (i < cnt)
        continue;
      int tmp = code[i - cnt];
      code[i - cnt] = acc - tmp;
      acc -= tmp;
    }
    auto res = vector<int>{code.begin(), code.begin() + n};
    if (k < 0) {
      reverse(res.begin(), res.end());
    }
    return res;
  }
};
