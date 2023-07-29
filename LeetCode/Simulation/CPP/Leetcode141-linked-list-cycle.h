class Solution {
 public:
  bool hasCycle(ListNode *head) {
    auto fast = head, slow = head;
    while (fast) {
      fast = fast->next;
      slow = slow->next;
      if (fast) fast = fast->next;
      if (fast != nullptr && fast == slow) return true;
    }
    return false;
  }
};
