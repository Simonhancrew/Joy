#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  static int minLength(string s) {
    vector<char> st;
    auto n = s.size();
    for (int i = 0; i < n; i++) {
      auto c = s[i];
      if (!st.empty() &&
          (c == 'B' && st.back() == 'A' || c == 'D' && st.back() == 'C')) {
        st.pop_back();
      } else {
        st.push_back(c);
      }
    }
    int res = static_cast<int> (st.size());
    return res;
  }
};
