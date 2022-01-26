class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        int n = 0;
        auto tmp = head;
        while(tmp) {
            ++n;
            tmp = tmp->next;
        }
        int re = n / 2 + 1;
        tmp = dummy;
        auto pre = dummy;
        while(re){
            pre = tmp;
            tmp = tmp->next;
            re--;
        }
        pre->next = tmp->next;
        return dummy->next;        
    }
};