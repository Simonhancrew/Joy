import <string>;
import <vector>;
import <unordered_map>;

using namespace std;

class Solution {
public:
  int maximumNumberOfStringPairs(vector<string> &words) {
    unordered_set<string> st;
    int ans{};
    for (auto &s : words) {
      if (st.count(s))
        ans++;
      reverse(s.begin(), s.end());
      st.insert(s);
    }
    return ans;
  }
};
