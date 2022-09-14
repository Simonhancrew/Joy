class Solution {
 public:
  int uniqueMorseRepresentations(vector<string> &words) {
    string pos[26] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                      "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                      "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                      "...-", ".--",  "-..-", "-.--", "--.."};
    unordered_set<string> st;
    for (auto &w : words) {
      string s;
      for (auto c : w) s += pos[c - 'a'];
      st.insert(s);
    }
    return st.size();
  }
};