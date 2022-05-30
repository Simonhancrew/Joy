var sumRootToLeaf = function (root) {
    let dfs = function (root, x) {
        if (!root) return x;
        x = x * 2 + root.val;
        if (!root.left && !root.right) return x;
        let tmp = 0;
        if (root.left) tmp += dfs(root.left, x);
        if (root.right) tmp += dfs(root.right, x);
        return tmp;
    }


    return dfs(root, 0);
};