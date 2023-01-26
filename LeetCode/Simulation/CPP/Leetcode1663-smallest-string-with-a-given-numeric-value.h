// last -> begin
class Solution {
 public:
  string getSmallestString(int n, int k) {
    if (k == n) {
      return string(n, 'a');
    }
    if (k == 26 * n) {
      return string(n, 'z');
    }
    string last;
    int left = k;
    for (int i = n - 1; i >= 0; i--) {
      int mx = left - i;
      if (mx > 26) {
        last += 'z';
        left -= 26;
      } else {
        last += 'a' + (mx - 1);
        left -= mx;
        break;
      }
    }
    reverse(last.begin(), last.end());
    if (left) last = string(left, 'a') + last;
    return last;
  }
};