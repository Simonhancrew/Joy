#include <cstdio>
#include <iostream>
#include <vector>

/*
    可达性问题建图，考虑两圆的关系
    不相交有两种关系：
    1. 外部
    2. 内部
    内切的关键条件：dis(o1,o2) = | r1 - r2 |,小于这个值就是内包含的
*/

using namespace std;
#define fast_cin()                                                             \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);                                                                  \
  cout.tie(0)
using LL = long long;
using PII = pair<LL, LL>;
const int N = 3e3 + 10;

LL n, x, y;
PII start, tail;
struct circle {
  LL x, y, r;
};
circle p[N];
vector<int> g[N];
bool used[N];
int S, T;

bool dfs(int x) {
  used[x] = true;
  if (x == T)
    return true;
  for (auto ne : g[x]) {
    if (used[ne])
      continue;
    if (dfs(ne))
      return true;
  }
  return false;
}

int main() {
  fast_cin();
  cin >> n;
  cin >> start.first >> start.second;
  cin >> tail.first >> tail.second;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y >> p[i].r;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      LL dis = (p[i].x - p[j].x) * (p[i].x - p[j].x) +
               (p[i].y - p[j].y) * (p[i].y - p[j].y);
      LL radius = (p[i].r + p[j].r) * (p[i].r + p[j].r);
      if (dis > radius || dis < (p[i].r - p[j].r) * (p[i].r - p[j].r))
        continue;
      g[i].push_back(j), g[j].push_back(i);
    }
  }

  for (int i = 0; i < n; i++) {
    if (p[i].r * p[i].r ==
        (p[i].x - start.first) * (p[i].x - start.first) +
            (p[i].y - start.second) * (p[i].y - start.second))
      S = i;
    if (p[i].r * p[i].r == (p[i].x - tail.first) * (p[i].x - tail.first) +
                               (p[i].y - tail.second) * (p[i].y - tail.second))
      T = i;
  }

  if (dfs(S))
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
  return 0;
}