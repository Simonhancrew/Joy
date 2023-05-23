class Solution {
 public:
  int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                            int numWanted, int useLimit) {
    using PII = pair<int, int>;
    vector<PII> rec;
    int n = values.size();
    for (int i = 0; i < n; i++) {
      rec.emplace_back(values[i], labels[i]);
    }
    sort(rec.begin(), rec.end(),
         [](const auto lhs, const auto rhs) { return lhs.first > rhs.first; });
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0, cnt = 0; i < n && cnt < numWanted; i++) {
      auto [k, v] = rec[i];
      if (mp[v] >= useLimit) continue;
      cout << k << ' ' << v << endl;
      mp[v] += 1;
      ans += k;
      cnt++;
    }
    return ans;
  }
};
