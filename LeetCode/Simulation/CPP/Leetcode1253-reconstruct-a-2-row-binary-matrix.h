#include <vector>
#include <array>
#include <algorithm>

using namespace std;

// 其实做复杂了，只需只需要统计一下col[i] = 2的，这个时候上下两行都填1
// upper和lower减去2的数值，只考虑1的列，对这种列判断一下

#if 0

class Solution {
public:
  vector<vector<int>> reconstructMatrix(int upper, int lower,
                                        vector<int> &colsum) {
    int n = colsum.size();
    vector<vector<int>> ans(2, vector<int>(n));
    array<int, 2> row{upper, lower};
    auto get = [&row, &colsum](int x, int y) {
      auto &r = row[x], &c = colsum[y];
      if (r == 0 || c == 0)
        return 0;
      c--, r--;
      return 1;
    };
    vector<int> idx(n);
    for (int i = 0;i < n;i++) {
      idx[i] = i;
    }
    sort(idx.begin(), idx.end(),
         [&colsum](int lhs, int rhs) { return colsum[lhs] > colsum[rhs]; });
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        auto cur = get(i, idx[j]);
        ans[i][idx[j]] = cur;
      }
    }
    if (row[0] || row[1]) {
      return {};
    }
    for (const auto c : colsum) {
      if (c) {
        return {};
      }
    }
    return ans;
  }
};

#else

class Solution {
 public:
  vector<vector<int>> reconstructMatrix(int upper, int lower,
                                        vector<int> &colsum) {
    int n = colsum.size();
    vector<vector<int>> ans(2, vector<int>(n));
    int sum = 0, rec = 0;
    for (const auto x : colsum) {
      if (x == 2) {
        ++rec;
      }
      sum += x;
    }
    if (sum != upper + lower || rec > min(upper, lower)) {
      return {};
    }
    upper -= rec, lower -= rec;
    for (int i = 0; i < n; i++) {
      if (colsum[i] == 2) {
        ans[0][i] = 1;
        ans[1][i] = 1;
      } else if (colsum[i] == 1) {
        if (upper > 0) {
          ans[0][i] = 1;
          --upper;
        } else if (lower > 0) {
          ans[1][i] = 1;
          --lower;
        }
      }
    }
    if (lower || upper) return {};
    return ans;
  }
};

#endif

