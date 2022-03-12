var postorder = function (root) {
    const ans = [];
    if (!root) return ans;
    let dfs = function (root) {
        if (!root) return;
        for (const ne of root.children) {
            dfs(ne);
        }
        ans.push(root.val);
    }
    dfs(root);
    return ans;
};