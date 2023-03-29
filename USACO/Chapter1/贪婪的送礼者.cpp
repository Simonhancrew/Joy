#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
unordered_map<string, pair<int, int>> st;
vector<string> name;
string s;

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);
  cin >> n;
  name.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s;
    name[i] = s;
    st[s] = {i, 0};
  }
  int p, cnt;
  for (int i = 0; i < n; i++) {
    cin >> s >> p >> cnt;
    if (!cnt || !p) continue;
    int sent = p / cnt, left = p % cnt;
    st[s].second -= (p - left);
    for (int j = 0; j < cnt; j++) {
      cin >> s;
      st[s].second += sent;
    }
  }
  vector<int> ans(n);
  for (const auto &[k, v] : st) {
    int idx = v.first, last = v.second;
    ans[idx] = last;
  }
  for (int i = 0; i < n; i++) {
    cout << name[i] << ' ' << ans[i] << '\n';
  }
  return 0;
}
