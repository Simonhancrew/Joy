class Solution {
 public:
  using LL               = long long;
  unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
  LL f(const std::string &s, int k) {
    unordered_map<char, int> mp;
    auto check = [&mp]() {
      if (mp.size() != 5) {
        return false;
      }
      for (const auto &[_, v] : mp) {
        if (v == 0) {
          return false;
        }
      }
      return true;
    };
    int cnt = 0;
    LL ans  = 0;
    int l   = 0;
    for (const auto c : s) {
      if (st.contains(c)) {
        mp[c]++;
      } else {
        cnt++;
      }
      while (cnt >= k && check()) {
        if (st.contains(s[l])) {
          mp[s[l]]--;
        } else {
          cnt--;
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
