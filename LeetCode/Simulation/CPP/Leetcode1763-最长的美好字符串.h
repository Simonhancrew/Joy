#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  string longestNiceSubstring(string s) {
    int n = s.size();
    string ans;
    for (int len = 1; len <= n; len++) {
      for (int l = 0; l + len - 1 < n; l++) {
        int r = len + l - 1;
        string t = s.substr(l, len);
        if (check(t) && ans.size() < t.size()) ans = t;
      }
    }
    return ans;
  }
  bool check(string const &t) {
    unordered_set<char> st;
    for (int i = 0; i < t.size(); i++) st.insert(t[i]);
    for (auto ch : st) {
      char low = tolower(ch), big = toupper(ch);
      if (!st.count(low) || !st.count(big)) return false;
    }
    return true;
  }
};