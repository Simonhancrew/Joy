#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<int> in(numCourses);
    unordered_map<int, unordered_set<int>> g;
    for (const auto& p : prerequisites) {
      int x = p[0], y = p[1];
      in[x]++;
      g[y].insert(x);
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (in[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      auto x = q.front();
      q.pop();
      ans.push_back(x);
      for (const auto ne : g[x]) {
        in[ne]--;
        if (in[ne] == 0) {
          q.push(ne);
        }
      }
    }
    if (ans.size() == numCourses) {
      return ans;
    }
    ans.clear();
    return ans;
  }
};
