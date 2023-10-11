#include <algorithm>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {
 public:
  using PII = pair<int, int>;
  static vector<int> topStudents(vector<string> &positive_feedback,
                          vector<string> &negative_feedback,
                          vector<string> &report, vector<int> &student_id,
                          int k) {
    int n = report.size();
    vector<PII> res(n);
    unordered_set<string> po{positive_feedback.begin(),
                             positive_feedback.end()};
    unordered_set<string> na{negative_feedback.begin(),
                             negative_feedback.end()};
    for (const auto &s : positive_feedback) {
      if (po.count(s)) continue;
      po.insert(s);
    }
    for (const auto &s : negative_feedback) {
      if (na.count(s)) continue;
      na.insert(s);
    }
    for (int i = 0; i < n; i++) {
      int id = student_id[i];
      res[i].first = id;
      const string &s = report[i];
      int m = s.size();
      for (int j = 0; j < m; j++) {
        if (s[j] == ' ') continue;
        int k = j;
        while (k < m && s[k] != ' ') k++;
        const string ss = s.substr(j, k - j);
        if (po.count(ss)) res[i].second += 3;
        if (na.count(ss)) res[i].second -= 1;
        j = k;
      }
    }
    partial_sort(res.begin(), res.begin() + k, res.end(),
                 [](auto &lhs, auto &rhs) {
                   if (lhs.second == rhs.second) {
                     return lhs.first < rhs.first;
                   }
                   return lhs.second > rhs.second;
                 });
    vector<int> ans;
    ans.reserve(k);
    for (int i = 0; i < k; i++) {
      ans.push_back(res[i].first);
    }
    return ans;
  }
};
