var canIWin = function (maxChoosableInteger, desiredTotal) {
    let [n, m] = [maxChoosableInteger, desiredTotal];
    let f = new Array(1 << n).fill(-1);
    if (Math.floor(n * (n + 1) / 2) < m) return false;
    let dp = function (x) {
        if (f[x] != -1) return f[x];
        let sum = 0;
        for (let i = 0; i < n; i++) {
            if ((x >> i) & 1) sum += i + 1;
        }
        for (let i = 0; i < n; i++) {
            if ((x >> i) & 1) continue;
            if (sum + i + 1 >= m) return f[x] = 1;
            if (!dp(x + (1 << i))) return f[x] = 1;
        }
        return f[x] = 0;
    }
    return dp(0);
};