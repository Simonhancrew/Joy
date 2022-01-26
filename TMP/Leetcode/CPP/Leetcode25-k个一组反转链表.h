#include "ADT.hpp"

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(0);
        dummy -> next = head;
        for(auto tmp = dummy;;){
            auto cur = tmp;
            for(int i = 0;i < k && cur;i++){
                cur = cur->next;   
            }
            if(!cur) break;
            auto prev = tmp->next;
            cur = prev -> next;
            for(int i = 0;i < k - 1;i++){
                auto tail = cur->next;
                cur->next = prev;
                prev = cur,cur = tail;
            }
            auto tail = tmp->next;
            tmp->next = prev,tail->next = cur;
            tmp = tail;
        }
        auto rec = dummy->next;
        delete dummy;
        return rec;
    }
};