var serialize = function (root) {
    const res = []
    let dfs = function (root) {
        if (!root) return
        res.push(root.val.toString());
        dfs(root.left);
        dfs(root.right);
    }
    dfs(root);
    return res.join(' ');
};

var deserialize = function (data) {
    if (!data) return null;
    let arr = data.split(' ');
    arr = arr.map(item => parseInt(item))
    let u = 0;
    let dfs = function (arr, l, r) {
        if (u >= arr.length || arr[u] < l || arr[u] > r) {
            return null;
        }
        let root = new TreeNode(arr[u]);
        u++;
        root.left = dfs(arr, l, root.val);
        root.right = dfs(arr, root.val, r);
        return root;
    }
    return dfs(arr, -10010, 10010)
};