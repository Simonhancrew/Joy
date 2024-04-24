// start往下走的深度，包含start作为端点的树的直径，二者取最大值
// 分情况，找到了start，返回的是当前节点到start的距离
// 左右子树都没有start，返回当前子树的最大深度
// 如果左右子树里面有start，取一条链，此时包含start的那个子树是到start的深度，返回到start的深度
class Solution {
public:
  using PIB = pair<int, bool>;
  int amountOfTime(TreeNode *root, int start) {
    int ans{};
    function<PIB(TreeNode *)> dfs = [&](TreeNode *node) -> PIB {
      if (!node) {
        return {0, false};
      }
      auto [l_len, lf] = dfs(node->left);
      auto [r_len, rf] = dfs(node->right);
      if (node->val == start) {
        ans = max(l_len, r_len);
        return {1, true};
      }
      if (lf || rf) {
        ans = max(ans, l_len + r_len);
        return {(lf ? l_len : r_len) + 1, true};
      }
      return {max(l_len, r_len) + 1, false};
    };
    dfs(root);
    return ans;
  }
};
