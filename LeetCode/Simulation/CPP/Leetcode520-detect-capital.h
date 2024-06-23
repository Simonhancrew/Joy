#include <string>

using namespace std;

class Solution {
public:
  bool detectCapitalUse(string word) {
    int n = word.size();
    bool first = isupper(word[0]);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += isupper(word[i]) ? 1 : 0;
    }
    return cnt == 0 || cnt == n || cnt == 1 && first;
  }
};
