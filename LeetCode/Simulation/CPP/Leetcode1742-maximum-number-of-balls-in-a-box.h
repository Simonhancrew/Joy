class Solution {
 public:
  int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> mp;
    auto calcu = [](int x) {
      int res = 0;
      while (x) {
        res += x % 10;
        x /= 10;
      }
      return res;
    };

    for (int i = lowLimit; i <= highLimit; i++) {
      mp[calcu(i)]++;
    }

    int ans = 0;
    for (auto &[k, v] : mp) {
      ans = max(ans, v);
    }
    return ans;
  }
};