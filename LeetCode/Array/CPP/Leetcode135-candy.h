class Solution {
 public:
  int candy(vector<int> &ratings) {
    int n = ratings.size(), res = n;
    for (int i = 0; i < n; i++) {
      int start = (i > 0 && ratings[i - 1] < ratings[i]) ? i - 1 : i;
      while (i + 1 < n && ratings[i] < ratings[i + 1]) {
        i++;
      }
      int top = i;
      while (i + 1 < n && ratings[i] > ratings[i + 1]) {
        i++;
      }
      // start, ... , top + start -> (top - start) * (top - start - 1) / 2
      int up  = top - start;
      int dec = i - top;
      res += (up * (up - 1) + dec * (dec - 1)) / 2 + max(dec, up);
    }
    return res;
  }
};
