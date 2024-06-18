#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
  string discountPrices(string s, int discount) {
    string ans, cur;
    stringstream ss(s);
    double d = 1 - discount / 100.0;
    while (ss >> cur) {
      if (!ans.empty()) {
        ans += ' ';
      }
      if (cur.size() > 1 && cur[0] == '$' &&
          all_of(cur.begin() + 1, cur.end(), ::isdigit)) {
        stringstream s;
        s << fixed << setprecision(2) << "$" << stoll(cur.substr(1)) * d;
        ans += s.str();
      } else {
        ans += cur;
      }
    }
    return ans;
  }
};

#if 0 
class Solution {
public:
  string discountPrices(string s, int discount) {
    int n = s.size();
    string ans;
    double d = 1 - discount / 100.0;
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j < n && s[j] != ' ') {
        j++;
      }
      auto cur = s.substr(i, j - i);
      if (!ans.empty())
        ans += " ";
      if (cur.size() > 1 && cur[0] == '$' &&
          all_of(cur.begin() + 1, cur.end(), ::isdigit)) {
        std::ostringstream oss;
        oss << "$" << fixed << setprecision(2) << stoll(cur.substr(1)) * d;
        ans += oss.str();
      } else {
        ans += cur;
      }
      i = j;
    }
    return ans;
  }
};
#endif
