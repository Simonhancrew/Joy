class Solution {
 public:
  vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k) {
    sort(score.begin(), score.end(), [k](auto &lhs, auto &rhs) {
      return lhs[k] > rhs[k];
    });
    return move(score);
  }
};
