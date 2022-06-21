var findBottomLeftValue = function (root) {
    let [hei, val] = [0, 0];
    let dfs = function (node, h) {
        if (!node) return;
        h++;
        dfs(node.left, h);
        dfs(node.right, h)
        if (h > hei) {
            hei = h;
            val = node.val;
        }
    }
    dfs(root, 0);
    return val;
};