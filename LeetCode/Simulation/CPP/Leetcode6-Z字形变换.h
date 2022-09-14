/*
    找规律的问题，画出来之后发现一个等差数列的规律
*/
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string res;
    for (int i = 0; i < numRows; i++) {
      if (i == 0 || i == numRows - 1) {
        for (int j = i; j < s.size(); j += 2 * numRows - 2) {
          res += s[j];
        }
      } else {
        for (int j = i, k = 2 * numRows - 2 - i; j < s.size() || k < s.size();
             j += 2 * numRows - 2, k += 2 * numRows - 2) {
          if (j < s.size()) res += s[j];
          if (k < s.size()) res += s[k];
        }
      }
    }
    return res;
  }
};