#include <vector>

using namespace std;

class Solution {
public:
  vector<int> canSeePersonsCount(vector<int> &heights) {
    int n = heights.size();
    vector<int> ans(n);
    vector<int> st;
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && st.back() < heights[i]) {
        st.pop_back();
        ans[i]++;
      }
      if (!st.empty())
        ans[i]++;
      st.push_back(heights[i]);
    }
    return ans;
  }
};
