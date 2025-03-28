class Solution {
 public:
  int minimizedStringLength(string s) {
    int acc = 0;
    array<int, 26> arr{};
    for (const auto x : s) {
      if (arr[x - 'a'] != 0) {
        continue;
      }
      arr[x - 'a'] = 1;
      acc += 1;
    }
    return acc;
  }
};
