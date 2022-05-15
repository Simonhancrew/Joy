var distinctSubseqII = function (s) {
    let [MOD, n] = [1e9 + 7, s.length];
    let f = new Array(n + 1).fill(0).map(() => new Array(26).fill(0));
    for (let i = 0; i < n; i++) {
        t = s[i].charCodeAt() - 'a'.charCodeAt();
        f[i + 1][t] = 1;
        for (let j = 0; j < 26; j++) {
            f[i + 1][t] = (f[i + 1][t] + f[i][j]) % MOD;
            if (t != j) {
                f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD;
            }
        }
    }
    let res = 0;
    for (const x of f[n]) res = (res + x) % MOD;
    return res;
};