class Solution {
 public:
  bool checkPowersOfThree(int n) {
    if (n == 3 || n == 1) return true;
    if (n % 3 > 1) return false;
    return checkPowersOfThree(n - 1) || checkPowersOfThree(n / 3);
  }
};