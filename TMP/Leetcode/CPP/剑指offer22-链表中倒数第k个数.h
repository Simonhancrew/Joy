
#include "ADT.hpp"

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int n = 0;
        auto tmp = head;
        while(tmp){
            n++;
            tmp = tmp->next;
        }
        tmp = head;
        n = n - k;
        while(n--){
            tmp = tmp->next;
        }
        return tmp;
    }
};

#if 0
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto fast = head;
        auto slow = head;
        while(fast && k > 0){
            fast = fast->next;
            k--;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
#endif