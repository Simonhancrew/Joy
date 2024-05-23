#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
  int maxVowels(string s, int k) {
    int l = 0;
    int n = s.size();
    int cnt = 0, ans = 0;
    for (int r = 0; r < n; r++) {
      if (r - l + 1 > k) {
        if (st.contains(s[l])) {
          cnt--;
        }
        l++;
      }
      if (st.contains(s[r]))
        ++cnt;
      if (r - l + 1 == k) {
        ans = max(ans, cnt);
      }
    }
    return ans;
  }
};
