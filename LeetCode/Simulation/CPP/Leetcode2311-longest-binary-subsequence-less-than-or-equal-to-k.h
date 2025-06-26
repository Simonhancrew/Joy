class Solution {
 public:
  int longestSubsequence(string s, int k) {
    int n  = s.size();
    auto m = bit_width((uint32_t)k);
    if (n < m) {
      return n;
    }
    auto suffix_val = stoi(s.substr(n - m), nullptr, 2);
    auto suf_len    = suffix_val <= k ? m : m - 1;
    return suf_len + count(s.begin(), s.begin() + n - m, '0');
  }
};
