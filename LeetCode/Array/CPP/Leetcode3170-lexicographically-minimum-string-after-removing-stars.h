class Solution {
 public:
  string clearStars(string s) {
    vector<stack<int>> cnt(26, stack<int>{});
    unordered_set<int> st;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        for (int j = 0; j < 26; ++j) {
          if (!cnt[j].empty()) {
            auto idx = cnt[j].top();
            cnt[j].pop();
            st.insert(idx);
            break;
          }
        }
      } else {
        auto c = s[i] - 'a';
        cnt[c].push(i);
      }
    }
    string res;
    for (const auto c : st)
      cout << c << '\n';
    for (int i = 0; i < n; i++) {
      if (st.count(i) || s[i] == '*')
        continue;
      res += s[i];
    }
    return res;
  }
};
