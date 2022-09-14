class Solution {
 public:
  /*
      稳定排序需要stable_sort
  */
  vector<string> reorderLogFiles(vector<string> &logs) {
    stable_sort(logs.begin(), logs.end(), [](const string &l, const string &r) {
      int x = l.find(' '), y = r.find(' ');
      auto a = l.substr(0, x), b = r.substr(0, y);
      auto a1 = l.substr(x + 1), b1 = r.substr(y + 1);
      auto a2 = isdigit(a1[0]), b2 = isdigit(b1[0]);
      if (a2 != b2) return a2 < b2;
      if (a2) return false;
      if (a1 != b1) return a1 < b1;
      return a < b;
    });
    return logs;
  }
};