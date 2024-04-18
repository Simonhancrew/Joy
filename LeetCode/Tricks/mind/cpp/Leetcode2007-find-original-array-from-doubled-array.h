#include <unordered_map>
#include <vector>


using namespace std;

// 消除的思路: 统计每个数，然后用每个数去消除后面更大的数，如果消除不了就返回空
// 消除的时候要注意0，0可以消除任何数，但是0的个数要是偶数个
// 大的数一定是可以被小的数消除的，除非没有小的数

class Solution {
public:
  vector<int> findOriginalArray(vector<int> &changed) {
    int n = changed.size();
    if (n & 1)
      return {};
    unordered_map<int, int> mp;
    for (const auto x : changed) {
      mp[x]++;
    }
    vector<int> ans;
    ans.reserve(n / 2);
    int c0 = mp[0];
    if (c0 & 1) {
      return {};
    }
    ans.insert(ans.end(), mp[0] / 2, 0);
    mp.erase(0);
    for (const auto &[k, v] : mp) {
      if (k % 2 == 0 && mp.contains(k / 2)) {
        continue;
      }
      int x = k;
      while (mp.contains(x)) {
        int cnt = mp[x];
        if(!mp.contains(x * 2)) {
          return {};
        }
        if (cnt > mp[x * 2]) {
          return {};
        }
        ans.insert(ans.end(), cnt, x);
        if (cnt < mp[x * 2]) {
          mp[x * 2] -= cnt;
          x *= 2;
        } else {
          x *= 4;
        }
      }
    }
    return ans;
  }
};
