#include <iostream>
#include <string>

using namespace std;

// 1. 处理环的技巧， 展开
// 2. 处理多种记录的技巧， 2进制枚举, 类似一个染色法

int n;
string s;

int get(char c) {
  if (c == 'r') return 1;
  return 2;
}

int main() {
  // freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> s;
  s += s;
  int ans = 0;
  for(int i = 0;i < n;i++) {
    int l = i, r = i + n - 1;
    int left = 0, right = 0, cnt = 0;
    // 给left和right分别染色
    while (l <= r && (s[l] == 'w' || (left | get(s[l])) != 3)) {
      if (s[l] != 'w') left |= get(s[l]);
      cnt++, l++;
    }
    while (l <= r && (s[r] == 'w' || (right | get(s[r])) != 3)) {
      if (s[r] != 'w') right |= get(s[r]);
      cnt++, r--;
    }
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
  return 0;
}


