class Solution {
 public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                     vector<vector<string>>& people) {
    int n = req_skills.size(), m = people.size();
    unordered_map<string, int> skill;
    for (int i = 0; i < n; i++) skill[req_skills[i]] = 1 << i;
    vector<int> f(1 << n, m + 1), g(m);
    for (int i = 0; i < m; i++) {
      for (const auto& s : people[i]) {
        g[i] |= skill[s];
      }
    }
    using PII = pair<int, int>;
    vector<PII> path(1 << n);
    f[0] = 0;
    for (int i = 0; i < 1 << n; i++) {
      for (int j = 0; j < m; j++) {
        int& v = f[i | g[j]];
        if (v > f[i] + 1) {
          path[i | g[j]] = {i, j};
          v = f[i] + 1;
        }
      }
    }
    // cout << f[1 << n - 1] << endl;
    int st = (1 << n) - 1;
    vector<int> res;
    while (st) {
      res.push_back(path[st].second);
      st = path[st].first;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
