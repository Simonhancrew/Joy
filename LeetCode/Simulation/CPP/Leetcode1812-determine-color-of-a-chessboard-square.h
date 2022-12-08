class Solution {
 public:
  bool squareIsWhite(string coordinates) {
    int col = coordinates[0] - 'a' + 1, row = coordinates[1] - '0';
    if (col & 1 && row & 1) {
      return false;
    }
    if (!(col & 1) && !(row & 1)) return false;
    return true;
  }
};