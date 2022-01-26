// 替换型的思路
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto ne = node->next;
        node->val = node->next->val;
        node->next=node->next->next;
        delete(ne);
    }
};

#if 0
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto ne = node->next;
        *node = *node->next;
        delete(ne);
    }
};
#endif