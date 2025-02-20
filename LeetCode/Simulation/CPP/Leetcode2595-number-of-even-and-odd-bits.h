class Solution {
 public:
  vector<int> evenOddBit(int n) {
    int od = 0, ev = 0;
    int cnt = 0;
    while (n) {
      auto c = (n & 1);
      if ((cnt & 1)) {
        od += c;
      } else {
        ev += c;
      }
      cnt++;
      n >>= 1;
    }
    return {ev, od};
  }
};
