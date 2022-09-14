class Solution {
 public:
  int countGoodRectangles(vector<vector<int>>& rectangles) {
    map<int, int> st;
    for (auto& edge : rectangles) {
      st[min(edge[0], edge[1])]++;
    }
    return st.rbegin()->second;
  }
};