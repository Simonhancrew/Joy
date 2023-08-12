class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if (n == 0) return nullptr;
    ListNode* dum = new ListNode(-1);
    auto* cur = dum;
    while (true) {
      int exa_cnt = 0;
      int id = -1;
      for (int i = 0; i < n; i++) {
        if (!lists[i]) {
          continue;
        }
        exa_cnt++;
        if (id == -1 || lists[id]->val > lists[i]->val) {
          id = i;
        }
      }
      if (id != -1) {
        cur->next = lists[id];
        lists[id] = lists[id]->next;
        cur = cur->next;
      }
      if (exa_cnt <= 1) {
        break;
      }
    }
    return dum->next;
  }
};
