#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  unordered_map<string, string> mp = {{"&quot;", "\""}, {"&apos;", "'"},
                                      {"&amp;", "&"},   {"&gt;", ">"},
                                      {"&lt;", "<"},    {"&frasl;", "/"}};
  string entityParser(string text) {
    string ans;
    int n = text.size();
    for (int i = 0; i < n; i++) {
      if (text[i] != '&') {
        ans += text[i];
      } else {
        int j = i;
        while (j < n && text[j] != ';') j++;
        if (j == n) {
          ans += text[i];
          continue;
        }
        auto s = text.substr(i, j - i + 1);
        if (mp.count(s)) {
          ans += mp[s];
        } else {
          ans += text[i];
          continue;
        }
        i = j;
      }
    }
    return ans;
  }
};
