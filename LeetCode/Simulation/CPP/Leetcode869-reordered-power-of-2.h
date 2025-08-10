class Solution {
 public:
  vector<int> get(int x) {
    vector<int> res(10);
    while (x) {
      res[(x % 10)]++;
      x /= 10;
    }
    return res;
  }

  bool reorderedPowerOf2(int n) {
    auto arr = get(n);
    for (int i = 1; i <= 1e9; i <<= 1) {
      if (arr == get(i)) {
        return true;
      }
    }
    return false;
  }
};
