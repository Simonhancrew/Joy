#include "ADT.hpp"
class Solution {
public:
    int cnt,res;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return res;
    }
    void dfs(TreeNode* root,int k){
        if(!root || cnt > k) return;
        dfs(root->left,k);
        cnt++;
        if(cnt == k){
            res = root->val;
            return;
        }
        dfs(root->right,k);
    }
};