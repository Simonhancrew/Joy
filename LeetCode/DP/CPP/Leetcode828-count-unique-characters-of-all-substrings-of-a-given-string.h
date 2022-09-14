// 记录当前位置往左找最近的相同值，右边同理
// 最后的结果就是(i - l[i]) * (r[i] - i)
// 只用考虑当前的字符对哪些子字符串有贡献就可以了
// 字符串中出现2个相同的字符就不计这个贡献了，所以不难想到
// 左右记录出现同值的位置
class Solution {
 public:
  int uniqueLetterString(string s) {
    int n = s.size();
    vector<int> l(n, -1), r(n, n);
    vector<int> last(26, -1);
    for (int i = 0; i < n; i++) {
      l[i] = last[s[i] - 'A'];
      last[s[i] - 'A'] = i;
    }
    last = vector<int>(26, n);
    for (int i = n - 1; i >= 0; i--) {
      r[i] = last[s[i] - 'A'];
      last[s[i] - 'A'] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (i - l[i]) * (r[i] - i);
    }
    return ans;
  }
};
