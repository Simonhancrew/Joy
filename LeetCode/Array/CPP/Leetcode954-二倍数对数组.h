#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

/*
    成组配对问题，直接按照从小到大排序就行了
    从左往右遍历，正数找他的两倍够不够删
    负数找他的1 / 2够不够删（此时要考虑奇偶性）
    也可以按照abs的序排，就保证了负数部分的从大到小排列
    这样可以按照和正数一个逻辑处理
*/

class Solution {
 public:
  bool canReorderDoubled(vector<int> &arr) {
    unordered_map<int, int> mp;
    vector<int> rec;
    for (auto &num : arr) mp[num]++;
    for (auto &[k, _] : mp) {
      rec.push_back(k);
    }
    sort(rec.begin(), rec.end(),
         [](int lhs, int rhs) { return abs(lhs) < abs(rhs); });
    for (auto x : rec) {
      if (mp[x * 2] < mp[x]) {
        return false;
      }
      mp[x * 2] -= mp[x];
    }
    return true;
  }
};