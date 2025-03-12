class Solution {
 public:
  unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
  using LL = long long;
  LL f(const std::string &s, int k) {
    int cnt = 0;
    unordered_map<char, int> mp;
    int l  = 0;
    LL ans = 0;
    for (auto c : s) {
      if (st.contains(c)) {
        mp[c]++;
      } else {
        cnt += 1;
      }
      while (mp.size() == 5 && cnt >= k) {
        if (st.contains(s[l])) {
          mp[s[l]]--;
          if (mp[s[l]] == 0) {
            mp.erase(s[l]);
          }
        } else {
          cnt -= 1;
        }
        ++l;
      }
      ans += l;
    }
    return ans;
  }
  long long countOfSubstrings(string word, int k) {
    return f(word, k) - f(word, k + 1);
  }
};
