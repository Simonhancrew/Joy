#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom,
                              vector<int> &moveTo) {
    set<int> st{nums.begin(), nums.end()};
    int n = moveFrom.size();
    for (int i = 0; i < n; ++i) {
      if (st.count(moveFrom[i])) {
        st.insert(moveTo[i]);
        if (moveFrom[i] != moveTo[i]) {
          st.erase(moveFrom[i]);
        }
      }
    }
    return {st.begin(), st.end()};
  }
};
