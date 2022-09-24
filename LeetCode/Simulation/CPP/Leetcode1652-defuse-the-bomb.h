class Solution {
 public:
  vector<int> decrypt(vector<int> &code, int k) {
    int n = code.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      if (k == 0)
        ans[i] = 0;
      else if (k > 0) {
        int acc = 0;
        for (int j = i + 1; j <= i + k; j++) {
          acc += code[j % n];
        }
        ans[i] = acc;
      } else {
        int acc = 0;
        for (int j = i - 1; j >= i + k; j--) {
          acc += code[(j + n) % n];
        }
        ans[i] = acc;
      }
    }
    return ans;
  }
};