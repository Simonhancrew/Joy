#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string merge(const string& a, const string& b) {
    if (a.find(b) != string::npos) return a;
    if (b.find(a) != string::npos) return b;
    int n = min(a.size(), b.size());
    int tot = a.size();
    // length, 枚举a的后半段和b的前半段相等
    for (int len = n; len > 0; len--) {
      if (a.substr(tot - len, len) == b.substr(0, len)) {
        return a + b.substr(len);
      }
    }
    return a + b;
  }

  string minimumString(string a, string b, string c) {
    vector<string> rec;
    rec.push_back(a), rec.push_back(b);
    rec.push_back(c);
    string res;
    // A(3, 3), 组合数
    vector<vector<int>> arr = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                               {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    for (const auto& x : arr) {
      auto cur = merge(rec[x[0]], merge(rec[x[1]], rec[x[2]]));
      if (res.empty() || res.size() > cur.size() ||
          res.size() == cur.size() && res > cur) {
        res = std::move(cur);
      }
    }
    return res;
  }
};
