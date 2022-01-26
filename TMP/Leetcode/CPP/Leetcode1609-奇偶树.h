#include <queue>

using namespace std;

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool st = true;
        while(q.size()){
            int n = q.size(),pre = -1,cur = 0;
            for(int i = 0;i < n;i++){   
                pre = cur;
                auto t = q.front();q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                cur = t->val;
                if(st) {
                    if(cur % 2 == 0) return false;
                    else if(i > 0 && pre >= cur) return false;
                }else{
                    if(cur % 2 == 1) return false;
                    else if(i > 0 && pre <= cur) return false;
                }
            }
            st = !st;
        }
        return true;
    }
};