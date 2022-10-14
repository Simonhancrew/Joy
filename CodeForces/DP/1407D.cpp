#include <algorithm>
#include <cstring>
#include <iostream>

// Created by Simonhancrew on 2022/10/14

using namespace std;

using LL  = long long;
using PII = pair<int, int>;
#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr)

const int INF = 0x3f3f3f3f, N = 3e5 + 10;

int n;
int h[N];

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  fast_cin();
  cin >> n;
  for(int i = 0;i < n;i++) cin >> h[i];
  
  return 0;
}