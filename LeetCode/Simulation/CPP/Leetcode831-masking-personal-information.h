class Solution {
 public:
  array<string, 4> country = {"", "+*-", "+**-", "+***-"};
  string maskPII(string s) {
    int pos = s.find('@');
    if (pos != string::npos) {
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      return s.substr(0, 1) + "*****" + s.substr(pos - 1);
    }
    s = regex_replace(s, regex("[^0-9]"), "");
    return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
  }
};