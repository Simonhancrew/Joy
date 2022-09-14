#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
    网格很大，直接hash存可能的行列还有对角线就行了
    对角线可以用截距表示
*/

class Solution {
 public:
  vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                               vector<vector<int>>& queries) {
    unordered_map<int, unordered_set<int>> row, col, dg, udg;
    for (auto& light : lamps) {
      int x = light[0], y = light[1];
      row[x].insert(y);
      col[y].insert(x);
      dg[y - x].insert(x);
      udg[x + y].insert(x);
    }
    vector<int> ans;
    for (auto& query : queries) {
      int x = query[0], y = query[1];
      if (row[x].size() || col[y].size() || dg[y - x].size() ||
          udg[y + x].size()) {
        ans.push_back(1);
        for (int i = x - 1; i <= x + 1; i++) {
          for (int j = y - 1; j <= y + 1; j++) {
            row[i].erase(j);
            col[j].erase(i);
            dg[j - i].erase(i);
            udg[i + j].erase(i);
          }
        }
      } else {
        ans.push_back(0);
      }
    }
    return ans;
  }
};