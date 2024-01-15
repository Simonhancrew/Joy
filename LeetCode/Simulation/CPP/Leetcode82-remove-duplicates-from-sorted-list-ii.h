class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    auto *dummy = new ListNode(-101);
    dummy->next = head;
    auto *node = dummy;
    while (node->next) {
      auto ne = node->next;
      if (ne->next && ne->next->val == ne->val) {
        while (ne->next && ne->next->val == ne->val) {
          ne = ne->next;
        }
        node->next = ne->next;
      } else {
        node = node->next;
      }
    }
    auto *res = dummy->next;
    delete dummy;
    return res;
  }
};
