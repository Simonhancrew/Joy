#include <vector>

using namespace std;

class Solution {
 public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<vector<int>> f(numCourses, vector<int>(numCourses, 0));
    for (const auto& x : prerequisites) {
      f[x[0]][x[1]] = true;
    }
    for (int k = 0; k < numCourses; k++) {
      for (int i = 0; i < numCourses; i++) {
        for (int j = 0; j < numCourses; j++) {
          if (f[i][k] && f[k][j]) {
            f[i][j] = true;
          }
        }
      }
    }
    vector<bool> ans;
    ans.reserve(queries.size());
    for (const auto& x : queries) {
      ans.push_back(f[x[0]][x[1]]);
    }
    return ans;
  }
};
