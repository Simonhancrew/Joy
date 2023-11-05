#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if (s.size() <= 10) {
      return {};
    }
    unordered_map<string, int> rec;
    int n = s.size();
    rec[s.substr(0, 10)] = 1;
    for (int i = 1; i + 9 < n; i++) {
      auto cur = s.substr(i, 10);
      if (rec.count(cur) && rec[cur] == 1) {
        rec[cur] += 1;
        ans.push_back(std::move(cur));
      } else if (!rec.count(cur)) {
        rec[cur] = 1;
      }
    }
    return ans;
  }
};
