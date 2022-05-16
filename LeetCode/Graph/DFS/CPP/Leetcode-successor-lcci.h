/*
    迭代的做法
*/
class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *pre = NULL, *cur = root;
        stack<TreeNode *> stk;
        while (!stk.empty() || cur != NULL)
        {
            while (cur != NULL)
            {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (pre == p)
                return cur;
            pre = cur;
            cur = cur->right;
        }
        return NULL;
    }
};
/*
    利用BST的性质
*/
class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        if (!root)
            return NULL;
        if (root->val <= p->val)
            return inorderSuccessor(root->right, p);
        auto ans = inorderSuccessor(root->left, p);
        return ans == NULL ? root : ans;
    }
};