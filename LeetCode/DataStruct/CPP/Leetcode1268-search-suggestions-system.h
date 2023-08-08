#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  static constexpr int N = 2e4 + 10;
  int tr[N][26];
  int idx{};
  unordered_map<int, int> lhs, rhs;

  void add(const std::string& s, int id) {
    int u = 0;
    for (const auto x : s) {
      auto c = x - 'a';
      if (tr[u][c] == 0) {
        tr[u][c] = ++idx;
        lhs[tr[u][c]] = id;
      }
      rhs[tr[u][c]] = id;
      u = tr[u][c];
    }
  }

  std::pair<int, int> query(const std::string& s) {
    pair<int, int> res{-1, -1};
    int u = 0;
    for (const auto x : s) {
      auto c = x - 'a';
      if (tr[u][c] == 0) return {-1, -1};
      res.first = lhs[tr[u][c]];
      res.second = rhs[tr[u][c]];
      u = tr[u][c];
    }
    return res;
  }

  vector<vector<string>> suggestedProducts(vector<string>& products,
                                           string searchWord) {
    sort(products.begin(), products.end());
    int n = products.size();
    vector<vector<string>> res;
    res.resize(searchWord.size());
    for (int i = 0; i < n; i++) add(products[i], i);
    n = searchWord.size();
    for (int i = 0; i < n; i++) {
      auto [l, r] = query(searchWord.substr(0, i + 1));
      for (int p = l; p <= min(l + 2, r) && l != -1; ++p)
        res[i].push_back(products[p]);
    }
    return res;
  }
};
