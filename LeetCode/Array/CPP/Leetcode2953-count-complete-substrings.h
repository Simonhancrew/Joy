#include <array>
#include <string>

using namespace std;

// 1. 先筛选出合法间隔字段，相邻字符之间差距不会大于2
// 2. 针对每个slice，最多只有26个字符，枚举出现字符的个数m = [1, 26]，其长度m * k, 在这个长度中做滑窗
// 3. 统计合乎条件的窗口数量
// 这一类的题目=枚举字符种类数 + 滑窗

class Solution {
 public:
  int countCompleteSubstrings(string s, int k) {
    int ans = 0;
    int n = s.size();
    auto check = [](array<int, 26> arr, int x) {
      for (const auto c : arr) {
        if (c == 0 || c == x) {
          continue;
        }
        return false;
      }
      return true;
    };
    auto f = [&](int start, int end) {
      auto len = end - start + 1;
      int res = 0;
      for (int x = 1; x <= 26; x++) {
        auto size = x * k;
        if (size > len) {
          break;
        }
        array<int, 26> cnt{};
        for (int i = start; i < start + size; i++) {
          cnt[s[i] - 'a']++;
        }
        if (check(cnt, k)) {
          ++res;
        }
        for (int i = start + size, j = start; i <= end; i++, j++) {
          cnt[s[i] - 'a']++;
          cnt[s[j] - 'a']--;
          if (check(cnt, k)) {
            ++res;
          }
        }
      }
      return res;
    };
    for (int i = 0; i < n;) {
      int start = i;
      i += 1;
      while (i < n && abs(int(s[i]) - int(s[i - 1])) <= 2) {
        i++;
      }
      ans += f(start, i - 1);
    }
    return ans;
  }
};
