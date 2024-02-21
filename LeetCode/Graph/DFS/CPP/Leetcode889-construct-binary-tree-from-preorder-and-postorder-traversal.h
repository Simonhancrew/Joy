#include <functional>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  unordered_map<int, int> mp;
  TreeNode *constructFromPrePost(vector<int> &preorder,
                                 vector<int> &postorder) {
    int n = preorder.size();
    for (int i = 0; i < n; i++) {
      mp[postorder[i]] = i;
    }
    function<TreeNode *(int, int, int, int)> build =
        [&](int pre_lhs, int pre_rhs, int post_lhs,
            int post_rhs) -> TreeNode * {
      if (pre_lhs > pre_rhs) {
        return nullptr;
      }
      auto root_val = preorder[pre_lhs];
      auto *root = new TreeNode(root_val);
      if (pre_lhs == pre_rhs) {
        return root;
      }
      auto new_post_rhs = mp[preorder[pre_lhs + 1]];
      root->left = build(pre_lhs + 1, pre_lhs + new_post_rhs - post_lhs + 1,
                         post_lhs, new_post_rhs);
      root->right = build(pre_lhs + new_post_rhs - post_lhs + 2, pre_rhs,
                          new_post_rhs + 1, post_rhs - 1);
      return root;
    };
    return build(0, n - 1, 0, n - 1);
  }
};
