#include <cmath>
#include <iostream>

using namespace std;

int x, y, a, b;
int t;

int main() {
  cin >> t;
  while (t--) {
    cin >> x >> y >> a >> b;
    int dis = abs(x - y);
    if (dis % (a + b) != 0) {
      cout << -1 << '\n';
      continue;
    }
    int res = dis / (a + b);
    cout << res << endl;
  }
}