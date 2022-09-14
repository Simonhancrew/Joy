class Solution {
 public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size(), suma = accumulate(rolls.begin(), rolls.end(), 0);
    int sum = (m + n) * mean;
    int sumb = sum - suma;
    int ev = sumb / n, lf = sumb % n;
    if (ev < 1 || ev > 6) return vector<int>{};
    if (ev == 6 && lf) return vector<int>{};
    vector<int> res(n, ev);
    for (int i = 0; i < lf; i++) res[i]++;
    return res;
  }
};