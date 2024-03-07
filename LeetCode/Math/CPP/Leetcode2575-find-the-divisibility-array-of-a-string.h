#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  using LL = uint64_t;
  vector<int> divisibilityArray(string word, int m) {
    int n = word.size();
    vector<int> res;
    res.reserve(n);
    LL acc = 0;
    for (const auto x : word) {
      acc = (acc * 10 + (x - '0')) % m;
      res.push_back(acc == 0);
    }
    return res;
  }
};
