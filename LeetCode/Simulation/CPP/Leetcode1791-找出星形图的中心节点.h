class Solution {
 public:
  int findCenter(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<int> st(n + 1);
    for (auto& e : edges) {
      st[e[0]]++, st[e[1]]++;
    }
    for (int i = 1; i <= n; i++) {
      if (st[i] == n - 1) return i;
    }
    return -1;
  }
};