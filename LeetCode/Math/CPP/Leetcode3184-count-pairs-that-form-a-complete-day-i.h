#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int countCompleteDayPairs(vector<int> &hours) {
    int ans = 0;
    unordered_map<int, int> mp;
    for (const auto x : hours) {
      ans += mp[x % 24];
      mp[(24 - (x % 24)) % 24]++;
    }
    return ans;
  }
};
