// 比较容易想到的是这个答案串一定是一个后缀子数组
// 后缀数组是比较好的解法， 但是这题只要求最大， 可以用字符串哈希 + 二分来求
// 遍历每个位置， 记录最大后缀， 如果最大后缀子数组能更新就更新， 不能继续遍历
// check函数找到两个不同位置a, b开始的后缀的第一个不同的位置做判断就可以
constexpr int N = 4e5 + 10, P = 13331;
using ULL = unsigned long long;
ULL p[N]{}, h[N]{};
class Solution {
 public:
  ULL get(int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; }
  string lastSubstring(string s) {
    int n = s.size();
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] * P;
      h[i] = h[i - 1] * P + s[i - 1];
    }
    int res = 1;
    auto check = [&s, n, this](int a, int b) {
      int l = 0, r = n - b + 1;
      while (l < r) {
        int mid = l + r + 1 >> 1;
        if (get(a, a + mid - 1) == get(b, b + mid - 1))
          l = mid;
        else
          r = mid - 1;
      }

      if (r == n - b + 1) return false;
      return s[a + r - 1] < s[b + r - 1];
    };
    for (int i = 2; i <= n; i++) {
      if (check(res, i)) {
        res = i;
      }
    }
    return s.substr(res - 1);
  }
};
