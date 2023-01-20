class Solution {
 public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    vector<int> ans(k);
    sort(logs.begin(), logs.end());
    int n = logs.size();
    for (int i = 0; i < n; i++) {
      int j = i;
      unordered_set<int> st;
      while (j < n && logs[j][0] == logs[i][0]) {
        st.insert(logs[j][1]);
        j++;
      }
      i = j - 1;
      ans[st.size() - 1]++;
    }
    return ans;
  }
};