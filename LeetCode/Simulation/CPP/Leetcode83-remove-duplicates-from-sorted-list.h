#if 0
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) {
      return head;
    }
    int cur = head->val;
    auto *ne = head->next;
    while (ne && ne->val == cur) {
      ne = ne->next;
    }
    head->next = ne;
    deleteDuplicates(head->next);
    return head;
  }
};
#endif

#if 0
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) {
      return head;
    }
    auto *cur = head;
    while (cur->next) {
      if (cur->val == cur->next->val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }
    return head;
  }
};
#endif
