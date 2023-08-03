#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> removeComments(vector<string>& source) {
    string s;
    for (const auto& x : source) s += x + '\n';
    vector<string> ans;
    string cur;
    for (int i = 0; i < s.size();) {
      if (i + 1 < s.size() && s[i] == '/' && s[i + 1] == '/') {
        while (s[i] != '\n') ++i;
      } else if (i + 1 < s.size() && s[i] == '/' && s[i + 1] == '*') {
        i += 2;
        while (s[i] != '*' || s[i + 1] != '/') i++;
        i += 2;
      } else if (s[i] == '\n') {
        if (cur.size()) {
          ans.push_back(std::move(cur));
        }
        i++;
      } else {
        cur += s[i];
        ++i;
      }
    }
    return ans;
  }
};
