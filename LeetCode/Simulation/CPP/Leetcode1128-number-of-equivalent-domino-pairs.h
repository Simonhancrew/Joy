class Solution {
 public:
  using PII = pair<int, int>;
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    int ans = 0;
    map<PII, int> mp;
    for (int i = 0; i < dominoes.size(); i++) {
      PII tmp = {dominoes[i][0], dominoes[i][1]};
      // cout << tmp.first << ' ' << tmp.second << "-->";
      ans += mp[tmp];
      if (tmp.first != tmp.second) {
        swap(tmp.first, tmp.second);
        // cout << tmp.first << ' ' << tmp.second << '\n';
        ans += mp[tmp];
      }
      mp[tmp]++;
    }
    return ans;
  }
};
