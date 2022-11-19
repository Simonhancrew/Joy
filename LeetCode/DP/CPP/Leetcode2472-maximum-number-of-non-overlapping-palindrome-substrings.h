class Solution {
 public:
  int maxPalindromes(string s, int k) {
    int n = s.size();
    vector<int> f(n + 1);
    for (int i = 0; i < 2 * n - 1; i++) {
      int l = i / 2, r = l + i % 2;
      f[l + 1] = max(f[l], f[l + 1]);
      while (l >= 0 && r < n && s[l] == s[r]) {
        if (r - l + 1 >= k) {
          f[r + 1] = max(f[l] + 1, f[r + 1]);
          break;
        }
        l--, r++;
      }
    }
    return f[n];
  }
};