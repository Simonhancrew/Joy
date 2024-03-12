#include <unordered_set>

using namespace std;

class FindElements {
public:
  void dfs(TreeNode *node) {
    if (!node) {
      return;
    }
    auto cur = node->val;
    st_.insert(cur);
    if (node->left) {
      auto f = cur * 2 + 1;
      node->left->val = f;
      st_.insert(f);
      dfs(node->left);
    }
    if (node->right) {
      auto f = cur * 2 + 2;
      node->right->val = f;
      st_.insert(f);
      dfs(node->right);
    }
  }
  unordered_set<int> st_;
  FindElements(TreeNode *root) {
    root->val = 0;
    dfs(root);
  }

  bool find(int target) { return st_.contains(target); }
};
