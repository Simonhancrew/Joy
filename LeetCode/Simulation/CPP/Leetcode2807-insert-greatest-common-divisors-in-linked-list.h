class Solution {
public:
  int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }

  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    if (!head) {
      return head;
    }
    auto next = insertGreatestCommonDivisors(head->next);
    if (next) {
      auto cur = head->val;
      auto ne = next->val;
      auto new_val = gcd(cur, ne);
      head->next = new ListNode(new_val);
      head->next->next = next;
    }
    return head;
  }
};
