class Solution {
 public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> st;
    for (auto &s : emails) {
      string t;
      bool flag = true;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.' && flag) continue;
        if (s[i] == '@') {
          flag = false;
          t += s.substr(i);
          break;
        } else if (s[i] == '+' && flag) {
          while (s[i] != '@') i++;
          t += s.substr(i);
          break;
        }
        t += s[i];
      }
      st.insert(t);
    }
    return st.size();
  }
};