#include <algorithm>
#include <array>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  string rankTeams(vector<string> &votes) {
    if (votes.size() == 1) {
      return std::move(votes.front());
    }
    unordered_map<char, array<int, 26>> rec;
    for (const auto &v : votes) {
      for (int i = 0; i < v.size(); i++) {
        rec[v[i]][i]++;
      }
    }
    string ans = std::move(votes[0]);
    sort(ans.begin(), ans.end(), [&](char l, char r) {
      return (rec[l] == rec[r] && l < r) || (rec[l] > rec[r]);
    });
    return ans;
  }
};
