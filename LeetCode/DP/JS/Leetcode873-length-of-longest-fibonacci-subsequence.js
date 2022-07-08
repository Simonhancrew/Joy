var lenLongestFibSubseq = function (arr) {
    let [n, res, mp] = [arr.length, 0, new Map()];
    let f = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        mp.set(arr[i], i);
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            const x = arr[i] - arr[j];
            f[i][j] = 2;
            if (x < arr[j] && mp.has(x)) {
                const k = mp.get(x);
                f[i][j] = Math.max(f[i][j], f[j][k] + 1);
            }
            res = Math.max(res, f[i][j]);
        }
    }
    if (res < 3) return 0;
    return res;
};