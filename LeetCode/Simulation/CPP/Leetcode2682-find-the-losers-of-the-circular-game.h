#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> circularGameLosers(int n, int k) {
    vector<int> res;
    unordered_set<int> st;
    int id = 0, cnt = 1;
    while (true) {
      if (st.count(id)) break;
      st.insert(id);
      id = (id + cnt * k) % n;
      cnt++;
    }
    for (int i = 0; i < n; i++) {
      if (!st.count(i)) {
        res.push_back(i + 1);
      }
    }
    return res;
  }
};
