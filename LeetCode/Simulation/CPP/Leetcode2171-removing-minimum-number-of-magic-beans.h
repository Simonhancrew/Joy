#include <ranges>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  using LL = long long;
  long long minimumRemoval(vector<int> &beans) {
    ranges::sort(beans);
    LL sum{};
    LL mx{};
    int n = beans.size();
    for (int i = 0; i < n; i++) {
      sum += beans[i];
      mx = max(mx, (LL)beans[i] * (n - i));
    }
    return sum - mx;
  }
};
