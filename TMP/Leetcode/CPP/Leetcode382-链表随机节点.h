class Solution {
public:
    vector<ListNode*> node;
    Solution(ListNode* head) {
        while(head){
            node.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        int n = node.size();
        int t = rand() % n;
        return node[t]->val;
    }
};
