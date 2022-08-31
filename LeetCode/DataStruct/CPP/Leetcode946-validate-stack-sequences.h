class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    vector<int> ans;
    for(int i = 0,j = 0;i < n;i++) {
      ans.emplace_back(pushed[i]);
      while(ans.size() && ans.back() == popped[j]) {
        ans.pop_back();
        j++;
      }
    }
    return ans.empty();
  }
};
