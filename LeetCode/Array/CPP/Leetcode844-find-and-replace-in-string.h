#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  using PII = pair<int, int>;
  string findReplaceString(string s, vector<int>& indices,
                           vector<string>& sources, vector<string>& targets) {
    int k = indices.size();
    unordered_map<int, string> rec;
    unordered_map<int, int> range;
    for (int i = 0; i < k; i++) {
      int idx = indices[i];
      string& pa = sources[i];
      int n = pa.size();
      auto tar = s.substr(idx, n);
      if (tar != pa) {
        continue;
      }
      rec[idx] = std::move(targets[i]);
      range[idx] = n;
    }
    int n = s.size();
    string ans;
    for (int i = 0; i < n; i++) {
      if (!range.count(i)) {
        ans += s[i];
      } else {
        ans += rec[i];
        i += range[i] - 1;
      }
    }
    return ans;
  }
};
