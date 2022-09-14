class Solution {
 public:
  string generateTheString(int n) {
    if (n % 2 == 0) {
      return string(n - 1, 'a') + 'b';
    }
    if (n == 1) return "a";
    return string(n - 2, 'a') + "b" + "c";
  }
};
