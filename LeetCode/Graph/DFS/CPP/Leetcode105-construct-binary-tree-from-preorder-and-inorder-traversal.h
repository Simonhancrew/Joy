#include <unordered_map>

using namespace std;

// 划分好区域index就很简单

class Solution {
public:
  unordered_map<int, int> mp;
  TreeNode *build(int p_lhs, int p_rhs, int i_lhs, int i_rhs,
                  const vector<int> &preorder, const vector<int> &inorder) {
    if (p_lhs > p_rhs) {
      return nullptr;
    }
    auto *root = new TreeNode(preorder[p_lhs]);
    auto in_idx = mp[preorder[p_lhs]];
    root->left = build(p_lhs + 1, p_lhs + in_idx - i_lhs, i_lhs, in_idx - 1,
                       preorder, inorder);
    root->right = build(p_lhs + in_idx - i_lhs + 1, p_rhs, in_idx + 1, i_rhs,
                        preorder, inorder);
    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) {
      return nullptr;
    }
    int i = 0;
    int n = inorder.size();
    for (const auto x : inorder) {
      mp[x] = i++;
    }
    return build(0, n - 1, 0, n - 1, preorder, inorder);
  }
};
