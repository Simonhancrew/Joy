class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    auto *fast = head, *slow = head;
    while (fast) {
      fast = fast->next;
      slow = slow->next;
      if (fast == nullptr) return nullptr;
      fast = fast->next;
      if (fast == nullptr) return nullptr;
      if (fast == slow) break;
    }
    slow = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};
