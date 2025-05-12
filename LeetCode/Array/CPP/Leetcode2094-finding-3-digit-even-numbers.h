class Solution {
 public:
  vector<int> findEvenNumbers(vector<int> &digits) {
    int cnt[10]{};
    for (const auto x : digits) {
      cnt[x]++;
    }
    vector<int> res;
    for (int i = 100; i < 1000; i += 2) {
      int tmp[10]{};
      bool ok = true;
      for (int x = i; x > 0; x /= 10) {
        int d = x % 10;
        if (++tmp[d] > cnt[d]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        res.push_back(i);
      }
    }
    return res;
  }
};
