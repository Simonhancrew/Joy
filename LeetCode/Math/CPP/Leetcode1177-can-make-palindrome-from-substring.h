// 因为看是不是回文，且只有26个可能出现的字母。
// 只要统计一下区间内出现的字母数量，这个用前缀和
// 偶数的天然不用考虑，奇数的分情况讨论就行了
// 有一个奇数的，这个时候长度一定是奇数是回文
// 两个奇数的，考虑替换一个就行了，此时两个都变成偶数的了
// 三个奇数的时候同理，替换一个，然后情况回到了一个奇数的时候
// 因此是一个cnt / 2的下取整
class Solution {
 public:
  static const int N = 1e5 + 10;
  int p[26][N]{};
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    int n = s.size();
    for (int i = 0; i < 26; i++) {
      for (int j = 1; j <= n; j++) {
        p[i][j] = p[i][j - 1];
        if (s[j - 1] - 'a' == i) p[i][j]++;
      }
    }
    vector<bool> ans;
    ans.reserve(queries.size());
    for (const auto& q : queries) {
      int l = q[0], r = q[1], k = q[2];
      int cnt = 0;
      for (int i = 0; i < 26; i++) {
        if ((p[i][r + 1] - p[i][l]) & 1) {
          cnt++;
        }
      }
      ans.push_back(cnt / 2 <= k);
    }
    return ans;
  }
};
