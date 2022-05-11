var minDeletionSize = function (strs) {
    let [m, n, res] = [strs[0].length, strs.length, 0];
    for (let j = 0; j < m; j++) {
        for (let i = 1; i < n; i++) {
            if (strs[i - 1][j] > strs[i][j]) {
                res++;
                break;
            }
        }
    }
    return res;
};