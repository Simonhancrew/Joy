/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
 var kInversePairs = function(n, k) {
    let f = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    f[1][0] = 1;
    let mod = 1e9 + 7;
    for(let i = 2;i <= n;i++){
        let s = 0;
        for(let j = 0;j <= k;j++){
            s += f[i - 1][j];
            if(j - i >= 0) s -= f[i - 1][j - i];
            f[i][j] = s % mod;
        }
    }
    return f[n][k];
};