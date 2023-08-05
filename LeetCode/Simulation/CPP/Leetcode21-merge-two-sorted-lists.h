class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode(-1);
    auto ans = head;
    while (list1 && list2) {
      ListNode* cur = nullptr;
      if (list1->val > list2->val) {
        cur = list2;
        list2 = list2->next;
      } else {
        cur = list1;
        list1 = list1->next;
      }
      ans->next = cur;
      ans = ans->next;
    }
    if (list1) {
      ans->next = list1;
    }
    if (list2) {
      ans->next = list2;
    }
    return head->next;
  }
};
