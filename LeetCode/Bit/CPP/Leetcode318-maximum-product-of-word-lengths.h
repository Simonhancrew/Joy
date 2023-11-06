#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  static int get(const std::string& s) {
    int len = s.size();
    int res = 0;
    for (int i = 0; i < len; i++) {
      int x = s[i] - 'a';
      res |= (1 << x);
    }
    return res;
  }
  int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<int> rec(n);
    sort(words.begin(), words.end(), [](const auto& lhs, const auto& rhs) {
      return lhs.size() > rhs.size();
    });
    for (int i = 0; i < n; i++) {
      rec[i] = get(words[i]);
    }
    size_t ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((rec[i] & rec[j]) == 0) {
          ans = max(ans, words[i].size() * words[j].size());
        }
      }
    }
    return ans;
  }
};
