var preorder = function (root) {
    const ans = [];
    let dfs = function (root) {
        if (!root) return;
        ans.push(root.val);
        for (const ne of root.children) {
            dfs(ne);
        }
    }
    dfs(root);
    return ans;
};