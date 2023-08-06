class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    auto* t = new ListNode(-1);
    t->next = head;
    auto *cur = head, *pre = t;
    while (cur && cur->next) {
      auto* ne = cur->next;
      cur->next = ne->next;
      ne->next = cur;
      pre->next = ne;
      pre = cur;
      cur = cur->next;
    }
    auto ans = t->next;
    delete t;
    return ans;
  }
};
