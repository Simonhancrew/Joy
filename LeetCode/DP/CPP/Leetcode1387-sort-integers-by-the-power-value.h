unordered_map<int, int> f;
int get(int x) {
  if (x == 1) {
    return 0;
  }
  if (f.count(x)) {
    return f[x];
  }
  f[x] = 1;
  if (x % 2 == 0) {
    f[x] += get(x / 2);
  } else {
    f[x] += get(x * 3 + 1);
  }
  return f[x];
}
class Solution {
 public:
  int getKth(int lo, int hi, int k) {
    vector<int> rec(hi - lo + 1, 0);
    iota(rec.begin(), rec.end(), lo);
    nth_element(rec.begin(), rec.begin() + k - 1, rec.end(),
                [](auto &lhs, auto &rhs) {
                  return make_pair(get(lhs), lhs) < make_pair(get(rhs), rhs);
                });
    return rec[k - 1];
  }
};
