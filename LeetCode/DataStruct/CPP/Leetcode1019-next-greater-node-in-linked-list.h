class Solution {
 public:
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ans;
    stack<pair<int, int>> st;
    int i = 0;
    for (ListNode* cur = head; cur; cur = cur->next) {
      while (!st.empty() && st.top().second < cur->val) {
        ans[st.top().first] = cur->val;
        st.pop();
      }
      st.push({i++, cur->val});
      ans.push_back(0);
    }
    return ans;
  }
};