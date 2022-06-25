var minCost = function (costs) {
    const n = costs.length;
    let f = new Array(n + 1).fill(0).map(() => new Array(3).fill(0));
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j < 3; j++) {
            if (j == 0)
                f[i][j] = Math.min(f[(i - 1)][1], f[(i - 1)][2]);
            if (j == 1)
                f[i][j] = Math.min(f[(i - 1)][0], f[(i - 1)][2]);
            if (j == 2)
                f[i][j] = Math.min(f[(i - 1)][0], f[(i - 1)][1]);
            f[i][j] += costs[i - 1][j];
        }
    }
    return Math.min(f[n][0], f[n][1], f[n][2]);
};