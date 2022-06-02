class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        del(root, key);
        return root;
    }
    // 二级指针
    void del(TreeNode *&root, int key)
    {
        if (!root)
            return;
        if (root->val == key)
        {
            if (!root->left && !root->right)
                root = nullptr;
            else if (!root->left)
                root = root->right;
            else if (!root->right)
                root = root->left;
            else
            {
                auto ne = root->right;
                while (ne->left)
                    ne = ne->left;
                root->val = ne->val;
                del(root->right, ne->val);
            }
        }
        else if (root->val > key)
        {
            del(root->left, key);
        }
        else
        {
            del(root->right, key);
        }
    }
};