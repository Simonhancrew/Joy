#include <string>

using namespace std;

class Solution {
public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int lhs = 0;
    int n = answerKey.size();
    int cnt[2]{};
    int ans = 0;
    for (int rhs = 0; rhs < n; rhs++) {
      if (answerKey[rhs] == 'T')
        cnt[0]++;
      else
        cnt[1]++;
      while (cnt[1] > k && cnt[0] > k) {
        auto c = answerKey[lhs++];
        if (c == 'T')
          cnt[0]--;
        else
          cnt[1]--;
      }
      ans = max(ans, rhs - lhs + 1);
    }
    return ans;
  }
};
