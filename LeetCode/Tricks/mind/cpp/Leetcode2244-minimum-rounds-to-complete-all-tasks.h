#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumRounds(vector<int> &tasks) {
    unordered_map<int, int> mp;
    for (const auto x : tasks) {
      mp[x]++;
    }
    int ans = 0;
    for (const auto &[k, v] : mp) {
      if (v == 1) {
        return -1;
      }
      ans += (v + 2) / 3;
    }
    return ans;
  }
};
