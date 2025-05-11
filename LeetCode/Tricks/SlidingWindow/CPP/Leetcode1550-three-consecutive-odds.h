class Solution {
 public:
  bool threeConsecutiveOdds(vector<int> &arr) {
    int l = 0, cnt = 0;
    for (int i = 0; i < arr.size(); ++i) {
      if (arr[i] & 1) {
        cnt++;
      }
      if (cnt == 3) {
        return true;
      }
      if (i >= 2) {
        cnt -= (arr[l++] & 1);
      }
    }
    return false;
  }
};
