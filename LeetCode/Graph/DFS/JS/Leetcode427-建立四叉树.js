var construct = function (grid) {
    const n = grid.length;
    const rec = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= n; j++) {
            rec[i][j] = rec[i - 1][j] + rec[i][j - 1] - rec[i - 1][j - 1] + grid[i - 1][j - 1]
        }
    }
    let dfs = function (x1, y1, x2, y2) {
        const n = x2 - x1 + 1
        const tot = rec[x2][y2] - rec[x2][y1 - 1] - rec[x1 - 1][y2] + rec[x1 - 1][y1 - 1]
        if (tot == 0 || tot == n * n) {
            return new Node(tot == 0 ? 0 : 1, true);
        }
        let node = new Node(0, false);
        const m = Math.floor(n / 2);
        node.topLeft = dfs(x1, y1, x1 + m - 1, y1 + m - 1)
        node.topRight = dfs(x1, y1 + m, x1 + m - 1, y2)
        node.bottomLeft = dfs(x1 + m, y1, x2, y1 + m - 1)
        node.bottomRight = dfs(x1 + m, y1 + m, x2, y2)
        return node;
    }
    return dfs(1, 1, n, n);
};