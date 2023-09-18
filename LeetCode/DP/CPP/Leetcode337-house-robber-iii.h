#define NODE_CHECK(f, x) f.count(x) ? f[x] : 0
class Solution {
 public:
  // f表示选当前节点，g表示不选当前节点
  unordered_map<TreeNode *, int> f, g;
  void dfs(TreeNode *node) {
    if (!node) {
      return;
    }
    dfs(node->left);
    dfs(node->right);
    f[node] = node->val;
    if (g.count(node->left)) {
      f[node] += g[node->left];
    }
    if (g.count(node->right)) {
      f[node] += g[node->right];
    }
    g[node] = max(NODE_CHECK(f, node->left), NODE_CHECK(g, node->left)) +
              max(NODE_CHECK(f, node->right), NODE_CHECK(g, node->right));
  }
  int rob(TreeNode *root) {
    dfs(root);
    return max(f[root], g[root]);
  }
};
