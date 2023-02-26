#include <vector>
#include <array>
#include <string>

using namespace std;

class Solution {
 public:
  int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    array<int, 26> rec{};
    for (const auto& c : letters) rec[c - 'a']++;
    int n = words.size();
    int res = 0;
    for (int i = 0; i < 1 << n; i++) {
      array<int, 26> cur{};
      for (int j = 0; j < n; j++) {
        if (i >> j & 1) {
          for (const auto& c : words[j]) {
            cur[c - 'a']++;
          }
        }
      }
      bool flag = true;
      for (int k = 0; k < 26; k++) {
        if (cur[k] > rec[k]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        int tmp = 0;
        for (int k = 0; k < 26; k++) {
          tmp += score[k] * cur[k];
        }
        res = max(res, tmp);
      }
    }
    return res;
  }
};