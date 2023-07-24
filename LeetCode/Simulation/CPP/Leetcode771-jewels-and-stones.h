#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> st;
    for (const auto x : jewels) st.insert(x);
    int ans = 0;
    for (const auto x : stones) {
      if (st.count(x)) ++ans;
    }
    return ans;
  }
};
