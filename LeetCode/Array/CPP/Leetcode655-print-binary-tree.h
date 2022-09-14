#include <algorithm>
#include <string>
#include <vector>

using std::max;
using std::string;
using std::to_string;
using std::vector;

class Solution {
 public:
  int hei = 0;
  vector<vector<string>> ans;
  void dfs(TreeNode* root, int level) {
    if (!root) return;
    hei = max(hei, level);
    level++;
    dfs(root->left, level);
    dfs(root->right, level);
  }
  void dfs_fill(TreeNode* node, int x, int y) {
    ans[x][y] = to_string(node->val);
    if (node->left) dfs_fill(node->left, x + 1, y - (1 << (hei - x - 1)));
    if (node->right) dfs_fill(node->right, x + 1, y + (1 << (hei - x - 1)));
  }
  vector<vector<string>> printTree(TreeNode* root) {
    dfs(root, 0);
    int n = hei + 1, m = (1 << (hei + 1)) - 1;
    ans = vector<vector<string>>(n, vector<string>(m));
    dfs_fill(root, 0, (m - 1) / 2);
    return ans;
  }
};