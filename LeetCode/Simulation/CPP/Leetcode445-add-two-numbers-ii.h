class Solution {
 public:
  ListNode* reverse(ListNode* head) {
    if (!head) return nullptr;
    auto* node = head;
    ListNode* pre = nullptr;
    while (node) {
      auto* ne = node->next;
      node->next = pre;
      pre = node;
      node = ne;
    }
    return pre;
  }
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto *h1 = reverse(l1), *h2 = reverse(l2);
    if (!h1 && !h2) {
      return nullptr;
    }
    int acc = 0;
    ListNode* dummy = new ListNode(-1);
    ListNode* ans = dummy;
    while (h1 && h2) {
      ans->next = new ListNode(-1);
      ans = ans->next;
      auto cur = acc + h1->val + h2->val;
      ans->val = cur % 10;
      acc = cur / 10;
      h1 = h1->next;
      h2 = h2->next;
    }
    while (h1) {
      ans->next = new ListNode(-1);
      ans = ans->next;
      auto cur = acc + h1->val;
      ans->val = cur % 10;
      acc = cur / 10;
      h1 = h1->next;
    }
    while (h2) {
      ans->next = new ListNode(-1);
      ans = ans->next;
      auto cur = acc + h2->val;
      ans->val = cur % 10;
      acc = cur / 10;
      h2 = h2->next;
    }
    if (acc) {
      ans->next = new ListNode(-1);
      ans = ans->next;
      ans->val = acc;
    }
    return reverse(dummy->next);
  }
};
