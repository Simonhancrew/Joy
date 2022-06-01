var makesquare = function (arr) {
    const tot = arr.reduce((acc, it) => acc + it, 0);
    if (tot % 4 != 0) return false;
    let edge = new Array(4).fill(0);
    let dfs = function (u) {
        if (u == arr.length) {
            return true;
        }
        for (let i = 0; i < 4; i++) {
            edge[i] += arr[u];
            if (edge[i] <= parseInt(tot / 4) && dfs(u + 1)) return true;
            edge[i] -= arr[u];
        }
        return false;
    }
    arr.sort((a, b) => b - a);
    return dfs(0);
};