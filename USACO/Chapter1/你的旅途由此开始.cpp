#include <iostream>

using namespace std;

string s;
const int P = 47;

int calcu(const string& s) {
  int res = 1, n = s.size();
  for (int i = 0; i < n; i++) {
    res = (res * (s[i] - 'A' + 1)) % P;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  int a = calcu(s);
  cin >> s;
  int b = calcu(s);
  if (a == b) {
    cout << "GO" << '\n';
  } else {
    cout << "STAY" << '\n';
  }
  return 0;
}