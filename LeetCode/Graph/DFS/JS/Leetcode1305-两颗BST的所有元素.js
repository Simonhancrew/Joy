var getAllElements = function (root1, root2) {
    let arr1 = [], arr2 = [];
    let dfs = function (node, arr) {
        if (!node) return;
        dfs(node.left, arr);
        arr.push(node.val);
        dfs(node.right, arr)
    }

    dfs(root1, arr1), dfs(root2, arr2);
    let [idx, l, r, n, m] = [0, 0, 0, arr1.length, arr2.length];
    let res = new Array(n + m).fill(0);
    while (l < n && r < m) {
        if (arr1[l] < arr2[r]) res[idx++] = arr1[l++];
        else res[idx++] = arr2[r++];
    }
    while (l < n) res[idx++] = arr1[l++];
    while (r < m) res[idx++] = arr2[r++];
    return res;
};