class Solution {
public:
  int findWinningPlayer(vector<int> &skills, int k) {
    int ans = 0, win = 0;
    for (int i = 1; i < skills.size() && win < k; ++i) {
      if (skills[i] > skills[ans]) {
        ans = i;
        win = 0;
      }
      ++win;
    }
    return ans;
  }
};
