class Solution {
 public:
  int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> mp(26);
    int n = s.size();
    for (int i = 0; i < n; i++) {
      mp[s[i] - 'a'].push_back(i);
    }
    int ans = words.size();
    for (auto x : words) {
      if (x.size() > s.size()) {
        ans--;
        continue;
      }
      int idx = -1;
      for (auto c : x) {
        auto& arr = mp[c - 'a'];
        auto it = upper_bound(arr.begin(), arr.end(), idx);
        if (it == arr.end()) {
          ans--;
          break;
        }
        idx = *it;
      }
    }
    return ans;
  }
};