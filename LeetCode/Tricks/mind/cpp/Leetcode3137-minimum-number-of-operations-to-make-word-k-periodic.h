#include <string>
#include <unordered_map>


using namespace std;

class Solution {
public:
  int minimumOperationsToMakeKPeriodic(string word, int k) {
    int n = word.size();
    flat_map<string, int> mp;
    for (int i = 0; i < n; i += k) {
      mp[word.substr(i, k)]++;
    }
    int mx = 0;
    for (const auto [_, v] : mp) {
      mx = max(mx, v);
    }
    return n / k - mx;
  }
};
