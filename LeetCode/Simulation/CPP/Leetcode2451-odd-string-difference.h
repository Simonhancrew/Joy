#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> calcu(const string& s) {
    int n = s.size();
    vector<int> res;
    res.reserve(n - 1);
    for (int i = 1; i < n; i++) {
      res.push_back(s[i] - s[i - 1]);
    }
    return res;
  }

  string oddString(vector<string>& words) {
    auto arr1 = calcu(words[0]);
    auto arr2 = calcu(words[1]);
    if (arr1 == arr2) {
      int n = words.size();
      for (int i = 2; i < n; i++) {
        auto arr = calcu(words[i]);
        if (arr != arr1) return words[i];
      }
    }
    return arr1 == calcu(words[2]) ? words[1] : words[0];
  }
};