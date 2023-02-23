class Solution {
 public:
  vector<int> circularPermutation(int n, int start) {
    vector<int> res(1 << n);
    for (int i = 0; i < 1 << n; i++) {
      res[i] = i ^ (i >> 1) ^ start;
    }
    return res;
  }
};
