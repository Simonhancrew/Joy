class Solution {
 public:
  bool check(int num) {
    int tmp = num;
    while (tmp) {
      int t = tmp % 10;
      tmp /= 10;
      if (t == 0 || num % t != 0) return false;
    }
    return true;
  }
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    for (int i = left; i <= right; i++) {
      if (check(i)) res.push_back(i);
    }
    return res;
  }
};