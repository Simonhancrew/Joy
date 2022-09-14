class Solution {
 public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int n = nums.size();
    if (!n) return nullptr;
    return dfs(nums, 0, n - 1);
  }

  TreeNode* dfs(vector<int>& nums, int l, int r) {
    if (l > r) {
      return nullptr;
    }
    if (l == r) {
      return new TreeNode(nums[l]);
    }
    int max_v = 0, idx = l;
    for (int i = l; i <= r; i++) {
      if (nums[i] > max_v) {
        max_v = nums[i];
        idx = i;
      }
    }
    TreeNode* node = new TreeNode(max_v);
    node->left = dfs(nums, l, idx - 1);
    node->right = dfs(nums, idx + 1, r);
    return node;
  }
};