#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
 public:
  vector<int> dfs(TreeNode* root) {
    if (!root) return {0, 0, 0};
    auto lhs = dfs(root->left), rhs = dfs(root->right);
    int x = lhs[0] + rhs[0] + 1;
    int y = lhs[1] + rhs[1] + root->val;
    return {x, y, abs(x - y) + lhs[2] + rhs[2]};
  }

  int distributeCoins(TreeNode* root) { return dfs(root)[2]; }
};
