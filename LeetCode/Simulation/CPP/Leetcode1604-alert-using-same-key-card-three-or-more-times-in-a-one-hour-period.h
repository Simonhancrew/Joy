#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    vector<string> ans;
    map<string, vector<int>> mp;
    int n = keyName.size();
    for (int i = 0; i < n; i++) {
      int h = (keyTime[i][0] - '0') * 10 + (keyTime[i][1] - '0');
      int m = (keyTime[i][3] - '0') * 10 + (keyTime[i][4] - '0');
      mp[keyName[i]].push_back(h * 60 + m);
    }
    for (auto& [k, v] : mp) {
      sort(v.begin(), v.end());
      int cnt = v.size();
      for (int i = 2; i < cnt; i++) {
        int dif = v[i] - v[i - 2];
        if (dif <= 60) {
          ans.push_back(k);
          break;
        }
      }
    }
    return ans;
  }
};
