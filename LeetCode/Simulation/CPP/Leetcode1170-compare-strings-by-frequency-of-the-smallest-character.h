#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#if 0
class Solution {
 public:
  vector<int> numSmallerByFrequency(vector<string>& queries,
                                    vector<string>& words) {
    int n = queries.size(), m = words.size();
    vector<int> ans(n), f(m);
    auto get = [m](const auto& x) {
      char mn = x.front();
      unordered_map<int, int> mp;
      for (const auto y : x) {
        if (mn > y) mn = y;
        mp[y]++;
      }
      return mp[mn];
    };
    for (int i = 0; i < m; i++) {
      f[i] = get(words[i]);
    }
    auto check = [&](int idx) {
      auto cur = get(queries[idx]);
      int res = 0;
      for (const auto x : f) {
        if (cur < x) ++res;
      }
      return res;
    };
    for (int i = 0; i < n; i++) {
      ans[i] = check(i);
    }
    return ans;
  }
};

#endif

// 2025/02/09

class Solution {
 public:
  static int get(const std::string &s) {
    int res = 0, cur = 'z';
    for (char i : s) {
      if (i < cur) {
        res = 0;
        cur = i;
      }
      if (i == cur) {
        ++res;
      }
    }
    return res;
  }
  vector<int> numSmallerByFrequency(vector<string> &queries,
                                    vector<string> &words) {
    vector<int> fq, fw;
    fq.reserve(queries.size());
    fw.reserve(fw.size());
    for (const auto &q : queries) {
      fq.push_back(get(q));
    }
    for (const auto &w : words) {
      fw.push_back(get(w));
    }
    ranges::sort(fw);
    vector<int> ans;
    ans.reserve(fq.size());
    int n = fw.size();
    for (const auto x : fq) {
      int l = -1, r = n;
      while (l + 1 < r) {
        int mid = l + r >> 1;
        if (fw[mid] <= x)
          l = mid;
        else
          r = mid;
      }
      ans.push_back(n - r);
    }
    return ans;
  }
};
