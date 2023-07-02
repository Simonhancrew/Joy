struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto *h1 = l1, *h2 = l2;
    if (!h1 && !h2) {
      return nullptr;
    }
    int acc = 0;
    ListNode *dummy = new ListNode(-1);
    ListNode *ans = dummy;
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
    return dummy->next;
  }
};
