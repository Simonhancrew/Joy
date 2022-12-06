#include <unordered_set>

using namespace std;

class Solution {
 public:
  int numDifferentIntegers(string word) {
    unordered_set<string> st;
    int n = word.size();
    auto check = [](char c) {
      if (c >= '0' && c <= '9') return true;
      return false;
    };
    for (int i = 0; i < n; i++) {
      if (!check(word[i])) continue;
      int j = i + 1;
      while (j < n && check(word[j])) j++;
      while (i < j - 1 && word[i] == '0') i++;
      auto s = word.substr(i, j - i);
      // cout << s << endl;
      st.insert(s);
      i = j - 1;
    }
    return st.size();
  }
};