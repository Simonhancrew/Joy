#include "ADT.hpp"

/*
    因为每个点都可以是起点，所以入口的地方要做左右节点的处理
    然后dfs的逻辑比较简单

*/
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return pathSum(root->left,targetSum) + pathSum(root->right,targetSum) + dfs(root,targetSum);
    }
    int dfs(TreeNode* root,int targetSum){
        if(!root) return 0;
        if(root->left == nullptr && root->right == nullptr) return targetSum == root->val ? 1 : 0;
        int cnt = targetSum == root->val ? 1 : 0;
        return dfs(root->left,targetSum - root->val) + dfs(root->right,targetSum - root->val) + cnt;
    }
};