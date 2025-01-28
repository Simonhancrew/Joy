#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res;
    res.reserve(rowIndex + 1);
    for (int i = 0; i <= rowIndex; i++) {
      res.push_back(1);
      for (int i = res.size() - 2; i >= 1; i--) {
        res[i] += res[i - 1];
      }
    }
    return res;
  }
};
