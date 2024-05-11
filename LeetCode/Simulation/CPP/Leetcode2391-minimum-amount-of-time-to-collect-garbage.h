#include <array>
#include <numeric>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int garbageCollection(vector<string> &garbage, vector<int> &travel) {
    int ans = garbage[0].size();
    int travel_sum = 0;
    array<int, 3> strive{};
    int n = garbage.size();
    unordered_map<char, int> mp = {{'M', 0}, {'P', 1}, {'G', 2}};
    for (int i = 1; i < n; i++) {
      ans += garbage[i].size();
      travel_sum += travel[i - 1];
      for (const auto x : garbage[i]) {
        strive[mp[x]] = travel_sum;
      }
    }
    return ans + reduce(strive.begin(), strive.end());
  }
};