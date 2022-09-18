#include <algorithm>
#include <cstring>
#include <iostream>

// Created by Simonhancrew on 2022/09/18

using namespace std;

// 就观察结果之后硬猜

using LL  = long long;
using PII = pair<int, int>;
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr)

const int INF = 0x3f3f3f3f;

int a, t;

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  fast_cin();
  cin >> t;
  while (t--) {
    cin >> a;
    int cnt = 0;
    while (a) {
      cnt += (a & 1);
      a >>= 1;
    }
    cout << (1 << cnt) << '\n';
  }
  return 0;
}