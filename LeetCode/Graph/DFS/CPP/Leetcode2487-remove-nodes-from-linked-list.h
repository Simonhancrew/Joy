class Solution {
public:
  ListNode *removeNodes(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    head->next = removeNodes(head->next);
    if (head->next != nullptr && head->val < head->next->val) {
      return head->next;
    }
    return head;
  }
};
