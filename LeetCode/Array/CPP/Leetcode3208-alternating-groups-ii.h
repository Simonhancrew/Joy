class Solution {
 public:
  int numberOfAlternatingGroups(vector<int> &colors, int k) {
    int n = colors.size();
    colors.insert(colors.end(), colors.begin(), colors.end());
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n + k - 1; i++) {
      if (i > 0 && colors[i] == colors[i - 1]) {
        cnt = 0;
      }
      cnt += 1;
      if (cnt >= k) {
        ans += 1;
      }
    }
    return ans;
  }
};
