#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end());
    int l = 0, r = n;
    auto check = [&citations, n](int id) {
      auto it = lower_bound(citations.begin(), citations.end(), id);
      if (it == citations.end()) {
        return false;
      }
      auto cnt = n - (it - citations.begin());
      return cnt >= id;
    };
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }
};
