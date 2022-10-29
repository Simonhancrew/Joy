#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int ans = 0, key = 0, n = items.size();
    if (ruleKey == "color")
      key = 1;
    else if (ruleKey == "name")
      key = 2;
    for (int i = 0; i < n; i++) {
      if (items[i][key] == ruleValue) ans++;
    }
    return ans;
  }
};