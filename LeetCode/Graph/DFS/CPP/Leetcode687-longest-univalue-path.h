class Solution {
public:
    int res = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return res;
    }
    int dfs(TreeNode* node) {
        if(!node) return 0;
        auto l = dfs(node->left),r = dfs(node->right);
        auto ll = 0,rr = 0;
        if(node->left && node->left->val == node->val) ll = l + 1;
        if(node->right && node->right->val == node->val) rr = r + 1;
        res = max(res,ll + rr);
        return max(ll,rr);
    }
};
