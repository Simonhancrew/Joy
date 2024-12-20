class Solution {
 public:
  int minAnagramLength(string s) {
    int n      = s.size();
    auto check = [&s, n](int len) {
      unordered_map<char, int> pre;
      for (int i = 0; i < n; i += len) {
        unordered_map<char, int> tmp;
        for (int j = i; j < i + len; j++) {
          tmp[s[j]]++;
        }
        if (i == 0) {
          pre = std::move(tmp);
          continue;
        }
        if (tmp != pre) {
          return false;
        }
      }
      return true;
    };
    int ans = n;
    for (int i = 1; i <= n / i; i++) {
      if (n % i != 0)
        continue;
      if (check(i))
        return i;
      int left = n / i;
      if (check(left))
        ans = min(ans, left);
    }
    return ans;
  }
};
