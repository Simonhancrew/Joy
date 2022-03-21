var findTarget = function (root, k) {
    const st = new Set();
    let dfs = function (root) {
        if (!root) return false;
        if (st.has(root.val)) return true;
        st.add(k - root.val);
        if (dfs(root.left) || dfs(root.right)) return true;
        return false;
    }
    return dfs(root);
};