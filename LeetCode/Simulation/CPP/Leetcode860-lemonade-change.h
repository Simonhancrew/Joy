#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    unordered_map<int, int> mp;
    for (const auto x : bills) {
      if (x == 5)
        mp[5]++;
      else if (x == 10) {
        if (mp[5] == 0) return false;
        mp[5]--, mp[10]++;
      } else {
        if ((mp[10] < 1 || mp[5] < 1) && mp[5] < 3) {
          return false;
        }
        if (mp[10] && mp[5])
          mp[10]--, mp[5]--;
        else
          mp[5] -= 3;
        mp[20]++;
      }
    }
    return true;
  }
};
