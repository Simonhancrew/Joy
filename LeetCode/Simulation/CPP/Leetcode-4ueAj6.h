class Solution {
 public:
  Node *insert(Node *head, int insertVal) {
    auto node = new Node(insertVal);
    if (!head) {
      node->next = node;
      return node;
    }
    if (head->next == head) {
      auto t = head->next;
      head->next = node;
      node->next = t;
      return head;
    }
    auto cur = head, ne = head->next;
    while (ne != head) {
      if (cur->val <= insertVal && insertVal <= ne->val) break;
      if (cur->val > ne->val)
        if (insertVal > cur->val || insertVal < ne->val) break;
      cur = ne, ne = ne->next;
    }
    cur->next = node;
    node->next = ne;
    return head;
  }
};