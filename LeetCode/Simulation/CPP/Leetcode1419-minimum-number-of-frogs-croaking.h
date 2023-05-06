#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


// cnt[k], 多少只青蛙发出了k叫声
// 当k来是，找前一个叫声，看看有无，没有的话且不是第一个，非法
// 否则接着前一个叫，然后给当前k叫声+=1
// 如果没有前面的叫声，且是第一个，说明要多加一直青蛙
class Solution {
 public:
  const string pa = "croak";
  int minNumberOfFrogs(string croakOfFrogs) {
    vector<int> pre(5), cnt(5);
    unordered_map<char, int> mp;
    for (int i = 0;i < 5;i++) mp[pa[i]] = i;
    string rev = "croakc";
    for (int i = 1; i < rev.size(); i++) {
      int idx = mp[rev[i]], last_idx = mp[rev[i - 1]];
      pre[idx] = last_idx;
    }
    for (const auto c : croakOfFrogs) {
      int idx = mp[c], last_idx = pre[idx];
      if (cnt[last_idx] != 0) {
        cnt[last_idx] -= 1;      
      } else if (idx != 0) {
        return -1;
      }
      cnt[idx] += 1;
    }
    for (int i = 0;i < 4;i++) {
      if (cnt[i]) return -1;
    }
    return cnt[4];
  }
};