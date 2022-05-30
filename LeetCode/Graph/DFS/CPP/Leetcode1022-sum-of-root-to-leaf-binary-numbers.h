class Solution
{
public:
    int dfs(TreeNode *node, int cnt)
    {
        if (!node)
            return cnt;
        cnt = cnt * 2 + node->val;
        if (!node->left && !node->right)
            return cnt;
        int tmp = 0;
        if (node->left)
            tmp += dfs(node->left, cnt);
        if (node->right)
            tmp += dfs(node->right, cnt);
        return tmp;
    }

    int sumRootToLeaf(TreeNode *root)
    {
        return dfs(root, 0);
    }
};