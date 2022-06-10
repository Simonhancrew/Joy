var countPalindromicSubsequences = function (s) {
    const n = s.length, P = parseInt(1e9) + 7;
    let f = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(1));
    for (let i = 1; i <= n; i++) f[i][i] += 1;
    for (let len = 2; len <= n; len++) {
        let q = new Array(4).fill(0).map(() => new Array());
        for (let j = 1; j <= n; j++) {
            q[s[j - 1].charCodeAt() - 'a'.charCodeAt()].push(j);
            let i = j - len + 1;
            if (i >= 1) {
                for (let k = 0; k < 4; k++) {
                    while (q[k].length && q[k][0] < i) q[k].shift();
                    if (q[k].length) {
                        f[i][j]++;
                        let [l, r] = [q[k][0], q[k][q[k].length - 1]];
                        if (l < r) {
                            f[i][j] = (f[i][j] + f[l + 1][r - 1]) % P;
                        }
                    }
                }
            }
        }
    }
    return (f[1][n] - 1 + P) % P;
};