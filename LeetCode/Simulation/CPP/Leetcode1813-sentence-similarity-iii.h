#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
   using CVS = const vector<string>;
  void split(string &s, vector<string> &cs) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == ' ') continue;
      int j = i;
      while (j < n && s[j] != ' ') j++;
      cs.push_back(s.substr(i, j - i));
      i = j;
    }
  }

  bool checkmiddle(CVS &s1, CVS &s2) {
    int i = 0, j = s1.size() - 1, ii = 0, jj = s2.size() - 1;
    while (i <= j && s1[i] == s2[ii]) {
      i++, ii++;
    }
    while (i <= j && s1[j] == s2[jj]) {
      jj--, j--;
    }
    return i > j;
  }

  bool checksimilar(const vector<string> &s1, const vector<string> s2) {
    if (s1.size() > s2.size()) return checksimilar(s2, s1);
    return checkmiddle(s1, s2);
  }

  bool areSentencesSimilar(string &sentence1, string &sentence2) {
    vector<string> s1, s2;
    split(sentence1, s1);
    split(sentence2, s2);
    return checksimilar(s1, s2);
  }
};