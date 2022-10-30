#include <unordered_set>
#include <vector>
#include <string>
#include <functional>

using namespace std;


class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    int n = s.size();
    vector<string> ans;
    std::function<void(int)> dfs = [&](int idx) {
      if (idx == s.size()) {
        ans.emplace_back(s);
        return;
      }
      bool flag = true;
      if (isdigit(s[idx])) {
        dfs(idx + 1);
        flag = false;
      } else if (isupper(s[idx])) {
        s[idx] = tolower(s[idx]);
        dfs(idx + 1);
        s[idx] = toupper(s[idx]);
      } else if (islower(s[idx])) {
        s[idx] = toupper(s[idx]);
        dfs(idx + 1);
        s[idx] = tolower(s[idx]);
      }
      if (flag) dfs(idx + 1);
    };
    dfs(0);
    return ans;
  }
};