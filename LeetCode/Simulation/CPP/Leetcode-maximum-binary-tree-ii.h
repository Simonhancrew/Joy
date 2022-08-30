class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        auto dummy = new TreeNode(-1);
        dummy->right = root;
        auto node = dummy;
        while(node->right && node->right->val > val) {
            node = node->right;
        }
        auto ne = node->right;
        auto t = new TreeNode(val);
        node->right = t;
        t->left = ne;
        root = dummy->right;
        delete dummy;
        return root;
    }
};