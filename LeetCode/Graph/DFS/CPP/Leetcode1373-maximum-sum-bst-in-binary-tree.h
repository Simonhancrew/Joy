// 先考虑如何判断一棵树是不是搜索二叉树
// 一个dfs，但是要记录当前节点下的最大值和最小值
// 这样在返回上层节点的时候才能根据最大或最小值判断上层节点是否满足二叉搜索树的
// 性质。这里多+一维度的元素和，如果不满足二叉搜搜树性质直接返回就可以了

class Solution {
 public:
  using T = tuple<int, int, int>;
  int ans{};
  T dfs(TreeNode* root) {
    if (!root) {
      return {INT_MAX, INT_MIN, 0};
    }
    auto [lmn, lmx, lsum] = dfs(root->left);
    auto [rmn, rmx, rsum] = dfs(root->right);
    auto val = root->val;
    if (val <= lmx || val >= rmn) {
      return {INT_MIN, INT_MAX, 0};
    }
    ans = max(ans, root->val + lsum + rsum);
    return {min(lmn, val), max(val, rmx), root->val + lsum + rsum};
  }
  int maxSumBST(TreeNode* root) {
    dfs(root);
    return ans;
  }
};
