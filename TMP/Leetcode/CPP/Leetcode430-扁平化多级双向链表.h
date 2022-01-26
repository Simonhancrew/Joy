#include "ADT.hpp"

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        auto t = head;
        while(t){
            auto ne = t->next;
            if(t->child){
                t->next = flatten(t->child);
                t->next->prev = t;
                t->child = nullptr;
                while(t->next) t = t->next;
            }
            t->next = ne;
            if(ne) ne->prev = t;
            t = ne;
        }
        return head;
    }   
};

#ifdef ONECEDFS
class Solution {
public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
    Node* dfs(Node* head){
        if(!head) return nullptr;
        auto t = head,last = head;
        while(t){
            if(!t->child){
                last = t;
                t = t->next;
            }else{
                auto ne = t->next,childlast = dfs(t->child);
                t->next = t->child;
                t->child->prev = t;
                t->child = nullptr;
                t = childlast;
                t->next = ne;
                if(ne) ne->prev = t;
                last = t;  
            }
        }
        return last;
    }
};
#endif