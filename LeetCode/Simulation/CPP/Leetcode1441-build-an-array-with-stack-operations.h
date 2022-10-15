class Solution {
 public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    for (int i = 1, j = 0; i <= n; i++) {
      if (target[j] == i) {
        ans.emplace_back("Push");
        j++;
      } else {
        ans.emplace_back("Push");
        ans.emplace_back("Pop");
      }
      if (i == target.back()) break;
    }
    return ans;
  }
};