var lexicalOrder = function (n) {
    const res = [];
    let dfs = function (cur, n) {
        if (cur <= n) {
            res.push(cur);
        } else {
            return;
        }
        for (let i = 0; i <= 9; i++) dfs(cur * 10 + i, n);
    }
    for (let i = 1; i <= 9; i++) dfs(i, n);
    return res;
};