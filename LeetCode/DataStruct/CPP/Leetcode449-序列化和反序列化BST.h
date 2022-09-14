class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string res;
    if (!root) return res;
    res += to_string(root->val) + ' ';
    res += serialize(root->left);
    res += serialize(root->right);
    return res;
  }

  TreeNode *dfs(vector<int> const &arr, int &u, int l, int r) {
    if (u >= arr.size() || arr[u] < l || arr[u] > r) return NULL;
    auto root = new TreeNode(arr[u++]);
    root->left = dfs(arr, u, l, root->val);
    root->right = dfs(arr, u, root->val, r);
    return root;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    vector<int> arr;
    stringstream ss(data);
    int x, u = 0;
    while (ss >> x) arr.push_back(x);
    return dfs(arr, u, INT_MIN, INT_MAX);
  }
};
