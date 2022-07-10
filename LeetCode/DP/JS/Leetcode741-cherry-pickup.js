var cherryPickup = function (grid) {
    const n = grid.length;
    let f = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0).map(() => new Array(2 * n + 1).fill(-10000)));
    f[1][1][2] = grid[0][0];
    for (let k = 3; k <= 2 * n; k++) {
        for (let i = Math.max(1, k - n); i <= Math.min(n, k - 1); i++) {
            for (let j = Math.max(1, k - n); j <= Math.min(n, k - 1); j++) {
                if (grid[i - 1][k - i - 1] == -1 || grid[j - 1][k - j - 1] == -1) continue;
                let t = grid[i - 1][k - i - 1];
                if (i != j) t += grid[j - 1][k - j - 1];
                for (let a = i - 1; a <= i; a++) {
                    for (let b = j - 1; b <= j; b++) {
                        f[i][j][k] = Math.max(f[i][j][k], f[a][b][k - 1] + t);
                    }
                }
            }
        }
    }
    return Math.max(0, f[n][n][2 * n]);
};