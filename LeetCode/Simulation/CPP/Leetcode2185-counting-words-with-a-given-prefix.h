class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    int ans = 0;
    auto check = [&](const string& word) {
      if (word.size() < pref.size()) return false;
      for (int i = 0; i < pref.size(); i++) {
        if (word[i] != pref[i]) return false;
      }
      return true;
    };
    for (auto& word : words) {
      if (check(word)) ans++;
    }
    return ans;
  }
};