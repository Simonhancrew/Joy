#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
  string bestHand(vector<int>& ranks, vector<char>& suits){
    unordered_map<int, int> mp;
    bool ju = false;
    int n = ranks.size(), cnt = 1;
    for (int i = 0;i < n;i++) {
      mp[ranks[i]]++;
      if (mp[ranks[i]] >= 3) ju = true;
      if (i > 0 && suits[i] == suits[i - 1]) {
        cnt++;
      } else {
        cnt = 1;
      }
    }
    if (cnt == 5) return "Flush";
    if (ju) return "Three of a Kind";
    for (const auto& [k, v] : mp) {
      if (v == 2) {
        return "Pair";
      }
    }
    return "High Card";
  }
};
