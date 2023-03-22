class Solution {
 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = scores.size();
    vector<pair<int, int>> rec(n);
    for (int i = 0; i < n; i++) rec[i] = make_pair(ages[i], scores[i]);
    sort(rec.begin(), rec.end());
    vector<int> f(n);
    int res = -1;
    for (int i = 0; i < n; i++) {
      f[i] = rec[i].second;
      for (int j = 0; j < i; j++) {
        if (rec[i].second >= rec[j].second) {
          f[i] = max(f[i], f[j] + rec[i].second);
        }
      }
      res = max(res, f[i]);
    }
    return res;
  }
};
