class Solution {
 public:
  bool checkDistances(string s, vector<int>& distance) {
    vector<int> dis(26);
    unordered_map<char, int> st;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (st.count(s[i])) {
        dis[s[i] - 'a'] = i - st[s[i]] - 1;
      } else {
        st[s[i]] = i;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (!st.count('a' + i)) continue;
      if (distance[i] != dis[i]) return false;
    }
    return true;
  }
};
