class Solution {
 public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode *pre, *node = list1;
    int cnt = 0;
    while (node && cnt < a) {
      pre = node;
      node = node->next;
      cnt++;
    }
    pre->next = list2;
    while (node && cnt < b) {
      node = node->next;
      cnt++;
    }
    auto list_tail = list2;
    while (list_tail->next != nullptr) {
      list_tail = list_tail->next;
    }
    list_tail->next = node->next;
    return list1;
  }
};
