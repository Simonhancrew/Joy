class Solution {
public:
    unordered_set<int> st;
    bool findTarget(TreeNode* root, int k) {
        return dfs(root,k);
    }
    bool dfs(TreeNode* root,int k) {
        if(!root) return false;
        if(st.count(root->val)) return true;
        st.insert(k - root->val);
        if(dfs(root->left,k)) return true;
        if(dfs(root->right,k)) return true;
        return false; 
    }
};