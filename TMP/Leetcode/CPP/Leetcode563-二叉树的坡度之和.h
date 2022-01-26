class Solution {
public:
    int ans = 0;
    int findTilt(TreeNode* root) {
        get(root);
        return ans;
    }
    int get(TreeNode* root){
        if(!root) return 0;
        int lhs = get(root->left),rhs = get(root->right);
        ans += abs(lhs - rhs);
        return lhs + rhs + root->val;
    }
};