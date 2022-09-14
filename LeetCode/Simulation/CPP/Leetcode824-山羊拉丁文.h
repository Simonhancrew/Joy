class Solution {
 public:
  string toGoatLatin(string s) {
    string res, cur = "a";
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < s.size(); i++) {
      if (i) res += ' ';
      int j = i;
      while (j < s.size() && s[j] != ' ') j++;
      string tmp = s.substr(i, j - i);
      i = j;
      if (st.count(tmp[0]) || st.count(tolower(tmp[0]))) {
        res += tmp;
      } else {
        res += tmp.substr(1) + tmp[0];
      }
      res += "ma" + cur;
      cur += 'a';
    }
    return res;
  }
};