#include "ADT.hpp"

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        for(auto p = head;p;p=p->next) n++;
        auto p = head;
        vector<ListNode*> res;
        for(int i = 0;i < k;i++){
            int base = n / k,mod = n % k;
            if(i + 1 <= mod) base++;
            res.push_back(p);
            for(int j = 0;j < base - 1;j++) p = p->next;  
            if(p){
                auto q = p->next;
                p->next = nullptr;
                p = q;
            }
        }
        return res;
    }
};