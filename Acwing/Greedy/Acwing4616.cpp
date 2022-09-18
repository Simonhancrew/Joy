#include <iostream>

using namespace std;

// 等价于找区间问题，找到每个长度为b的区间总数
// 减去a - 1之后就是需要命中的区间
// 模拟去算

const int N = 2e5 + 10;

int n, a, b, k;
char arr[N];

int main() {
  cin >> n >> a >> b >> k;
  cin >> arr + 1;
  int res = 0;
  for (int i = 1, len = 0; i <= n; i++) {
    if (arr[i] == '1')
      len = 0;
    else {
      if (++len == b) {
        len = 0;
        res++;
      }
    }
  }
  res -= (a - 1);
  cout << res << '\n';
  for (int i = 1, len = 0; res; i++) {
    if (arr[i] == '1')
      len = 0;
    else {
      if (++len == b) {
        cout << i << ' ';
        res--;
        len = 0;
      }
    }
  }
  return 0;
}