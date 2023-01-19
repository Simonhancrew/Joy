class Solution {
 public:
  bool strongPasswordCheckerII(string password) {
    if (password.size() < 8) return false;
    int n = password.size();
    bool lower{false}, upper{false}, num{false}, spe{false};
    string s = "!@#$%^&*()-+";
    unordered_set<char> st;
    for (auto c : s) st.insert(c);
    for (int i = 0; i < n; i++) {
      if (password[i] >= 'a' && password[i] <= 'z')
        lower = true;
      else if (password[i] >= 'A' && password[i] <= 'Z')
        upper = true;
      else if (password[i] >= '0' && password[i] <= '9')
        num = true;
      if (st.count(password[i])) spe = true;
      if (i + 1 < n && password[i + 1] == password[i]) return false;
    }
    return lower && upper && num && spe;
  }
};
