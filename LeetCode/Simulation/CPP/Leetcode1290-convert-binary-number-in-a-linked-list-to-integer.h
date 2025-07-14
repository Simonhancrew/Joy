class Solution {
 public:
  int getDecimalValue(ListNode *head) {
    int ans = 0;
    while (head != nullptr) {
      auto cur = head->val;
      ans <<= 1;
      ans |= cur;
      head = head->next;
    }
    return ans;
  }
};
