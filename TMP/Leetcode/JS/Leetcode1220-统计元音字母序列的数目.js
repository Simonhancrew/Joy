var countVowelPermutation = function(n) {
    const P = 1e9 + 7;
    const f = new Array(n + 1).fill(0).map(()=>new Array(5).fill(0));
    for(let i = 0;i < 5;i++) f[1][i] = 1;
    for(let i = 2;i <= n;i++) {
        f[i][0] = f[i - 1][1];
        f[i][1] = f[i - 1][0] + f[i - 1][2];
        f[i][2] = f[i - 1][0] + f[i - 1][1] + f[i - 1][3] + f[i - 1][4];
        f[i][3] = f[i - 1][2] + f[i - 1][4];
        f[i][4] = f[i - 1][0];
        for(let j = 0;j < 5;j++) f[i][j] %= P;
    }
    let ans = 0;
    for(let i = 0;i < 5;i++) ans += f[n][i];
    return ans % P;
};