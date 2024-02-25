class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    auto *ans = root;
    do {
      if (p->val > ans->val && q->val > ans->val) {
        ans = ans->right;
        continue;
      }
      if (p->val < ans->val && q->val < ans->val) {
        ans = ans->left;
        continue;
      }
      break;
    } while (true);
    return ans;
  }
};