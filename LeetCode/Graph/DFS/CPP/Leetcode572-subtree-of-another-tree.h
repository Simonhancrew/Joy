class Solution {
public:
  bool judge(TreeNode *node, TreeNode *sub_node) {
    if (!node || !sub_node) {
      if (!node && !sub_node) {
        return true;
      }
      return false;
    }
    if (node->val != sub_node->val) {
      return false;
    }
    return judge(node->left, sub_node->left) &&
           judge(node->right, sub_node->right);
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!root || !subRoot) {
      if (!subRoot && !root) {
        return true;
      }
      return false;
    }
    bool ans = false;
    if (root->val == subRoot->val) {
      ans = judge(root->left, subRoot->left) &&
            judge(root->right, subRoot->right);
    }
    return ans || isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
  }
};
