/**
 * @param {number} n
 * @return {number}
 */
 var getMoneyAmount = function(n) {
    let f = new Array(n + 2).fill(0).map(() => new Array(n + 2).fill(0));
    for(let len = 2;len <= n;len++){
        for(let l = 1;l + len - 1 <= n;l++){
            let r = l + len - 1;
            f[l][r] = 1e9
            for(let k = l;k <= r;k++){
                f[l][r] = Math.min(f[l][r],Math.max(f[l][k - 1],f[k + 1][r]) + k);
            }
        }
    }
    return f[1][n];
};