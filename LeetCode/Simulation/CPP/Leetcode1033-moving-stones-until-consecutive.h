class Solution {
 public:
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> tmp{a, b, c};
    sort(tmp.begin(), tmp.end());
    vector<int> ans(2);
    int l = tmp[1] - tmp[0] - 1, r = tmp[2] - tmp[1] - 1;
    ans[0] = 2;
    if (l == 0 && r == 0)
      ans[0] = 0;
    else if (l <= 1 || r <= 1)
      ans[0] = 1;
    ans[1] = l + r;
    return ans;
  }
};