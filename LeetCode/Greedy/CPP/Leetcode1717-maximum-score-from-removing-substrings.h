// 优先选大的，碰到非ab就把小的全删了算积分，然后重新开始计
class Solution {
 public:
  int maximumGain(string s, int x, int y) {
    char a = 'a', b = 'b';
    if (x < y) {
      swap(a, b);
      swap(x, y);
    }
    int cnt1 = 0, cnt2 = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == a) {
        cnt1++;
      } else if (s[i] == b) {
        if (cnt1) {
          cnt1--;
          ans += x;
          continue;
        }
        cnt2++;
      } else {
        ans += min(cnt1, cnt2) * y;
        cnt1 = 0;
        cnt2 = 0;
      }
    }
    ans += min(cnt1, cnt2) * y;
    return ans;
  }
};
