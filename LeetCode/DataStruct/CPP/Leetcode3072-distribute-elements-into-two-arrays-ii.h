#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> tr1, tr2;
  void add(int x, vector<int> &tree) {
    while (x < tree.size()) {
      tree[x] += 1;
      x += x & -x;
    }
  }

  int ask(int x, vector<int> &tree) {
    int res = 0;
    while (x > 0) {
      res += tree[x];
      x -= x & -x;
    }
    return res;
  }

  vector<int> resultArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> x1{nums[0]}, x2{nums[1]};
    auto sorted = nums;
    ranges::sort(sorted);
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int m = sorted.size();
    tr1.resize(m + 1), tr2.resize(m + 1);
    add(ranges::lower_bound(sorted, nums[0]) - sorted.begin() + 1, tr1);
    add(ranges::lower_bound(sorted, nums[1]) - sorted.begin() + 1, tr2);
    for (int i = 2; i < n; i++) {
      int x = nums[i];
      int v = ranges::lower_bound(sorted, x) - sorted.begin() + 1;
      int gc1 = x1.size() - ask(v, tr1);
      int gc2 = x2.size() - ask(v, tr2);
      if (gc1 > gc2 || gc1 == gc2 && x1.size() <= x2.size()) {
        x1.push_back(x);
        add(v, tr1);
      } else {
        x2.push_back(x);
        add(v, tr2);
      }
    }
    x1.insert(x1.end(), x2.begin(), x2.end());
    return x1;
  }
};
