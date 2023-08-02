#include <unordered_set>
#include <vector>


using namespace std;

class Solution {
 public:
  int flipgame(vector<int>& fronts, vector<int>& backs) {
    int ans = INT_MAX;
    unordered_set<int> st;
    int n = fronts.size();
    for (int i = 0; i < n; ++i) {
      if (fronts[i] == backs[i]) st.insert(fronts[i]);
    }
    for (int i = 0; i < n; i++) {
      if (!st.count(fronts[i])) {
        ans = min(ans, fronts[i]);
      }
      if (!st.count(backs[i])) {
        ans = min(ans, backs[i]);
      }
    }
    if (ans == INT_MAX) return 0;
    return ans;
  }
};
