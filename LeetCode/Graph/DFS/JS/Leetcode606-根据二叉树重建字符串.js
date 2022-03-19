var tree2str = function (root) {
    const res = [];
    let dfs = function (root) {
        if (!root) return;
        res.push(root.val);
        if (root.left || (!root.left && root.right)) {
            res.push('(');
            dfs(root.left);
            res.push(')');
        }
        if (root.right) {
            res.push('(');
            dfs(root.right);
            res.push(')');
        }
    }
    dfs(root);
    return res.join('');
};